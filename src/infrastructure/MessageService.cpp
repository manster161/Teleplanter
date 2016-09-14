#include "MessageService.h"
#include <Ethernet.h>
#include <ESP8266wifi.h>
namespace Infrastructure {

    unsigned long _channelNumber = 0;

    EthernetClient _client;

     MessageService::MessageService(long channelNumber, char* writeApiKey){
       _channelNumber = channelNumber;
     };
     MessageService::~MessageService(){};

     int MessageService::post(char * message){
       return 0;
     }

     int MessageService::post(float values[]){

       return (int)values[0];
     }

};
