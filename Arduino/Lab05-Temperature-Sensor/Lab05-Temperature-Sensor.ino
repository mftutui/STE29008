const int pin = 0;
int baud_rate = 9600;
float valorSensor = 0;
float analog_value, digital_value;
float res0, res1;
float TK, TC;

#define vin 5.0
#define R0 10000.0
#define T0 298.15
#define beta 3950.0

float RMS(int repeat){
  float accumulated = Accumulate(repeat);
  float average = accumulated/repeat;
  return sqrt(average);
}

float Accumulate(int repeat){
  float accumulated = 0;
  for (int i = 0; i < repeat; i++){
    digital_value = analogRead(pin);
    accumulated =  accumulated + (digital_value * digital_value);
  }
  return accumulated;
}

float Temperature(float digital_value){
  float analog_value = (digital_value*vin)/1024;
  res0 = R0*vin;
  res1 = (res0/analog_value) - R0; 
  delay(1000);
  TK =  1/T0 +((1/beta)*log(res1/R0));
  TK = 1/TK;
  TC = (TK - 273.15);
  return TC;
}

void setup() {
  Serial.begin(baud_rate);
}

void loop() {
  float digital_value = RMS(30);
  float temp = Temperature(digital_value);
  Serial.print("Temperatura: ");
  Serial.println(temp);
  delay(1000);
}
