void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(-1);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("step 1");
digitalWrite(8,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,HIGH);
digitalWrite(12,LOW);


Serial.println("step 2");
digitalWrite(8,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,HIGH);


Serial.println("step 3");
digitalWrite(8,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
digitalWrite(12,HIGH);


Serial.println("step 4");
digitalWrite(8,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,LOW);

}
