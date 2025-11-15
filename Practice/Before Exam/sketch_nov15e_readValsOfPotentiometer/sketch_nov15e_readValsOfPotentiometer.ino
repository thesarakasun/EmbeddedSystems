void setup() {
  Serial.begin(9600);      // Start serial communication
}

void loop() {
  int adcValue = analogRead(A0);        // Read ADC (0–1023)
  float voltage = adcValue * (5.0 / 1023.0); // Convert to voltage (0–5V)

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  delay(10000); // Small delay so serial monitor is readable
}
