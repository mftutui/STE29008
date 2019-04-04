int led1 = 13;
int push_b = 2;

void serial_write(){
  if(digitalRead(push_b) == LOW){
    Serial.println("Desafio, aula 5");
  }
}

void blink_led(){
  digitalWrite(led1, HIGH);
  delay(2000);
  digitalWrite(led1, LOW);
  delay(2000);
}

void setup() {
  Serial.begin(9600);
  pinMode(push_b, INPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  blink_led();
  serial_write();
}

