const int pin = 0;
float valorSensor = 0;
float analog_value, digital_value;
int baud_rate = 9600;

int RMS(int repeat){
  float accumulated = 0;
  float average;
  for (int i = 0; i < repeat; i++){
    digital_value = analogRead(pin);
    accumulated =  accumulated + (digital_value * digital_value);
  }
  average = accumulated/repeat;
  return sqrt(average);
}

void setup() {
  Serial.begin(baud_rate);
}

void loop() {
  digital_value = RMS(30);
  analog_value = (digital_value*5)/1024;
  Serial.print("Digital: ");
  Serial.println(digital_value);
  Serial.print("Analógico: ");
  Serial.println(analog_value);
  delay(1000);
}
