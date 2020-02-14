#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] =  "";

void setup()
{
  // Debug console
  Serial.begin(115200);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(0, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(12, OUTPUT);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}
boolean status = false;
void loop()
{
  
  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(0, LOW);
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    status = false;
    delay(500);
    Serial.print(".");
    
  }else{
    digitalWrite(5, HIGH);
    status = true;
    
   }

   if (status){
      Blynk.run();
   }
  
   Serial.print("Ok conected");
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
