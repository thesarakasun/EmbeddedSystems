const int lm35Pin = A0;
const int motorPin = 6;  // PWM pin

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  int value = analogRead(lm35Pin);
  //analogReference(DEFAUL); not reuquired coz by default its setted up

  // Convert ADC to temperature (°C)
  float temp = (value * 5.0 * 100.0) / 1023.0;

  int pwm = 0;  // Default motor speed

  if (temp >= 35) {
    pwm = 255;               // Full speed
  }
  else if (temp < 25) {
    pwm = 0;                 // Motor off
  }
  else {  
    // Linearly increase from 25°C → 35°C (0 → 255)
    pwm = ((temp - 25.0) * 255.0) / 10.0;
  }

  analogWrite(motorPin, pwm);

  delay(200);
}
