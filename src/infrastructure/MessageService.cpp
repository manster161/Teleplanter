#include "Arduino.h"
#include "MessageService.h"
#include <SoftwareSerial.h>
#include "../core/Constants.h"
namespace Infrastructure {
    unsigned long _channelNumber = 0;
    String ssid = "Mansternet";
    String password = "snoppsnopp666";
    SoftwareSerial esp(Pins::DATA_TX,Pins::DATA_RX);
    String data;
    String server;
    String uri;
    char host[] = "api.thingspeak.com";
    String APIKey = "9NSN7TRBNSNUCYK4";
    const char OK[]  = "OK";
     MessageService::MessageService(){

     };
     MessageService::~MessageService(){};

     void printData(String data){
       esp.println(data);
       Serial.println(data);
     }


     bool MessageService::httpPost(int temp, int humidity, int moisture){
       char buffer[1024];
       char dataBuffer[100];
       int n = sprintf(dataBuffer, "t=%d&h=%d&m=%d", temp, humidity, moisture);

       sprintf(buffer, "POST /update HTTP/1.0\r\nHost: %s\r\nAccept: */*\r\nContent-Length: %d\r\nContent-Type: application/x-www-form-urlencoded\r\n\r\n%s",
       host,
       n,
       dataBuffer);

       printData(buffer);


       return true;
     }

          bool MessageService::reset(){
            esp.println("AT+RST");

            delay(1000);

            
           return (esp.find((char*)OK));


         }

     bool MessageService::connectWiFi(){
       String cmd = "AT+CWJAP=\"" +ssid+"\",\"" + password + "\"";

       printData(cmd);
       delay(4000);

        return (esp.find((char*)OK));
     }


     bool MessageService::init(){
        esp.begin(115200);
        Serial.begin(115200);

        return true;
        //return (esp.find((char*)OK));
     }

     int MessageService::post(float humidity, float temp, float moisture){

       return 0;
    }

};
