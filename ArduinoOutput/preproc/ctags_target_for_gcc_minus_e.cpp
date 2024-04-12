# 1 "/home/kevson/Desktop/www/github/area-50/arduino/arduino.ino"
# 2 "/home/kevson/Desktop/www/github/area-50/arduino/arduino.ino" 2
// #include <LiquidCrystal_I2C.h>
# 4 "/home/kevson/Desktop/www/github/area-50/arduino/arduino.ino" 2
# 5 "/home/kevson/Desktop/www/github/area-50/arduino/arduino.ino" 2





DHT dht(15, DHT11);
Sensor sensor(dht);

LiquidCrystal_I2C lcd(0x27, 16, 2);

Led lowTemperatureAlert = Led(16);
Led normalTemperatureAlert = Led(4);
Led highTemperatureAlert = Led(2);

Led lowHumidityAlert = Led(23);
Led normalHumidityAlert = Led(22);
Led highHumidityAlert = Led(21);

void setup()
{
  Serial.begin(115200);
  dht.begin();
  // lcd.begin();
  // lcd.backlight();
  // lcd.setCursor(0, 1);
  // lcd.print("Hello, world!");
  highHumidityAlert.begin();
  normalHumidityAlert.begin();
  lowHumidityAlert.begin();
  highTemperatureAlert.begin();
  normalTemperatureAlert.begin();
  lowTemperatureAlert.begin();
  // lcd.print("Hello, World!");
}

void loop()
{
  delay(1000);
  sensor.setHumidity();
  sensor.setTemperature();

  if (sensor.isHighHumidity()) {
    Serial.print(sensor.getHumidity());
    Serial.print(" % ");
    Serial.println("|| Humidade Alta");
    highHumidityAlert.lightUp();
  } else {
    highHumidityAlert.turnOff();
  }

  if (sensor.isNormalHumidity()) {
    Serial.print(sensor.getHumidity());
    Serial.print(" % ");
    Serial.println("|| Humidade Normal");
    normalHumidityAlert.lightUp();
  } else {
    normalHumidityAlert.turnOff();
  }

  if (sensor.isLowHumidity()) {
    Serial.print(sensor.getHumidity());
    Serial.print(" % ");
    Serial.println("|| Humidade Baixa");
    lowHumidityAlert.lightUp();
  } else {
    lowHumidityAlert.turnOff();
  }

  if (sensor.isHighTemperature()) {
    highTemperatureAlert.lightUp();

    Serial.print(sensor.getTemperature());
    Serial.print("°C ");
    Serial.println("|| Temperatura Alta");
  } else {
    highTemperatureAlert.turnOff();
  }

  if (sensor.isNormalTemperature()) {
    normalTemperatureAlert.lightUp();

    Serial.print(sensor.getTemperature());
    Serial.print(((reinterpret_cast<const __FlashStringHelper *>(("°C ")))));
    Serial.println("|| Temperatura Normal");
  } else {
    normalTemperatureAlert.turnOff();
  }

  if (sensor.isLowTemperature()) {
    lowTemperatureAlert.lightUp();

    Serial.print(sensor.getTemperature());
    Serial.print("°C ");
    Serial.println("|| Temperatura Baixa");
  } else {
    lowTemperatureAlert.turnOff();
  }
}
