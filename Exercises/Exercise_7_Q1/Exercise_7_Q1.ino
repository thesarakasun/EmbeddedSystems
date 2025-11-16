// This variable holds the last command received ('Y' to send, 'N' to stop)
char ch = 'N';

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    ch = Serial.read(); // Read the character and update the command
  }

  // If the last command was 'Y', start/continue transmitting temperature
  if (ch == 'Y') { 
    
    // Read the analog value from the LM35 sensor on pin A0 (PC0)
    int adcVal = analogRead(A0);

    // Convert the 10-bit ADC value (0-1023) to a voltage (0.0-5.0V)
    float voltage = adcVal * (5.0 / 1024.0);

    // Convert the voltage to temperature in Celsius
    // (LM35 is 10mV per degree C, so temp = voltage * 100)
    float tempC = voltage * 100; 

    Serial.println((int)tempC); 


    delay(1000); 
  }

}