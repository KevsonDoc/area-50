#ifndef led_file
#define led_file

enum Status
{
  ON,
  OFF,
};

class Led
{

public:
  void setPin(int pin);
  void lightUp();
  void turnOff();
  void begin();
  int getPin();
  Status getStatus();
  Led(int pin);

private:
  int pin;
  Status status = OFF;
};

#endif