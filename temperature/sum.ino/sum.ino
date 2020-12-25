char Ch = 0;
char Ch1=0;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.setTimeout(-1);
}
int num1=0;
int num2=0;
boolean firstnum=false;
void loop() {
  // put your main code here, to run repeatedly:


  if (Serial.available()&&!firstnum) {
    Ch = Serial.read();
    Serial.println("Boolean value");
     Serial.println(firstnum);
    num1 = Ch-'0'; 
    Serial.write(Ch);
     Serial.println("");
    Serial.println("First number");
    firstnum = true;
    Serial.println("Changed");
    Serial.println(firstnum);
    
  }
   
 if (Serial.available()&& firstnum) {
  
  Serial.println("Boolean value second number");
     Serial.println(firstnum);
    Ch1 = Serial.read();
    num2 = Ch1-'0';
     Serial.println("The second number");
    Serial.write(Ch1);
    firstnum = false;
     Serial.println("Boolean value second number changed");
      Serial.println(firstnum);
     int sum=num2+num1;
      Serial.println("Sum of the numbers is this:");
      Serial.println(sum);
   }

  
}
