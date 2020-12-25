void setup() {
  // put your setup code here, to run once:
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(8,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9, OUTPUT);
pinMode(A0, INPUT);

int count=0;
double average = 0;
double averagevolt=0;
double T=0;
double Tset=333;
double Rt=0;
boolean on=false;
int timer = 0;

}

void loop() {
  // put your main code here, to run repeatedly:

//Motor Code

digitalWrite(8,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,HIGH);
digitalWrite(12,LOW);

delay(100);

digitalWrite(8,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,HIGH);

delay(100);

digitalWrite(8,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
digitalWrite(12,HIGH);

delay(100);

digitalWrite(8,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,LOW);

delay(100);


//Heater and Thermistor Code

  if(timer==10){
      if(on){
        digitalWrite(9,HIGH);
        
        
      }
      else{
          digitalWrite(9,LOW);
         
      }
      timer=0;
    }
  else{
      
      
      double value=analogRead(A0);
      value*=0.00488;
      double R1=20000.0;
    
      Rt=(R1*5-value*R1)/value;
    
      T=1/((1/298.15)+(1/3950.0)*log10(Rt/100000.0));
    
      if(count==10){
      
          average=average/10.0;
          
          averagevolt= averagevolt/10.0;
         // Serial.println("this is the average temp");
          Serial.println("");
          Serial.print(average);
          Serial.print(",");
          Serial.print((on*100)+200);
          if(average>Tset){
            on=false;
          }
          else{
            on=true;
          }
          // Serial.println("this is the average voltage");
          // Serial.println(averagevolt);
          delay(100);
          timer+=1;
          count=0;
          average = 0;
          averagevolt=0;
          //Serial.println("this is the 1 second timer ");
          //Serial.println(timer);
        }
      else{
      
      
          delay(100);
          count+=1;
          average+=T;
          averagevolt+=value;
          

}