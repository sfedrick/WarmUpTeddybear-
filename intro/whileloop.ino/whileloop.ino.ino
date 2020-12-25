void setup() {
  // put your setup code here, to run once:
 pinMode(2, OUTPUT);
 pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 // put your main code here, to run repeatedly:
  int countled=0;
  int countbuiltin=0;

 while(countbuiltin<3){
  digitalWrite(LED_BUILTIN,HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN,LOW);
  delay(250);
  countbuiltin=countbuiltin+1;
 }
 while(countled<6){
  digitalWrite(2,HIGH);
  delay(250);
  digitalWrite(2,LOW);
  delay(250);
  countled=countled+1;
 }


 
}
