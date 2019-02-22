byte byte_received = 0;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  if(Serial.available()){
    byte_received = Serial.read();
    byte_received++;
    Serial.write(byte_received);
    Serial.println();
  }
}

