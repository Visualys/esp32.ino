#include <WiFi.h>
#include <HTTPClient.h>
#define LED 2

uint8_t wificonnected = 0;
String msg = "http://192.168.1.32:8080/dmx.db?cmd=mes&mes=65,essai";
HTTPClient request;

void WiFiEvent(WiFiEvent_t event){
  if(event==14) wificonnected = 0;
  if(event==16) {
    wificonnected = 1;
    Serial.println(WiFi.localIP());
    }
  }

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  WiFi.onEvent(WiFiEvent);

  WiFi.mode(WIFI_STA);
  WiFi.begin("ssid", "password");

}

void loop() {
  if(!wificonnected){
    digitalWrite(LED, HIGH);
    delay(150);
    digitalWrite(LED, LOW);
    delay(150);
    }else{
    request.begin(msg.c_str());
    request.GET();
    delay(60000);
    }
  }
