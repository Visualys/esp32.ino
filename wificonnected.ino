#include <WiFi.h>
#define LED 2

uint8_t wificonnected = 0;

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
    }
  }
