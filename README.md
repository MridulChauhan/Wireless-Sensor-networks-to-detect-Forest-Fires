# Wireless-Sensor-networks-to-detect-Forest-Fires

To detect forest fires, I am proposing to make wireless sensing nodes laid out in forest in a radial circular manner following tree topology. These nodes will communicate with each other through radio frequencies (instead of using internet because of network availability problem inside the forests) using NRF24L01 long range trans receiver modules which can act as a transmitter as well as a receiver using radio frequencies. Each of these nodes will have 2 parts:

PART A :-
-> An Arduino, a DHT11 sensor and a MQ2 gas sensor module

PART B :-
-> An NRF24L01 module, a base module to regulate the voltage when the module is used for high range transmissions (1 Km without any data loss). 

=> During forest fire temperature and gas sensor readings are sent to higher level node using Part B . Each node is having a unique 15 bits address which is sent to the higher level node (along with the data of sensors) on detection of the forest fire. This higher level node further transfers the address and sensor information to next higher level node and finally to the base station. The base station is supposed to be located at a place where internet is available. Base station further transfers data to the server using WIFI module and an alarm is raised. The server is capable of showing the location of place on the google map where the fire is detected and also the nearest way to reach there (if available).
