#include <Servo.h>
int ENA=5; 
int ENB=11; 
int IN1=6; 
int IN2=7; 
int IN3=8; 
int IN4=9; 
float d; 
int degRot;
int servoPin=10;
int servoPos;
int trigPin=12;
int echoPin=13;
int pingTravelTime;
int SensorKanan;
Servo myServo; 
void setup() { 
  // put your setup code here, to run once: 
  Serial.begin(9600); 
  pinMode(ENA,OUTPUT); 
  pinMode(ENB,OUTPUT); 
  pinMode(IN1,OUTPUT); 
  pinMode(IN2,OUTPUT); 
  pinMode(IN3,OUTPUT); 
  pinMode(IN4,OUTPUT); 
  digitalWrite(ENA,HIGH); 
  digitalWrite(ENB,HIGH); 
  myServo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  } 
  void loop() { 
    if (Sensor()<=2000){
      stopCar();
      delay(100);
      backward(1);
      delay(100);
      stopCar();
      delay(100);
      int Kiri=lookLeft();
      delay(100);
      int Kanan=lookRight();
      delay(100);
      if (Kiri>=Kanan){
        turnLeft(100);
        stopCar();
        }
      else{
        turnRight(100);
        stopCar();
        }
      }
      forward();
    } 
    void backward(float d){ 
      float t; 
      digitalWrite(IN1,HIGH); 
      digitalWrite(IN2,LOW); 
      digitalWrite(IN3,LOW); 
      digitalWrite(IN4,HIGH); 
      t=d/2.45*1000; 
      delay(t); 
      stopCar(); 
      } 
      void forward(){ 
       
      digitalWrite(IN1,LOW); 
      digitalWrite(IN2,HIGH); 
      digitalWrite(IN3,HIGH); 
      digitalWrite(IN4,LOW); 
      //t=d/2.45*1000; 
      //delay(t); 
       
      } 
      void turnLeft(int deg){ 
        float t; 
        digitalWrite(IN1,HIGH); 
        digitalWrite(IN2,LOW); 
        digitalWrite(IN3,HIGH); 
        digitalWrite(IN4,LOW); 
        t=deg/390.*1000.; 
        Serial.println(deg); 
        delay(t); stopCar(); 
        } 
        void turnRight(float deg){ 
          float t; 
          digitalWrite(IN1,LOW); 
          digitalWrite(IN2,HIGH); 
          digitalWrite(IN3,LOW); 
          digitalWrite(IN4,HIGH); 
          t=deg/390.*1000.; 
          Serial.println(deg); 
          delay(t); stopCar(); 
          } 
          void stopCar(){ 
            digitalWrite(IN1,LOW); 
            digitalWrite(IN2,LOW); 
            digitalWrite(IN3,LOW); 
            digitalWrite(IN4,LOW); 
            } 
            void calF(){ 
             digitalWrite(IN1,HIGH); 
             digitalWrite(IN2,LOW); 
             digitalWrite(IN3,LOW); 
             digitalWrite(IN4,HIGH); 
             delay(5000); stopCar(); 
             } 
             void calB(){ 
              digitalWrite(IN1,LOW); 
              digitalWrite(IN2,HIGH); 
              digitalWrite(IN3,HIGH); 
              digitalWrite(IN4,LOW); 
              delay(5000); 
              stopCar(); 
              } 
              void calR(){ 
                digitalWrite(IN1,HIGH); 
                digitalWrite(IN2,LOW); 
                digitalWrite(IN3,HIGH); 
                digitalWrite(IN4,LOW); 
                delay(5000); stopCar(); 
                } 
                void calL(){ 
                  digitalWrite(IN1,LOW); 
                  digitalWrite(IN2,HIGH); 
                  digitalWrite(IN3,LOW); 
                  digitalWrite(IN4,HIGH); 
                  delay(5000); 
                  stopCar(); 
                  }
int lookRight(){
  int SensorKanan;
  myServo.write(0);
  delay(500);
  SensorKanan=Sensor();
  delay(500);
  myServo.write(90);
  delay(500);
  return SensorKanan;
  }
int lookLeft(){
  int SensorKiri;
  myServo.write(170);
  delay(500);
  SensorKiri=Sensor();
  delay(500);
  myServo.write(90);
  delay(500);
  return SensorKiri;
  }
int Sensor(){
  int pingTravelTime;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite (trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  pingTravelTime=pulseIn(echoPin,HIGH);
  return pingTravelTime;
  }
