
#define BLYNK_TEMPLATE_ID "TMPL6E9x-9iwy"
#define BLYNK_TEMPLATE_NAME "Finpro IoT"
#define BLYNK_AUTH_TOKEN "jEb7v-VC3Drvdwx2HaaIObHHQvauiixq"

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include <BlynkSimpleEsp32.h>

// Konfigurasi WiFi dan Blynk
const char *ssid = "RS Umum.";
const char *pass = "jalursamping";

// URL API BMKG
const char *api_url = "https://api.bmkg.go.id/publik/prakiraan-cuaca?adm4=32.76.06.1002";

// Konfigurasi DHT11
#define DHT_PIN 4
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

void setup()
{
    Serial.begin(115200);
    Serial.println("Memulai koneksi ke Wi-Fi...");

    WiFi.begin(ssid, pass);
    unsigned long startAttemptTime = millis();

    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000)
    {
        delay(500);
        Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("\nWiFi Connected!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    }
    else
    {
        Serial.println("\nGagal terhubung ke Wi-Fi. Periksa SSID atau password.");
    }

    dht.begin();
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
    Blynk.run();

    // Membaca data dari DHT
    float localTemp = dht.readTemperature();
    float localHumidity = dht.readHumidity();

    if (isnan(localTemp) || isnan(localHumidity))
    {
        Serial.println("Gagal membaca data dari sensor DHT!");
        return;
    }

    Serial.println("\nData dari sensor DHT:");
    Serial.printf("Suhu Lokal: %.1f°C\n", localTemp);
    Serial.printf("Kelembapan Lokal: %.1f%%\n", localHumidity);

    Blynk.virtualWrite(V0, localTemp);
    Blynk.virtualWrite(V1, localHumidity);

    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        Serial.println("\nMengakses API...");
        http.begin(api_url);

        int httpResponseCode = http.GET();
        if (httpResponseCode > 0)
        {
            String payload = http.getString();
            Serial.println("Respons API diterima, memproses data JSON...");

            StaticJsonDocument<5000> doc;
            DeserializationError error = deserializeJson(doc, payload);

            if (!error)
            {
                JsonArray cuaca_array = doc["data"][0]["cuaca"][0];
                JsonObject forecast = cuaca_array[1];

                int apiTemp = forecast["t"];
                int apiHumidity = forecast["hu"];
                const char *kondisi_cuaca = forecast["weather_desc"];

                Serial.println("\nData dari API BMKG:");
                Serial.printf("Suhu BMKG: %d°C\n", apiTemp);
                Serial.printf("Kelembapan BMKG: %d%%\n", apiHumidity);
                Serial.printf("Kondisi Cuaca: %s\n", kondisi_cuaca);

                Blynk.virtualWrite(V2, apiTemp);
                Blynk.virtualWrite(V3, apiHumidity);
                Blynk.virtualWrite(V4, kondisi_cuaca);

                // Membandingkan data
                float tempDiff = localTemp - apiTemp;
                float humidityDiff = localHumidity - apiHumidity;

                Serial.println("\nPerbandingan Data:");
                Serial.printf("Perbedaan Suhu: %.1f°C\n", tempDiff);
                Serial.printf("Perbedaan Kelembapan: %.1f%%\n", humidityDiff);

                Blynk.virtualWrite(V5, tempDiff);
                Blynk.virtualWrite(V6, humidityDiff);
            }
            else
            {
                Serial.print("Gagal mem-parsing JSON: ");
                Serial.println(error.c_str());
            }
        }
        else
        {
            Serial.print("Error dalam HTTP Request: ");
            Serial.println(httpResponseCode);
        }

        http.end();
    }
    else
    {
        Serial.println("WiFi terputus. Menghubungkan kembali...");
        WiFi.begin(ssid, pass);
    }

    delay(60000);
}
