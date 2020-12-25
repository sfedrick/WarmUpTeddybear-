void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  Serial.setTimeout(-1);
  
 
}
int count=0;
double average = 0;
double averagevolt=0;
double T=0;
double Tset=333;
double Rt=0;
boolean on=false;
int timer = 0;
int G= 85;
int IG=0.425;
float error=0;
int response=0;
int errorintegral=0;
void loop() {
  
  // put your main code here, to run repeatedly:
  if(timer==10){
    analogWrite(9,response);
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
         error=Tset-average;
         errorintegral+=error;
         response=int(G*error +IG*errorintegral);
         if(response>255){
          response=255;
         }
         else if(response<1){
          response=0;
         }
          Serial.println("");
          Serial.print(average);
          //Serial.print(",");
          //Serial.print(response);
          
      
        
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
  
    
  }
  
  



}
