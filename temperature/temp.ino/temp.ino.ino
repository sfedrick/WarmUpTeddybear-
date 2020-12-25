void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  
  Serial.begin(9600);
  Serial.setTimeout(-1);
  
 
}

void loop() {
  // put your main code here, to run repeatedly:


 delay(1000);
double value=analogRead(A0);
value*=0.00488;
 Serial.println(value);

}
