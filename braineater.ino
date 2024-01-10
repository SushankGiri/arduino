int trigPin = 9;
int echoPin = 10;
double duration;
double distance = 300;
int a_forward = 2;
int a_backward = 3;
int b_forward = 4;
int b_backward = 5;
char t;
bool detectS = false;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(a_forward,OUTPUT);   
  pinMode(a_backward,OUTPUT);  
  pinMode(b_forward,OUTPUT);   
  pinMode(b_backward,OUTPUT); 
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  Serial.begin(9600);
}
void loop() {
  delay(10);
  if(Serial.available()){
    t = Serial.read();
  }
  Serial.print(t);
  
  switch (t){      
  case 'F':
    digitalWrite(a_forward,HIGH);
    digitalWrite(b_forward,HIGH);
    break;

  case 'B':
    digitalWrite(a_backward,HIGH);
    digitalWrite(b_backward,HIGH);
    break;

 
  case 'L':     
    digitalWrite(b_forward,HIGH);
    digitalWrite(a_backward,HIGH);
    break;

   
  case 'R': 
    digitalWrite(a_forward,HIGH);
    digitalWrite(b_backward,HIGH);
    break;

  
  case 'S':  
    digitalWrite(a_forward,LOW);
    digitalWrite(a_backward,LOW);
    digitalWrite(b_forward,LOW);
    digitalWrite(b_backward,LOW);
    break;
  default: 
    digitalWrite(a_forward,LOW);
    digitalWrite(a_backward,LOW);
    digitalWrite(b_forward,LOW);
    digitalWrite(b_backward,LOW);
    break;

  case 'V':
    while (true){
      if(Serial.available()){
        t = Serial.read();
      } 
  
      distance = detect();
      while (distance <= 40){
        digitalWrite(a_forward,LOW);
        digitalWrite(a_backward,HIGH);
        digitalWrite(b_forward,HIGH);
        digitalWrite(b_backward,LOW);
        delay(10);
        digitalWrite(a_forward,LOW);
        digitalWrite(a_backward,LOW);
        digitalWrite(b_forward,LOW);
        digitalWrite(b_backward,LOW);
        if(Serial.available())
        {
          t = Serial.read();
        } 
        if (t=='v')
        {
          break;
        }
      }
      digitalWrite(a_forward,HIGH);
      digitalWrite(a_backward,LOW);
      digitalWrite(b_forward,HIGH);
      digitalWrite(b_backward,LOW);
      delay(10);
      if (t=='v')
      {
        break;
      }
      if (t=='v')
      {
        break;
      }
    
    }
    break;
  }

}



double detect(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  return distance;
}
