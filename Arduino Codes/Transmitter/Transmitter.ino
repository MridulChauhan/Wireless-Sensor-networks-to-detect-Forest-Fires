// Transmitter NODE00 (A)

#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>
#include "DHT.h"
#define DHTPIN A0
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 
RF24 radio(7,8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
char this_node='A';   // Address of this node in Octal format ( 04,031, etc)
const uint16_t node00 = 00;
const uint16_t node02 = 02;
const uint16_t node03 = 03;
  
void setup()
{
  Serial.begin(9600);
  dht.begin();
  SPI.begin();
  radio.begin();
  network.begin(90, node00); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
}
void loop() 
{
  network.update();
    //float f = dht.readTemperature(true);
    unsigned long h = dht.readHumidity();  // Read the temp value
    unsigned long temp = dht.readTemperature();
    unsigned long smoke=analogRead(A1);
    // Compute heat index
    // Must send in temp in Fahrenheit!
    //float hi = dht.computeHeatIndex(f, h);
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(temp);
    Serial.print(" *C ");
    //Serial.print("Heat index: ");
    //Serial.print(hi);
    //Serial.println(" *F");
    Serial.print("Smoke : ");
    Serial.println(smoke); 
    if(temp>25 && smoke>150)
    {
      RF24NetworkHeader header5(node03);
      bool ok3 = network.write(header5, &this_node, sizeof(this_node));
      Serial.println(this_node); 
      delay(2000);
    }
}
  
