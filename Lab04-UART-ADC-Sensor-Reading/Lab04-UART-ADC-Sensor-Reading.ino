int val_a, val_d = 0;
int pin = 3;  

int RMS(int repeat){
  int accumulated = 0;
  int digital_value, analog_value, average;
    
  for (int i = 0; i < repeat; i++){
    digital_value = analogRead(pin);   //convert the analog-value (voltage) to digital one (0-1024)
    accumulated = accumulated + digital_value*digital_value;   //accumulate all the digital-values “repeat” times
  }
  average = accumulated/repeat;
  return sqrt(average);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  val_d = RMS(30);    //accumulate x mesures. Recomended x=30;
  val_a = (val_d*5)/1024;// Regra de 3 para saber o valor analógico
  
  Serial.println("Digital:" + val_d);
  Serial.println("Analógico:" + val_a);
  delay(2000);
} 
