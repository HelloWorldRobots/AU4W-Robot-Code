/* Created at 6/19/2020 | Experiments with Robot (4WD) | Developed by: Akshat Sharma | */
/* Bluetooth Date: 2-Forward, 3-Backward, 4-Right, 5-Left, 6-Auto, 1-LED*/

int info;
const int LED_A = 12;
const int LED_B = 13;
const int LOWER_LED = 11;
const int TrigPin = A0;
const int EchoPin = A1;
const int ForwardL = 2;
const int ForwardR = 3;
const int BackwardL = 4;
const int BackwardR = 5;
const int LEDPIN = 10;
const int a = 6;
const int b = 7;
const int c = 8;
const int d = 9;
int range = 6;  
int near = 8;
int Follow = 20;
int Point = 35;


void setup() {
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LOWER_LED, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(ForwardL, OUTPUT);
  pinMode(ForwardR, OUTPUT);
  pinMode(BackwardL, OUTPUT);
  pinMode(BackwardR, OUTPUT);
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
  
  for(int p = 0; p < 8; p++){
  digitalWrite(LOWER_LED, HIGH);
  delay(350);
  digitalWrite(LOWER_LED, LOW);
  delay(350);
  }
  Serial.begin(9600);
  while(true){
  
  BlinkLED();
  if(Serial.available() > 0){
    info = Serial.read();
   }
    if(info == '2'){
        long inches;
        Object_Detection(inches);
        if(inches < near){
           backward();
           delay(300);
           stops();
         }
        Light_UP();
        Serial.println("Forward");
        forward();
        delay(680);
       
        Object_Detection(inches);
        if(inches < near){
           backward();
           delay(300);
           stops();
         }
        stops();
        Object_Detection(inches);
        if(inches < near){
           backward();
           delay(300);
           stops();
         }
      
        info = 0;
    }
        else if(info == '3'){
          Light_UP();
          Serial.println("Backward");
          Buzzer();
          backward();
          delay(680);
          stops();
          info = 0;
             }
        else if(info == '4'){
          long inches;
          Object_Detection(inches);
          if(inches < near){
             backward();
             delay(300);
             stops();
           }
             Light_UP();
             left();
             delay(680);
                 
          Object_Detection(inches);
          if(inches < near){
             backward();
             delay(300);
             stops();
           }
             stops();
                
           Object_Detection(inches);
           if(inches < near){
              backward();
              delay(300);
              stops();
           }
              info = 0;   
           }
      
        else if(info == '5'){
          Light_UP();
          long inches;
          Object_Detection(inches);
          if(inches < near){
             backward();
             delay(300);
             stops();
           }
             right();
             delay(680);
          Object_Detection(inches);
          if(inches < near){
             backward();
             delay(300);
             stops();
           }
          
           stops();
             
           Object_Detection(inches);
           if(inches < near){
              backward();
              delay(300);
              stops();
             }
              info = 0;
            }
        else if(info == '6'){
           NightMode();
           info == 0;
        }
        else if(info == '1'){
          Light_UP();
          stops();
          info = 0;
          
        }
        else if(info == '7'){
           Light_UP();
           Go_To_Point_A();
        }
         else if(info == '8'){
          Light_UP();
          AutoMode();
          
        }
         else if(info == '9'){
          Light_UP();
          
          FollowObjectAuto();
          
          
        }
      
  }
  
}
  
void loop() {


}

void forward(){
  digitalWrite(ForwardR, HIGH);
  digitalWrite(ForwardL, LOW);
  digitalWrite(BackwardR, HIGH);
  digitalWrite(BackwardL, LOW);
  digitalWrite(a, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(d, LOW);
}

void backward(){
  digitalWrite(ForwardR, LOW);
  digitalWrite(ForwardL, HIGH);
  digitalWrite(BackwardR, LOW);
  digitalWrite(BackwardL, HIGH); 
  digitalWrite(a, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(d, HIGH);
}

void left(){
  digitalWrite(ForwardR, HIGH);
  digitalWrite(ForwardL, LOW);
  digitalWrite(BackwardR, LOW);
  digitalWrite(BackwardL, HIGH); 
  digitalWrite(a, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(d, LOW);
  
}
void right(){
  digitalWrite(ForwardR, LOW);
  digitalWrite(ForwardL, HIGH);
  digitalWrite(BackwardR, HIGH);
  digitalWrite(BackwardL, LOW); 
  digitalWrite(a, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(b, LOW);
  digitalWrite(d, HIGH);
}

void stops(){
   digitalWrite(ForwardR, LOW);
  digitalWrite(ForwardL, LOW);
  digitalWrite(BackwardR, LOW);
  digitalWrite(BackwardL, LOW);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  
}

void AutoMode(){
  long inches;
  Object_Detection(inches);
  

 
   if(inches > range){
    
    forward();
   
    Object_Detection(inches);
    
    }
    if(inches < range){  
      Serial.println(inches);
      backward();
      delay(1555);
      stops();
      tone(13, 699, 650);
      delay(150);
      right();
      delay(1000);
      Object_Detection(inches);
    
    
   }
 
     
   }

 

void FollowObjectAuto(){
   long inches;
   Object_Detection(inches);
  if(inches > Follow){
     for(int m; m < 3; m++){
        right();
        delay(250);
        stops();
        Object_Detection(inches);
       
          if(inches < Follow){
                break;
          }
        delay(250);
    }
  
      for(int g; g < 6; g++){
        left();
        delay(250);
        stops();
       
        Object_Detection(inches);
     
        if(inches < Follow){
           break;
        }
        delay(250);
        
   
      }
 }
  if(inches < Follow){
    
    forward();

    Object_Detection(inches);
    
    
  }
  

}
void Go_To_Point_A(){
  
  Go_Straight_Until_Obstacle();
  
  
}

void Go_Straight_Until_Obstacle(){
   long inches;
   Object_Detection(inches);
  
  
  if(inches > Point){
    forward();
    long inches;
    Object_Detection(inches);
    
  
    
    
  
  }
  if(inches < Point){
    right();
    delay(680);
    stops();
    long inches;
    Object_Detection(inches);
    
    
  }
}

void BlinkLED(){
  digitalWrite(LED_A, HIGH);
  digitalWrite(LED_B, HIGH);
  delay(350);
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
  delay(350);
}

void Light_UP(){
  digitalWrite(LED_A, HIGH);
  digitalWrite(LED_B, HIGH);
}

void Buzzer(){
  for(int r = 0; r < 3; r++){
   tone(10, 250, 250);
    
  }
}
void Obstacle_Buzz(){
   tone(10, 699);
}
void NightMode(){
  digitalWrite(LOWER_LED, HIGH);
}
long microsecondsToInches(long microseconds){
 return microseconds / 74 / 2;
}

void Object_Detection(long &inches){
     long duration;
    digitalWrite(TrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(TrigPin, LOW);
    
    duration = pulseIn(EchoPin, HIGH);
      
    inches = microsecondsToInches(duration);
}
