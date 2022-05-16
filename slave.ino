//Slave

// Include Arduino Wire library for I2C
#include <Wire.h>
  
// Define Slave answer size
#define ANSWERSIZE 7
 
// Define string with response to Master
String reading = "";
 
void setup() {
 
  // Initialize I2C communications as Slave
  Wire.begin(0x8);
  
//  // Function to run when data requested from master
  Wire.onRequest(requestEvent); 
  
  // Function to run when data received from master
//  Wire.onReceive(receiveEvent);
  

  Serial.begin(9600);

}
 

 
void requestEvent() {
 
  // Setup byte variable in the correct size
  byte response[ANSWERSIZE];

   long randData = random(10);

   if(randData <4){
    reading = "Low";
   }
   else if(randData>4 && randData<6){
    reading = "medium";
   }
   else if(randData>6){
    reading = "Bright";
   }
   
    Serial.println(reading);
    
  // Format answer as array
  for (byte i=0;i<ANSWERSIZE;i++) {
    response[i] = (byte)reading.charAt(i);
  }
  
  // Send response back to Master
  Wire.write(response,sizeof(response));
  
  // Print to Serial Monitor
  Serial.println("Request event");
}
 
void loop() {
 
  // Time delay in loop
  delay(50);
}
