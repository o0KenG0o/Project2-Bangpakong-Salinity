/*  
  Example for report random data to Magellan IoT Platform
  please use payload with json format e.g. {"Temperature":25.5,"Humidity":90.4,"Light":45}
  and {"Location":"13.001,100.44"} for plot the location on MAP
                    |        |
                latitude  longitude 

  and {"Lamp":0} or {"Lamp":1"} for show the Lamp status on dashboard
  
  Please login and enjoy with https://magellan.ais.co.th
  
  If you have any questions, please see more details at https://magellan.ais.co.th
*/
#include "Magellan_BC95_lite.h"
Magellan_BC95_lite magel;

String payload;

void setup() 
{
  Serial.begin(9600);
  magel.begin();           //Init Magellan LIB
}

void loop() 
{
  /*
    Example report random temperature and humidity to Magellan IoT platform
  */
  String temperature=String(random(0,100));
  String humidity=String(random(0,100));
  String dataTest=String(random(0,100));
  
  payload="{\"temperature\":"+temperature+",\"humidity\":"+humidity+",\"dataTest\":"+dataTest+"}";  //Please provide payload with json format
  
  magel.report(payload);                                                  //Report random data to Magellan IoT platform
  delay(5000);                                                            //Delay 5 second
}
