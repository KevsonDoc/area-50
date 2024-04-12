# Use a imagem oficial do Mosquitto
FROM eclipse-mosquitto:latest

COPY mosquitto.conf /mosquitto/config/mosquitto.conf
CMD ["mosquitto", "-c", "/mosquitto/config/mosquitto.conf"]