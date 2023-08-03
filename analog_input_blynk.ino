#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = ""; // Enter your Auth Token 

char ssid[] = ""; // Enter your WIFI name
char pass[] = ""; // Enter your WIFI password

int sensor =A0;


void sensor_status()
{
  int value = map(analogRead(sensor),10,1024,0,200);
  Blynk.virtualWrite(V0,value);
   }

void setup() {
  Serial.begin(115200); 

   pinMode(sensor, INPUT); // Sensor pin define

  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); 

}

void loop() {
  //Run the Blynk library
  sensor_status(); //Run the function
  Blynk.run();
 
}
