/*
Author: Akshay Kotish
Publisher: Akshay Kotish & Co.
Purpose: To make wifi communication easy.
Produced on: 2020
Date of Release: 06-09-2020
Language: C++
Made For: Fasten Robotics Private Limited
*/


#ifndef Communication_h
#define Communication_h
#include"Arduino.h"
#include <SPI.h>
#include <WiFi.h>
class Communication{

private:
    String SSID = "";
    String Password = "";

    IPAddress IP;
    int Acknowledge_ID = 0;
    
    char* toArray(String e)
    {
        char *value = new char[e.length()];
        for(int i=0; i<e.length(); i++)
        {
            value[i] = e[i];
        }
        return value;
    }
	WiFiClient client;
    
    

public:

    int Install(String SSID_t, String Password_t);
    int IsConnect();
    String Get_My_IP();
    int Connect();
    int Disconnect();
    String Read();
    int Write(String data);
    int Feedback();
};
#endif
