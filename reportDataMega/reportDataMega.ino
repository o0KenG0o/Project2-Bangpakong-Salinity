/* 
  Example for report random data to Magellan IoT Platform
  please use payload with json format e.g. {"Temperature":25.5,"Humidity":90.4,"Light":45}
  and {"Location":"13.001,100.44"} for plot the location on MAP
                    |        |
                latitude  longitude 

  and {"Lamp":0} or {"Lamp":1"} for show the Lamp status on dashboard
  
  Please login and enjoy with https://magellan.ais.co.th
  
  If you have any questions, please see more details at https://magellan.ais.co.th
  
         " Plug NB-IoT Shield on Arduino Mega "
    1. Jump Pin 8 (RX) NB to Pin 48 Mega 
    2. Jump Pin 9 (TX) NB to Pin 46 Mega 
*/

#include "Magellan_BC95.h"
Magellan_BC95 magel;

String payload;

void setup() 
{
  Serial.begin(115200);
  magel.begin();           //Init Magellan LIB
}

void loop() 
{
  /*
    Example report random temperature and humidity to Magellan IoT platform
  */
  String EC=String(random(0,100));
  
  payload="{\"EC\":"+EC+"}";  //Please provide payload with json format
  
  magel.report(payload);                                                  //Report random data to Magellan IoT platform
  delay(5000);                                                           //Delay 10 second
}
