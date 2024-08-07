# area-50

Este projeto consiste em um sistema de coleta de temperatura e humidate de um servidor DHT11 acoplado a um ESP32.

## Tecnologias
 - ESP32
 - DHT11
 - Node.js
 - MongoDB
 - NestJS
 - Mongoose
 - Docker
 - Mosquito

## Funcionamento
Um sensor DHT11 acoplado ao ESP32 captura dados de temperatura e humidade enviando através do protocolo MQTT para um broken Eclipse Mosquitto.
Um serviço escrito em Node.js inscrito na fila do Eclipse Mosquitto ouve os dados e envia para um banco de dados em MongoDB.
