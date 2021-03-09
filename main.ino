#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "DHT.h"

#define DHT11_PIN 2 //PIN on Arduino/ESP which receives data from DHT
#define DHTTYPE DHT11
 
DHT dht(DHT11_PIN, DHT11);

const char* ssid = "WIFI_SSID";
const char* password = "WIFI_PASSWORD";

// username and password for HTTP Basic Authentication
const char* authUsername = "AUTHORIZATION_USERNAME";
const char* authPassword = "AUTHORIZATION_PASSWORD";



void setup () {

  WiFi.begin(ssid, password);
 
  Serial.begin(9600);

  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);
    Serial.println("Connecting...");
 
  }
 
}
 
void loop() {
 
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
 
  if (WiFi.status() == WL_CONNECTED) {
 
    HTTPClient http;

    http.begin("http://arduino.gaway.pl/api/measurement/");
    http.setAuthorization(authUsername,authPassword);
    http.addHeader("Content-Type", "application/json");
    int httpCode = http.POST("{\"temp\":" + String(temp) + ",\"humidity\":" + String(hum)+"}");


    // Printing HTTP response
    if (httpCode > 0) {
      Serial.println(httpCode);
      String result = http.getString();
      Serial.println(result);
    }
    
    http.end();
  }
  
  else{
    
    WiFi.begin(ssid, password);
  }

  delay(600000);
}
