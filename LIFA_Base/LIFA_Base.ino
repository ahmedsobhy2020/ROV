

/*********************************************************************************
 **
 **  LVFA_Firmware - Provides Basic Arduino Sketch For Interfacing With LabVIEW.
 **
 **  Written By:    Sam Kristoff - National Instruments
 **  Written On:    November 2010
 **  Last Updated:  Dec 2011 - Kevin Fort - National Instruments
 **
 **  This File May Be Modified And Re-Distributed Freely. Original File Content
 **  Written By Sam Kristoff And Available At www.ni.com/arduino.
 
 *********************************************************************************/


/*********************************************************************************
 **
 ** Includes.
 **
 ********************************************************************************/
// Standard includes.  These should always be included.
#include <Wire.h>
#include <SPI.h>
#include <Servo.h>
#include "LabVIEWInterface.h" 
// Matt's inclusion: add server ability
#include <Ethernet.h>
EthernetServer server(87);
byte mac[] = { 
  0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x00 };
IPAddress ip(192,168,1,10);
int led = 9;



/*********************************************************************************
 **  setup()
 **
 **  Initialize the Arduino and setup serial communication.
 **
 **  Input:  None
 **  Output: None
 *********************************************************************************/
void setup()
{  


  // Place your custom setup code here: Starts Server
  Ethernet.begin(mac, ip);  
  server.begin();
  

  // Initialize Serial Port With The Default Baud Rate
  syncLV();
}


/*********************************************************************************
 **  loop()
 **
 **  The main loop.  This loop runs continuously on the Arduino.  It 
 **  receives and processes serial commands from LabVIEW.
 **
 **  Input:  None
 **  Output: None
 *********************************************************************************/

// set up Ethernet Connection

EthernetClient client;


void loop()
{   
  // Checks to see if there is a client and if it is ready to send data
  client = server.available();
  if(client)
  {

    while (client.connected()) 
    {
      while (client.available()) 
      { 
        // Checks if data is a command and if so, executes it
        checkForCommand();

        if(acqMode==1)
        {
          sampleContinously(); 
        }
      }
    } 
  }
  client.stop();
}















