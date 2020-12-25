void setup() {
  // put your setup code here, to run once:

  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (digitalRead(3) == 0) {
digitalWrite(2, LOW);
} else {
digitalWrite(2, HIGH);
}

 if (digitalRead(4) == 0) {
digitalWrite(LED_BUILTIN, LOW);
} else {
digitalWrite(LED_BUILTIN, HIGH);
}

}
