# ESP32-TelloDrone

A class to communicate with a Tello Drone.

Read the SDK for further information about what commmands you can send to the drone
- [Tello SDK 1.3 for the white Tello Drones](https://terra-1-g.djicdn.com/2d4dce68897a46b19fc717f3576b7c6a/Tello%20%E7%BC%96%E7%A8%8B%E7%9B%B8%E5%85%B3/For%20Tello/Tello%20SDK%20Documentation%20EN_1.3_1122.pdf)
- [Tello SDK 2.0 for the black EDU version](https://dl-cdn.ryzerobotics.com/downloads/Tello/Tello%20SDK%202.0%20User%20Guide.pdf)


```c++
// create instance of the class
TelloDrone drone;

// connect to wifi - paramters are 'ssid' and 'password'
drone.connect("tello2", "");

// send a command to the drone
sendCommand("command");
sendCommand("battery?");
``` 
