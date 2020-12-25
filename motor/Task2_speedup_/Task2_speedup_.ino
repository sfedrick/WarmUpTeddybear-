void setup() {
  // put your setup code here, to run once:
 // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  Serial.setTimeout(-1);
  
}
int timer=0;
int response=0;\
int stepint=5;
//the response step the number of time steps we take before each ramp up 
double totaltimesteps=255/stepint;
//and the number of ramp up steps it takes to get to the max of the ramp
double responsestep=255/stepint;

//desired ramp up time in miliseconds
double ramptime=2000;
double actualdelay=ramptime/(totaltimesteps*responsestep);
boolean up=true;
void loop() {
   if(timer>=responsestep){
       if(response>=255 && up){
        up=false;
      }
      else if(response<=0 && !up){
        up=true;
      }
      
      if(up){
        response+=stepint;
        analogWrite(9,response);
      }
      else if(!up){
      response-=stepint;
      analogWrite(9,response);
     
      }
      
   
      
      
      
      

    
    timer=0;
    }
    else{
       timer+=1;
       delay(actualdelay);
       Serial.println(actualdelay);
       
      
    }
  
    
  // put your main code here, to run repeatedly:

}
