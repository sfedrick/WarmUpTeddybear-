void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  
  Serial.begin(9600);
  Serial.setTimeout(-1);
  
 
}
int count=0;
double average = 0;
double averagevolt=0;
double T=0;
double Rt=0;
void loop() {
  // put your main code here, to run repeatedly:


double value=analogRead(A0);
value*=0.00488;
double R1=20000.0;

Rt=(R1*5-value*R1)/value;

T=1/((1/298.15)+(1/3950.0)*log10(Rt/100000.0));

if(count==10){
  
  average=average/10.0;
   averagevolt= averagevolt/10.0;
  Serial.println("this is the average temp");
  Serial.println(average);
  Serial.println("this is the average voltage");
  Serial.println(averagevolt);
  delay(100);
  count=0;
  average = 0;
  averagevolt=0;
  
}
else{
  
  
   delay(100);
 
  count+=1;
  average+=T;
  averagevolt+=value;
}

//This reads in the temp from the thermal resistor 


}
