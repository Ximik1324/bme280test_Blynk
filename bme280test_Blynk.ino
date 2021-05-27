
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
char auth[] = "yTZwFufou0Ii9niYqdynfWqUjRRtZ98F";
 
/* WiFi credentials */
char ssid[] = "FASTWEB-B6EF73";
char pass[] = "MT9FP4Y4J2";
 
SimpleTimer timer;
 
 
 
#define ONE_WIRE_BUS 2 // DS18B20 on arduino pin2 corresponds to D4 on physical board "D4 pin on the ndoemcu Module"
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
float temp;
float Fahrenheit=0;
void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  DS18B20.begin();
  timer.setInterval(1000L, sendSensor);
}
 
void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}
 
/***************************************************
 * Send Sensor data to Blynk
 **************************************************/
