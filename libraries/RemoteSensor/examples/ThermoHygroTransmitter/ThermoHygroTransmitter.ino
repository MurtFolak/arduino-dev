/*
 * This sketch sends (bogus) thermo / hygro data to a remote weather sensors made by Cresta.
 * 
 * Setup:
 *  - connect transmitter input of a 433MHz transmitter to digital pin 11
 *  - On the weather station, activate the "scan" function for channel 1.
 */
 
 #include <SensorTransmitter.h>
 
 // Initializes a ThermoHygroTransmitter on pin 11, with "random" ID 0.
 ThermoHygroTransmitter transmitter(11, 0);
 
 void setup() {
 }
 
 void loop() {
   // Displays temperatures from -10 degrees Celsius to +20,
   // and humidity from 10% REL to 40% REL, with increments of 2
   for (int i = -10; i<=20; i+=2) {
     // Temperatures are passed at 10 times the real value,
     // to avoid using floating point math.
     // last value set channel 1 (2,3)
     transmitter.sendTempHumi(i * 10, i + 20, 1);
     
     // Wait two seconds before sending next.
     delay(2000);
   }
 }
