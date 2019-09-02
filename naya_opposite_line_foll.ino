
   ////////////////////////////////////////////////////////
  //               LinoBot v1.0                         //             
 //               By vikas ece                         //
////////////////////////////////////////////////////////

//I have added the two modes for turning(normal turn or fast turn) the lfr bot
//The values of analogRead could be changed for trouble shooting

//including the libraries
 #include <AFMotor.h>

//defining pins and variables
const int left = A1;
const int  right = A2; 

//defining motors
AF_DCMotor motor1(1, MOTOR12_8KHZ); 
AF_DCMotor motor2(2, MOTOR12_8KHZ);
/*
AF_DCMotor motor1(3, MOTOR12_8KHZ); 
AF_DCMotor motor2(4, MOTOR12_8KHZ);
 */

void setup() {
  //setting the speed of motors
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  //declaring pin types
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  //begin serial communication
  Serial.begin(9600);
  
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.println(digitalRead(left));
  Serial.println(digitalRead(right));
  //line detected by both
  if(!digitalRead(left) && !digitalRead(right)){
    //stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    Serial.println("STOP");
  }
  //line detected by left sensor
  else if(!digitalRead(left) && digitalRead(right)){
    //turn left
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    Serial.println("LEFT");
    /*
    motor1.run(RELEASE);
    motor2.run(FORWARD);
     */
  }
  //line detected by right sensor
  else if(digitalRead(left) && !digitalRead(right)){
    //turn right
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    Serial.println("RIGHT");
    /*
    motor1.run(FORWARD);
    motor2.run(RELEASE);
     */
  }
  //line detected by none
  else if(digitalRead(left) && digitalRead(right)){
    //forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    Serial.println("FORWARD");
    /*
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
     */
  }
  
}


