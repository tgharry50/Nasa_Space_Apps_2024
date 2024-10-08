![image](https://github.com/user-attachments/assets/7b86bd9d-79ee-497a-aafa-9692fe817ccb)

IoT-Based Distributed Farming data gathering system Using LoRa and ESP32

Attention!!!! the entire project was implemented in the Hackathon "2024 NASA Space Apps Challenge" in Stalowa Wola in the span of 24h

This innovative IoT system manages a network of distributed sensors in outdoor and remote environments, utilizing LoRa technology for long-range communication. Each sensor functions as an HTTP-to-LoRa gateway, enabling seamless data transfer between the web interface and the LoRa network. 

The server-side application is split into two parts. The front-end is developed using Vue.js with Vuetify, providing a responsive and modern UI. The back-end is built in Python and R, which communicates with a SQLite database. This architecture ensures that all data, is efficiently processed and stored in a secure and scalable manner. Communication between the server and devices is handled via HTTP and JSON files, with the server-side application written in C# and the client-side built using JavaScript and Vue.js.

The embedded software for the sensors has been developed in C using the ESP-IDF framework. The application is designed to run in a multi-threaded environment, with the HTTP communication and LoRa protocol handled on separate cores of the ESP32, ensuring efficient parallel processing. 

Original repos of embedded and backend project posted below (if you want to see the history of project development from scratch):

Backend:
https://github.com/bafaurazan/AGRUP_NASA/tree/init

Embedded:
https://github.com/majorBien/nasa-sapce-apps-farming-fusion-transmiter-station
https://github.com/majorBien/nasa-space-apps-challenge-concentraotr
