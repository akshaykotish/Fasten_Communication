/*
Author: Akshay Kotish
Publisher: Akshay Kotish & Co.
Purpose: To make wifi communication easy.
Produced on: 2020
Date of Release: 06-09-2020
Language: C++
Made For: Fasten Robotics Private Limited
*/

#include <SPI.h>
#include <WiFi.h>
#include"Arduino.h"
#include"Communication.h"

	WiFiServer server(80);
	int Communication::Install(String SSID_t, String Password_t)
    {
        SSID = SSID_t;
        Password = Password_t;

        //As we assigned values to variables we use Acknowledge_ID = 111 [1 = Function Index, 1 = Task Index, 1 = OKAY]
        Acknowledge_ID = 111;

        ;

        while(WiFi.status() != WL_CONNECTED)
        {
            delay(500);
            //As we checking status, we use Acknowledge_ID = 120 [1 = Function Index, 2 = Task Index, 0 = NOT OKAY]
        	Acknowledge_ID = 120;
        	return Acknowledge_ID;
        }
		
		int status = WL_IDLE_STATUS;
		while ( status != WL_CONNECTED) {    
		    status = WiFi.begin(toArray(SSID), toArray(Password));
			delay(10000);
		} 
        
		//Wifi is working now, we use Acknowledge_ID = 131 [1 = Function Index, 3 = Task Index, 1 = OKAY]
	    Acknowledge_ID = 131;
        IP = WiFi.localIP();
        return Acknowledge_ID;
    }
    
	int Communication::Connect()
	{
		server.begin();
		//TCP Server started, we use Acknowledge_ID = 211 [2 = Function Index, 1 = Task Index, 1 = OKAY]
	    Acknowledge_ID = 211;
        IP = WiFi.localIP();
    	return Acknowledge_ID;
	}
	
    int Communication::IsConnect()
	{
    	client = server.available();
    	//TCP Client Check, we use Acknowledge_ID = 311 [3 = Function Index, 1 = Task Index, 1 = OKAY]
        Acknowledge_ID = 211;
        if (client) {
		    if (client.connected()) {
		    	//TCP Client Connected started, we use Acknowledge_ID = 321 [3 = Function Index, 2 = Task Index, 1 = OKAY]
		      	Acknowledge_ID = 321;
	    	}
			else{
				//TCP Client Not Connected, we use Acknowledge_ID = 330 [3 = Function Index, 3 = Task Index, 0 = NOT OKAY]
	    		Acknowledge_ID = 330;
			}
	    }
	    else{
	    	//TCP Client Not Connected, we use Acknowledge_ID = 340 [3 = Function Index, 4 = Task Index, 0 = NOT OKAY]
	    	Acknowledge_ID = 340;
		}
		return Acknowledge_ID;	
	}
	
	String Communication::Get_My_IP()
	{
		//Returning IP
		return String(IP);
	}
	
	int Communication::Disconnect()
	{         
		client.stop();
		WiFi.disconnect();
		//Client & Wifi Both Stopped, we use Acknowledge_ID = 411 [4 = Function Index, 1 = Task Index, 1 = OKAY]
		Acknowledge_ID = 411;
		
    	return Acknowledge_ID;
	}
	
	String Communication::Read()
	{
		String data = "";
		while(client == true) 
		{
			char c = client.read();
			data = data + String(c);
    	}
    	//Data recieved sucessfully, we use Acknowledge_ID = 511 [5 = Function Index, 1 = Task Index, 1 = OKAY]
    	Acknowledge_ID = 511;
    	return data;
	}
	
	int Communication::Write(String data)
	{
		if(client == true)
		{
			server.write(toArray(data));
			//Data write sucessfully, we use Acknowledge_ID = 611 [6 = Function Index, 1 = Task Index, 1 = OKAY]
			Acknowledge_ID = 611;
		}
		else{
			//Data not write sucessfully, we use Acknowledge_ID = 610 [6 = Function Index, 1 = Task Index, 0 = NOT OKAY]
	    	Acknowledge_ID = 610;
		}
    	return Acknowledge_ID;
	}
	
	int Communication::Feedback()
	{
		//Returning Feedback
    	return Acknowledge_ID;
	}
