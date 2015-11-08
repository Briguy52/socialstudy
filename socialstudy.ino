int buttonPin = D0;
int trigPin = D1;
int echoPin = D2;
int minimumRange = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Particle.publish("the FCIEMAS Atrium");
    delay(500);
  }
  
  long duration, inches;
  
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  duration = pulseIn(echoPin, HIGH);
  
  inches = duration / 74 / 2;
  
  if (inches < 1 && inches > minimumRange) {
      Particle.publish("Twinnies");
      delayMicroseconds(500);
  }
  
 Serial.print(duration);
 Serial.println();
 delay(2000);
    
}
