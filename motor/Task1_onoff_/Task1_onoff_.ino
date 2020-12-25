void setup() {
  // put your setup code here, to run once:
 // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  Serial.setTimeout(-1);
  
}
int timer=0;
boolean on=false;
void loop() {
   if(timer==20){
    if(!on){
    digitalWrite(9,HIGH);
    on=true;
    }
    else{
    digitalWrite(9,LOW);
    on=false;
    }
    timer=0;
    }
    else{
       timer+=1;
       delay(100);
      
    }
  
    
  // put your main code here, to run repeatedly:

}
