    
#include <Servo.h>  //servo library
Servo myservo;      // create servo object to control servo

//Ultrasonic sensor variables
int Echo = 4;  
int Trig = 5; 

//motor controller pins
#define ENA 11
#define ENB 3
#define IN1 A0
#define IN2 A1
#define IN3 A3
#define IN4 A4
#define carSpeed 150
#define carSpeed2 150
int rightDistance = 0, leftDistance = 0;
void forward(){ 
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
}

void back() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
}
void left() {
  analogWrite(ENA, carSpeed2);
  analogWrite(ENB, carSpeed2);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  Serial.println("Left");
}
void right() {
  analogWrite(ENA, carSpeed2);
  analogWrite(ENB, carSpeed2);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Right");
}
void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
}
int Distance_test() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance / 58;       
  return (int)Fdistance;
 // Serial.println (Fdistance);
}
void setup() { 
  myservo.attach(9);  // attach servo on pin 3 to servo object
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();
}
void loop() { 
  
    myservo.write(50);  //setservo position to right side
    delay(300); 
    rightDistance = Distance_test();

    myservo.write(110);  //setservo position to left side
    delay(300); 
    leftDistance = Distance_test();

 myservo.write(170);  //setservo position to left side
    delay(300); 
    leftDistance = Distance_test();
    
    if((rightDistance > 70)&&(leftDistance > 30)){
      stop();
    }else if((rightDistance > 10&&rightDistance<20) ||0 (leftDistance>10&& leftDistance<20)) {     
      forward();
    }else if((rightDistance <= 7) && (leftDistance <= 7)) {
        back();
        delay(100);
    }
    else if(rightDistance - 3 > leftDistance) {
        left();
        delay(100);
    }else if(rightDistance + 3 < leftDistance) {
        right();
        delay(100);
    }else{
      stop();
    }
    
}
    
        
