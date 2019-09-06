#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <TelloDrone.h>


TelloDrone drone;


void setup(){
  // Initilize hardware serial:
  Serial.begin(9600);
  drone.connect("tello2", "");
}


void loop(){
  //only send data when drone is connected to wifi
  if(drone.connected)
  {

    Serial.println("command");
    drone.sendCommand("command");


    Serial.println("takeoff");
    drone.sendCommand("takeoff");  
    
    Serial.println("land");
    drone.sendCommand("land");   
  }
  
  //Wait for 5 second
  delay(5000);
  
  }