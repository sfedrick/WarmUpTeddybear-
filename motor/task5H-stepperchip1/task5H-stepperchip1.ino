void setup() {
  // put your setup code here, to run once:

pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(-1);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(11,LOW);
digitalWrite(12,HIGH);
delay(1000);

}
