# Fasten Private Limited
## Fasten For Wifi Communication
###### Powered By Akshay Kotish & Co.

**TCP server based wifi communication easy to use library developed for ESP32 or any other wifi modules.**

**This file consist of WiFi.h and SPI library supports from** ` Arduino ` **itself.** 


## How to use
You will find `Communication.h` library that can be added in our main program.

###### Create Communication class object like
```
Communication communication
```


###### To install Wifi
```
communication.Install([SSPI], [PASSWORD]);
```

###### To connect Clients
```
communication.Connect();
```

###### To Get Node[ESP Module] IP
```
communication.Get_My_IP();
```

###### To check available clients
```
communication.IsConnect();
```

###### To diconnect from current client
```
communication.Disconnect();
```

###### To read recieved data from client
```
communication.Read();
```

###### To write data for sending to client
```
communication.Write([Data]);
```

###### To Get Feedback
```
communication.Feedback();
```

Thanks to our team
```
Rachna Aggarwal @github/rachnaggarwal
Abhishek 
Animesh
Akshay Kotish @github/akshaykotish
```

###### Compiled Library Screenshot
![alt text](https://github.com/akshaykotish/[reponame]/blob/[branch]/image.jpg?raw=true)
