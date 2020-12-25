void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
// I had to switch out pin 8 because it's busted so now we're using pin 13 instead of 8
pinMode(13,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9, OUTPUT);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
Serial.begin(9600);
  Serial.setTimeout(-1);


}
// initialize variables
int count=0;
double average = 0;
double water=0;
double averagevolt=0;
double T=0;
double Theater=0;
double Tset=450;
double Rt=0;
double Rtheater=0;
boolean on=false;
int timer = 0;
double desired=400;
boolean pour=false;
int G= 85;
int IG=0.425;
float error=0;
double response=0;
double errorintegral=0;
int falsereading=0;
void loop() {
  // this reads in the temperature  it can read in the value from two thermistors one from A0 and one from A1
    double value=analogRead(A0);
    double valueheater=analogRead(A1);
      value*=0.00488;
      valueheater*=0.00488;
      double R1=20000.0;
    
      Rt=(R1*5-value*R1)/value;
      Rtheater=(R1*5-valueheater*R1)/valueheater;
    
      T=1/((1/298.15)+(1/3950.0)*log10(Rt/100000.0));
      Theater=1/((1/298.15)+(1/3950.0)*log10(Rtheater/100000.0));




//calculates the average temp 
 if(count==10){
      
          average=average/10.0;
          water=water/10;
          averagevolt= averagevolt/10.0;
         // Serial.println("this is the average temp");
         error=Tset-average;
        errorintegral+=error;
        // this sets the heater but because water takes so god damn long to boil we won't be using this we'll just keep the heaters blasted so response will 
        // Always equal 255
         response=int(G*error +IG*errorintegral);
         if(response>255){
          response=255;
         }
         else if(response<1){
          response=0;
         }
          Serial.println("water temp: ");
          Serial.print(water);
          Serial.println("");
          Serial.println("Heater Temp: ");
          Serial.print(average);
           Serial.println("");
          Serial.println("false readings: ");
          Serial.print(falsereading);
           Serial.println("");
        
          
      
        
          // Serial.println("this is the average voltage");
          // Serial.println(averagevolt);
          delay(100);
          //water fluctuates in temp so some parts of the water might be hotter than other parts
          // this could mean that the thermistor could read a temp thats desired but it turns out that the 
          // water is actually far colder to account for this I made a false reading variable that'll only pour 
          // the water if there are 3000 consecutive desired temperature readings
          if(falsereading>3000){
            pour=true;
            falsereading=0;
         
          }
          else if(falsereading>1 && water<desired){
            falsereading-=1;
          }
          else if(water>=desired){
              falsereading+=1;  
          }
          
         
          timer+=1;
          count=0;
          average = 0;
          water=0;
          averagevolt=0;
          //Serial.println("this is the 1 second timer ");
          //Serial.println(timer);
        }
      else{
      
      
          delay(100);
          count+=1;
          average+=Theater;
          water+=T;
          averagevolt+=value;
          
      }
// pours the water
if(pour){
  int rotate=0;
 
  
  while(rotate<12){
     digitalWrite(13,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
   delay(100);
     digitalWrite(13,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
   delay(100);
    digitalWrite(13,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
     delay(100);
      digitalWrite(13,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
     delay(100);

     rotate+=1;
    Serial.println(rotate);
  }
  delay(2000);
  while(rotate>=0){
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
    rotate-=1;
  Serial.println(rotate);}
  pour=false;
}

if(!pour){
  // motor stay
digitalWrite(13,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,HIGH);
analogWrite(9,255);



}

}
