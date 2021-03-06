const int led1 = 13;
const int button1 = 2;

unsigned long now;
unsigned long before;

volatile boolean led_state = 1;
int debounce_limit = 300;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(button1, INPUT);
  before = millis();
  attachInterrupt(digitalPinToInterrupt(button1), interrupt_handler, RISING);
}

void loop() {
  digitalWrite(led1, led_state);
}

void interrupt_handler() { 
  now = millis(); 
  if( (now - before) > debounce_limit) {
    before = now;
    led_state = !led_state;
  }
}
