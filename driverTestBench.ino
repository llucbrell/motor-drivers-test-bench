byte greenLed=13;
byte yellowLed= 11;
byte redLed=9;
byte dir=7;
byte pwm=6;
byte enable=8;
byte pot=A2;


void setup() {
  
 // initialize pins.
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(enable, OUTPUT);
  pinMode(pwm, OUTPUT);
  pinMode(pot, INPUT);

  //light advise of power on

  digitalWrite(greenLed, HIGH);
  delay(500);
  digitalWrite(yellowLed, HIGH);
  delay(500);
  digitalWrite(redLed, HIGH);
  delay(500);

  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);
  delay(200);
  
  digitalWrite(greenLed, HIGH);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(redLed, HIGH);
  delay(500);

  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);
  delay(200);
  
  digitalWrite(greenLed, HIGH);
  delay(100);
  digitalWrite(yellowLed, HIGH);
  delay(100);
  digitalWrite(redLed, HIGH);
  delay(100);
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);
  delay(200);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(enable, HIGH);
  digitalWrite(dir, HIGH);
  int potValue= analogRead(pot);
  int pwmValue= map(potValue, 0, 1023, 0, 255);
  if(potValue < 20){
    digitalWrite(greenLed, LOW); 
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);  
    analogWrite(pwm, pwmValue);
   
  }
   else if(potValue >= 20 && potValue <=341 ){
    digitalWrite(greenLed, HIGH); 
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW); 
    analogWrite(pwm, pwmValue); 
    
  }
  else if(potValue > 341 && potValue <=682 ){
    digitalWrite(greenLed, HIGH); 
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW); 
    analogWrite(pwm, pwmValue); 
    
  }
  else if(potValue > 682 ){
    digitalWrite(greenLed, HIGH); 
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, HIGH);  
    analogWrite(pwm, pwmValue);
   
  }
    delay(30);
  Serial.print(potValue);
  Serial.print("-");
  Serial.println(pwmValue);
  
}
