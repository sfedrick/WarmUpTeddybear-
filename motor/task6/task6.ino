                                           void setup() {
  // put your setup code here, to run once:
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9, OUTPUT);
pinMode(A0, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,HIGH);
digitalWrite(12,LOW);

delay(100);

digitalWrite(13,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,HIGH);

delay(100);

digitalWrite(13,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
digitalWrite(12,HIGH);

delay(100);

digitalWrite(13,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,LOW);

delay(100);

}
