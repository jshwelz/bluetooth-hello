/*
 * Copyright (c) 2016 Intel Corporation.  All rights reserved.
 * See the bottom of this file for the license terms.
 */

#include <CurieBLE.h>

//Pins for DO
const int ledPinDo1 = 10; // 
const int ledPinDo2 = 6; // 
const int ledPinDo3 = 3; // 


//Pins for REmenor
const int ledPinRe1 = 4; // 
const int ledPinRe2 = 7; // 
const int ledPinRe3 = A0; // 


//Pins for Mimenor
const int ledPinMi1 = 5; // 
const int ledPinMi2 = 6; // 


//Pins for FA
const int ledPinFa1 = 0; // 
const int ledPinFa2 = 1; // 
const int ledPinFa3 = 2; // 
const int ledPinFa4 = 3; // 
const int ledPinFa5 = 4; // 
const int ledPinFa6 = 7; // 
const int ledPinFa7 = 10; // 
const int ledPinFa8 = 11; // 



//Pins for SOL
const int ledPinSol1 = 6; // 
const int ledPinSol2 = A0; // 
const int ledPinSol3 = A1; // 



//Pins for LaMenor
const int ledPinLa1 = 3; // 
const int ledPinLa2 = 6; // 
const int ledPinLa3 = 7; // 

//Pins for SI7
const int ledPinSi1 = 5; // 
const int ledPinSi2 = 1; // 
const int ledPinSi3 = 9; // 
const int ledPinSi4 = 7; // 


const int buttonPin = 4; // 

BLEPeripheral blePeripheral; // create peripheral instance
BLEService ledService("19B10010-E8F2-537E-4F6C-D104768A1214"); // create service


// create switch characteristic and allow remote device to read and write
BLECharCharacteristic ledCharacteristic("19B10011-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);
// create button characteristic and allow remote device to get notifications
BLECharCharacteristic buttonCharacteristic("19B10012-E8F2-537E-4F6C-D104768A1214", BLERead | BLENotify); // allows remote device to get notifications

void setup() {
  Serial.begin(9600);
  pinMode(ledPinDo1, OUTPUT); // 
  pinMode(ledPinDo2, OUTPUT); // 
  pinMode(ledPinDo3, OUTPUT); // 

  pinMode(ledPinRe1, OUTPUT); // 
  pinMode(ledPinRe2, OUTPUT); // 
  pinMode(ledPinRe3, OUTPUT); // 



  pinMode(ledPinMi1, OUTPUT); // 
  pinMode(ledPinMi2, OUTPUT); // 
  


  pinMode(ledPinFa1, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinFa2, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinFa3, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinFa4, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinFa5, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinFa6, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinFa7, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinFa8, OUTPUT); // use the LED on pin 13 as an output
  


  pinMode(ledPinSol1, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinSol2, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinSol3, OUTPUT); // use the LED on pin 13 as an output
  

  pinMode(ledPinLa1, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinLa2, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinLa3, OUTPUT); // use the LED on pin 13 as an output


  pinMode(ledPinSi1, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinSi2, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinSi3, OUTPUT); // use the LED on pin 13 as an output
  pinMode(ledPinSi4, OUTPUT); // use the LED on pin 13 as an output

  pinMode(buttonPin, INPUT); // use button pin 4 as an input

  // set the local name peripheral advertises
  blePeripheral.setLocalName("ButtonLED");
  // set the UUID for the service this peripheral advertises:
  blePeripheral.setAdvertisedServiceUuid(ledService.uuid());

  // add service and characteristics
  blePeripheral.addAttribute(ledService);
  blePeripheral.addAttribute(ledCharacteristic);
  blePeripheral.addAttribute(buttonCharacteristic);

  ledCharacteristic.setValue(0);
  buttonCharacteristic.setValue(0);

  // advertise the service
  blePeripheral.begin();

  Serial.println("Bluetooth device active, waiting for connections...");
}

void loop() {
  // poll peripheral
  blePeripheral.poll();

     
  if (ledCharacteristic.written() ) {
    switch (ledCharacteristic.value()) {
    case 1:
      //DO
      turnOffLeds();
      digitalWrite(ledPinDo1, HIGH);
      digitalWrite(ledPinDo2, HIGH);
      digitalWrite(ledPinDo3, HIGH);     
      break;
    case 2:
      //RE
      turnOffLeds();
      digitalWrite(ledPinRe1, HIGH);
      digitalWrite(ledPinRe2, HIGH);
      analogWrite(ledPinRe3, 255);                
      break;
    case 3:
      //MI
      turnOffLeds();
      digitalWrite(ledPinMi1, HIGH);
      digitalWrite(ledPinMi2, HIGH);               
      break;
    case 4:
      //FA
      turnOffLeds();
      digitalWrite(ledPinFa1, HIGH);
      digitalWrite(ledPinFa2, HIGH);
      digitalWrite(ledPinFa3, HIGH);
      digitalWrite(ledPinFa4, HIGH);
      digitalWrite(ledPinFa5, HIGH);
      digitalWrite(ledPinFa6, HIGH);
      digitalWrite(ledPinFa7, HIGH);
      digitalWrite(ledPinFa8, HIGH);
                 
      break;
    case 5:
      //SOL
      turnOffLeds();
      digitalWrite(ledPinSol1, HIGH);
      digitalWrite(ledPinSol2, HIGH);
      analogWrite(ledPinSol3, 255);                
      
      break;
    case 6:
      //LA
      turnOffLeds();
      digitalWrite(ledPinLa1, HIGH);
      digitalWrite(ledPinLa2, HIGH);
      digitalWrite(ledPinLa3, HIGH);      
      break;
    case 7:
      //SI
      turnOffLeds();
      digitalWrite(ledPinSi1, HIGH);
      digitalWrite(ledPinSi2, HIGH);
      digitalWrite(ledPinSi3, HIGH);
      digitalWrite(ledPinSi4, HIGH);
                    
      break;

    default: 
      // if nothing else matches, do the default
      // default is optional
    break;
    }
      
  }  
}

void turnOffLeds()
{


 analogWrite(ledPinRe3, 0); 
 analogWrite(ledPinSol3, 0); 
   
  for (int i=0;i<=13;i++)
  {
      digitalWrite(i, LOW);              
  }

  for (int i=0;i<=5;i++)
  {
      analogWrite(i, 0);              
  }
      
}

/*
  Copyright (c) 2016 Intel Corporation. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-
  1301 USA
*/
