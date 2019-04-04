int led_pin1 = 8;
int led_pin2 = 9;

int push_b1 = 2;
int push_b2 = 3;

int val1 = 1;
int val2 = 0;

void setup() {
    pinMode(led_pin1, OUTPUT);
    pinMode(led_pin2, OUTPUT);
    pinMode(push_b1, INPUT);
    pinMode(push_b2, INPUT);

}

void loop() {
    val1 = digitalRead(push_b1);
    val2 = digitalRead(push_b2);

    if (val1 == HIGH) {       
        digitalWrite(led_pin1, HIGH);
    }
    else{
        digitalWrite(led_pin1, LOW);
    }

    if (val2 == LOW) {       
        digitalWrite(led_pin2, HIGH);
    }
    else {
        digitalWrite(led_pin2, LOW);
    }
}