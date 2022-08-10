const int sensorPin = A0;
const int baselineTemp = 28;

void setup() {
  // Start a serial communication
  Serial.begin(9600);

  // iterate over each pin, initiate it as output and set it to off or 'LOW'
  for(int pinNumber = 0; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {

  // Read TMP32 Value
  int sensorVal = analogRead(sensorPin);
  
  Serial.print("sensorVal: ");
  Serial.print(sensorVal);

  // Calculate voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  
  Serial.print(", voltage: ");
  Serial.print(voltage);

  // Calculate temperature
  float temperature = (voltage - .5) * 100;
  
  Serial.print(", temperature: ");
  Serial.print(temperature);
  Serial.print("\n");

  if(temperature >= baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  } else if(temperature >= baselineTemp+4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp+2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  delay(1);
}



