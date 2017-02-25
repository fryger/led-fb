// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
 
#define REDPIN 5
#define GREENPIN 3
#define BLUEPIN 6
#define FADESPEED 5     // make this higher to slow down
int i = 0;

void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  Serial.begin(9600);
}
 
 
void loop() {

  

  
while (Serial.available() == 1){

long val = Serial.parseInt();
if(val >= 1){
  i=i+1;
  if(val == 1){val = 0;};
  Serial.println(val);
  if(i == 1){
    analogWrite(REDPIN, val);
  }
  if(i == 2){

     analogWrite(GREENPIN, val);

  }
  if(i == 3) {
     analogWrite(BLUEPIN, val); 
     i=0; 
  }

}
}
}

