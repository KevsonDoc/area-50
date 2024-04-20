#line 1 "/home/kevson/Desktop/www/github/area-50/arduino/src/led/Led.cpp"
#include "Led.hpp"
#include "esp32-hal-gpio.h"

Led::Led(int pin)
{
  setPin(pin);
}

void Led::lightUp()
{
  this->status = ON;
  digitalWrite(this->pin, HIGH);
}

void Led::turnOff()
{
  this->status = OFF;
  digitalWrite(this->pin, LOW);
}

void Led::begin()
{
  pinMode(this->pin, OUTPUT);
}

int Led::getPin()
{
  return this->pin;
}

Status Led::getStatus()
{
  return this->status;
}

void Led::setPin(int pin)
{
  this->pin = pin;

  if (this->status = ON)
  {
    this->lightUp();
  }
  else
  {
    this->turnOff();
  }
}