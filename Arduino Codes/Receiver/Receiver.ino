// Receiver NODE02 (B)

#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>
RF24 radio(7,8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
char this_node='B';
const uint16_t node02 = 02; // Address of our node in Octal format ( 04,031, etc)
char address;  

void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  network.begin(90, node02); //(channel, node address)
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
    delay(2000);
    /*RF24NetworkHeader header;
    unsigned long temp;
    unsigned long h;
    unsigned long smoke;
    network.read(header, &temp, sizeof(temp)); // Read the incoming data
    Serial.print("Temp : ");
    Serial.println(temp);
    delay(3000);
    network.read(header, &smoke, sizeof(smoke)); // Read the incoming data
    Serial.print("Smoke : ");
    Serial.println(smoke);
    delay(3000);
    network.read(header, &h, sizeof(h)); // Read the incoming data
    Serial.print("Humidity : ");
    Serial.println(h);
    delay(3000);*/
  }
}
