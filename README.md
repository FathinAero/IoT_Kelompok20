# ForecastBuddy

ForecastBuddy is a weather and environmental monitoring project designed to provide users with accurate and easy-to-understand data. The project uses an ESP32 microcontroller and a DHT11 sensor to measure temperature and humidity.

The key features of ForecastBuddy include:

* Real-Time Monitoring: It collects real-time weather data using the DHT11 sensor.
* Data Comparison: The system compares the data collected by the DHT11 sensor with official data from BMKG.
* Weather Forecasts: Based on the comparison, it provides users with a weather forecast derived from both data sources.

## Hardware Design and implementation details
The hardware design for the ForecastBuddy system includes several key components that work together to collect and display real-time weather data. At the core of the system is the ESP32, a powerful microcontroller that acts as the central processing unit (CPU). The ESP32 is responsible for managing the communication between the various components, including the DHT11 sensor and the BMKG API. The DHT11 sensor, known for its high accuracy, is used to measure the local temperature and humidity. The sensor communicates with the ESP32 via a digital pin (GPIO4), while also receiving power from the 5V pin.

![image](https://github.com/user-attachments/assets/7fce5c60-e801-4f0f-8ea5-beb33c35432a)



## Software implementation details

The software development for the ForecastBuddy project involves programming the ESP32 to interact with the DHT11 sensor, retrieve weather data from the BMKG API, and display the results using the Blynk platform. All the necessary programming is written in a single .ino file, with the integration of various libraries for each component.

Flowchart:

![image](https://github.com/user-attachments/assets/a539b3a9-25f7-4eff-9e0d-3d5d4a882a1a)

ForecastBuddy project involves programming the ESP32 to interface with the DHT11 sensor, retrieve weather data from the BMKG API, and display the results through the Blynk platform. Initially, the ESP32 attempts to connect to a Wi-Fi network. If the connection is successful, it proceeds to access the BMKG API to retrieve weather data such as temperature, humidity, and weather conditions. If there’s an issue with the connection or the API request, the system will retry until a successful response is received. Once the weather data is fetched, the program reads the local temperature and humidity from the DHT11 sensor. The data from the DHT11 sensor is then compared with the data obtained from the BMKG API, verifying the consistency and accuracy of both data sources.The final results, including temperature, humidity, and weather conditions, are displayed on the Blynk app in real time, allowing users to easily monitor the weather.

## Test Result and Performance Evaluation

Testing Result
The results from the testing phase of the ForecastBuddy project align with the expectations and predefined criteria, confirming that the system functions as intended. Throughout the testing process, both the hardware and software components were thoroughly evaluated to ensure smooth integration and optimal performance, particularly in how the ESP32 interacts with the BMKG API, the DHT11 sensor, and the Blynk platform.

![image](https://github.com/user-attachments/assets/1aa5a839-5a37-4452-8d16-bdee4204418d)

![image](https://github.com/user-attachments/assets/e00211c4-13bb-455d-aed3-d4d2dfe8e77e)


The ForecastBuddy project was evaluated based on its ability to meet the established objectives and functionality criteria. The system successfully integrates the ESP32 microcontroller, the DHT11 sensor, the BMKG weather API, and the Blynk platform to provide real-time weather monitoring and analysis.
During the evaluation phase, the system’s performance was found to be reliable and accurate. The data retrieved from the DHT11 sensor and the BMKG API were consistently synchronized, with clear and accurate readings displayed via the Blynk app. The integration with Blynk allowed users to easily access the weather data from their mobile devices, ensuring a smooth user experience. The system also performed well in terms of response time and reliability, with minimal lag when retrieving data and displaying it on the Blynk platform.

## User Manual
* Prepare the Circuit and Turn On the ESP32
* Connect the mobile device to Wi-Fi and open the Blynk app.
* The data can now be monitored from the mobile device in real-time.


## Conclusion and future work
The ForecastBuddy project successfully met its objective of providing real-time weather and environmental monitoring by integrating the DHT11 sensor, the BMKG weather API, and the Blynk platform. The combination of these components enabled the system to measure local temperature and humidity through the DHT11 sensor while comparing the data with weather forecast fetched from the BMKG API. The use of Blynk provided an intuitive, mobile-friendly interface for users to monitor these data in real-time.
However, there are still opportunities for further enhancement. Future iterations could involve adding additional sensors for more comprehensive environmental monitoring or improving the system’s power efficiency for extended use in remote locations. Additionally, integrating more detailed weather parameters from the BMKG API, such as wind speed and pressure, could enhance the system’s forecasting capabilities.


## Contributor

* Muhammad Billie Elian       (2206059446)
* Fathin Umara Aero           (2206814186)
* Adhelia Putri Maylani       (2206814816)
* Muhammad Rifki Pratama      (2206828903)


