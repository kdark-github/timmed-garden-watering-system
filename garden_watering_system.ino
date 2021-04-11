
#include <DS3231.h>
#include <Wire.h>

DS3231 clock;

#define motor 2

bool century = false;
bool h12Flag;
bool pmFlag = true;
String string;
int hr, sec, mi;



void setup() {

  Serial.begin(57600);
  Wire.begin();
  pinMode(motor, OUTPUT);

}

void loop() {

  hr = clock.getHour(h12Flag, pmFlag);
  mi = clock.getMinute();
  sec = clock.getSecond();

  string = (String) hr + ":" + (String) mi + ":" + (String) sec;

  Serial.println("current time is: ");
  Serial.println(string);

  Serial.println("current hr is: ");
  Serial.println(hr);


  Serial.println("current min is: ");
  Serial.println(mi);

  Serial.println("current sec is: ");
  Serial.println(sec);

  Serial.println("------------------------------------------------------------------------------------------------------");



  if ((hr == 17 || hr == 12) && sec <= 10 && sec >= 1 && mi == 55 ) {
    digitalWrite(motor, HIGH);
  }
  else
  {
    digitalWrite(motor, LOW);
  }

  delay(1000);


}
