/*   
 *   Code is based on code
 *   by Dejan, https://howtomechatronics.com
 *   and https://roboticsbackend.com/raspberry-pi-arduino-serial-communication/
 */

// defines pins
#define stepPin 2 
#define dirPin 5 
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600); //baud rate -- low baud rate but 
  int currentpos = 1 // options are 1 through 5, we assume by default that we start
  int nextpos = 1 // default // error value
  int rotvalue = 0
}


void loop() {
  // Serial Terminal to tell what position to go to
  if (Serial.available() > 0) {
    //serial tell us what 
    nextpos = Serial.read() - '0'
    Serial.print("Next Spot to Go to: ");
    Serial.println(nextpos,DEC);
  
    //number of rotations
    rotvalue = current position - next position

    //for efficencey we make sure we are taking the fastest possible task
    if (rotvalue == -4) {
      rotvalue = 1;
    }
    else if(rotvalue = 4)
    {
      rotvalue = -1;
    }

    if(rotvalue > 0){
      digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
    }
    else if (rotvalue < 0{
      digitalWrite(dirPin,LOW)
    }
    
    // Makes 200 pulses for making one full cycle rotation of the gear
    //we have a 5 to one gear ratio, so to in order to get 1 full rotation of the rack, we need to do 1000 pulses to do one full rotation
    // to do 1/5 rotation 10000/ 5 --> 200 pulses of 1/5 roataion

    int pulse = 200 * abs(rotvalue) * 4

    //so based on rot value we determine the pulse value

    for(int x = 0; x < pulse ; x++) { //multiply pulse value by 4
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(700);    // by changing this time delay between the steps we can change the rotation speed
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(700); 
    }
    delay(1000); // One second delay
  }

}