// NodeMcu Receiver NODE01 

#include <stdio.h>
#include <SoftwareSerial.h>
#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>
SoftwareSerial ArduinoUno(3,2); // (Rx,Tx)
RF24 radio(7,8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
int this_node = 01; // Address of our node in Octal format ( 04,031, etc)
char address;  

void setup() 
{
  Serial.begin(9600);
  ArduinoUno.begin(4800);
  SPI.begin();
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
}
void loop() 
{
  network.update();
  while ( network.available() )  // Is there any incoming data?
  {    
    RF24NetworkHeader header5;
    network.read(header5, &address, sizeof(address)); // Read the incoming data
    Serial.println(address);
    Serial.println("Fire Detected");
    int a=address;
    ArduinoUno.println(a);
  }
}
