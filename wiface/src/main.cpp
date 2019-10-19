#include <Arduino.h>
#include <WIFI.h>
#include <HTTPClient.h>
#include "ArduinoJson.h"

const char* ssid = "Tec-Visitantes";
const char* password = "";
bool permiso=true;

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
void setup() {
  
  // put your setup code here, to run once:
Serial.begin(115200);
WiFi.begin(ssid, password);

while(WiFi.status()!=WL_CONNECTED)
{
  delay(1000);
  Serial.println("conectando a la red");
}
Serial.println("conectado a la red wifi ");
}

void loop() {
if(permiso){
if(WiFi.status()==WL_CONNECTED){
String cadena="Semana1:1";
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
    root["id"]= "23670212";

      //int a = root.printTo(Serial);
      String postMessage;
 
    root.printTo(postMessage);
  HTTPClient http;
  http.begin("http://192.168.137.199:8080/consultar");//destino for http request
  http.addHeader("Content-type","application/json");
     //23670212
  int httpResponseCode = http.POST(postMessage);

  if(httpResponseCode>0)
  {
    String response = http.getString();

    Serial1.println(httpResponseCode);
   // Serial.print(response);
   //String part01 = getValue(response,':',2);
   //Serial.println(part01);
    
  }else
  {
    Serial.println("Error Al enviar Post");
    Serial.println(httpResponseCode);
  }
   http.end();

}else
{
   Serial.println("Error Al conectar");
}
}
}
