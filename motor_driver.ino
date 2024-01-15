/*   
 *   Code is based on code
 *   by Dejan, https://howtomechatronics.com
 *   and https://roboticsbackend.com/raspberry-pi-arduino-serial-communication/
 */

// defines pins
#define stepPin 2 
#define dirPin 5 
#define sensorPin A0 //pin for RFID reader to input

int currentpos = 1; // options are 1 through 5, we assume by default that we start
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600); //baud rate 

}

//future work -- interrupts for RFID reads and to not consistantly poll for serial interrupts to allow for function
// currenrtly with the arduino mini I am using, there can only be digital inputs for interrupts so it does not make sense in this input


void loop() {
 
  int nextpos; // default // error value
  int rotvalue=0;
  int pulse;
  int sensorValue = 0;

  //getting RFID reader
  sensorValue = analogRead(sensorPin);

  //Valuse should be 5V however we allow for incorrect readings because this is an adrino
  if(sensorValue > 1000) {
    Serial.print("RFID Triggered\n");
    Serial.println(sensorValue,DEC);
  }

  // Serial Terminal to tell what position to go to
  if (Serial.available() > 0) {
    
    
  
    //serial tell us what 
    nextpos = Serial.read() - '0';

    if(nextpos < 6 & nextpos > -5) {
    Serial.print("Current spot :");
    Serial.println(currentpos,DEC);
    Serial.print("Next Spot to Go to: ");
    Serial.println(nextpos,DEC);
  
    //number of rotations
    rotvalue = currentpos - nextpos;

    //for efficencey we make sure we are taking the fastest possible task
    if (rotvalue == -4) {
      rotvalue = 1;
    }
    else if(rotvalue == 4)
    {
      rotvalue = -1;
    }
  
    if(rotvalue > 0){
      digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
    }
    else if (rotvalue < 0){
      digitalWrite(dirPin,LOW);
    }
    
    // Makes 200 pulses for making one full cycle rotation of the gear
    //we have a 5 to one gear ratio, so to in order to get 1 full rotation of the rack, we need to do 1000 pulses to do one full rotation
    // to do 1/5 rotation 10000/ 5 --> 200 pulses of 1/5 roataion

    pulse = 200 * abs(rotvalue);
  
    //so based on rot value we determine the pulse value

    for(int x = 0; x < pulse ; x++) { 
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(2000);    // by changing this time delay between the steps we can change the rotation speed
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(2000); 
    }

    currentpos = nextpos;
    Serial.print("Rotation is complete");
    delay(1000); // One second delay
  }
  }
}