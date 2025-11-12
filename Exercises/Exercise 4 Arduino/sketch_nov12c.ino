void setup() {
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT) ;
}

void loop() {
  int value = analogRead(A0);
  float vIn = value * 5.0/1024;
  digitalWrite(8,LOW);
  if(vIn>4.9)
    digitalWrite(8,HIGH);
  else
    digitalWrite(8,LOW);
}
