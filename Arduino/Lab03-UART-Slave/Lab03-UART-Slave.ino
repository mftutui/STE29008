// slave
int byte_received = 0;
int led = 13;

void setup() {
  Serial.begin(9600); 
  pinMode(led, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){ 
    byte_received = Serial.read();
  }
}

