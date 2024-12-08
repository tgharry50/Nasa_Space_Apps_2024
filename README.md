![image](https://github.com/user-attachments/assets/7b86bd9d-79ee-497a-aafa-9692fe817ccb)

IoT-Based Distributed Farming data gathering system Using LoRa and ESP32

Attention!!!! the entire project was implemented in the Hackathon "2024 NASA Space Apps Challenge" in Stalowa Wola in the span of 24h

This innovative IoT system manages a network of distributed sensors in outdoor and remote environments, utilizing LoRa technology for long-range communication. Each sensor functions as an HTTP-to-LoRa gateway, enabling seamless data transfer between the web interface and the LoRa network. 

Our project aims to revolutionize agriculture by addressing the critical challenge of limited data access 
that hinders farmers from optimizing their crop yields and because of that we are developing an innovative solution 
that leverages cutting-edge technology that unlocks the full potential of agricultural fields.

We aim to provide farmers an access to the most comprehensive and expansive agricultural knowledge database,
allowing farmers to take control of their operations and allowing them to make informed decisions,
while also providing them  with a real-time data, which is actionable from their fields, 
allowing them to manage their resources efficiently and create targeted interventions, 
boosting their crop yield up to 20%, significantly improving their farm productivity and profitability
at the cost of flexible,  subscription based model, allowing all farmers an easy access to it.

The server-side application is split into two parts. The front-end is developed using Vue.js with Vuetify, providing a responsive and modern UI. The back-end is built in Python and R, which communicates with a SQLite database. This architecture ensures that all data, is efficiently processed and stored in a secure and scalable manner. Communication between the server and devices is handled via HTTP and JSON files, with the server-side application written in C# and the client-side built using JavaScript and Vue.js.

The embedded software for the sensors has been developed in C using the ESP-IDF framework. The application is designed to run in a multi-threaded environment, with the HTTP communication and LoRa protocol handled on separate cores of the ESP32, ensuring efficient parallel processing. 

Original repos of embedded and backend project posted below (if you want to see the history of project development from scratch):

Backend:
https://github.com/bafaurazan/AGRUP_NASA/tree/init

Embedded:
https://github.com/majorBien/nasa-sapce-apps-farming-fusion-transmiter-station

https://github.com/majorBien/nasa-space-apps-challenge-concentraotr



![image](https://github.com/user-attachments/assets/91b64354-bf4f-4d43-b90d-fc6df23a2d31)

![image](https://github.com/user-attachments/assets/df334dd3-0b6d-4991-85cc-1d42d596febf)

![image](https://github.com/user-attachments/assets/e023d980-837e-4712-8246-5fbae6bec6a8)


