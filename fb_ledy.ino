#include <SoftwareSerial.h>

#define REDPIN 5
#define GREENPIN 3
#define BLUEPIN 6


/* These are function prototypes - required by the compiler */
void a();
void b();
void c();

typedef void (* Caller)();
Caller FuncCall[] = {&a, &b, &c}; //initialize addresses for pointers 
//String func_list[] = {"a","b","c"}; //this is a terrible way to do this
char func_list[] = {'a', 'b', 'c'};   //use this instead - if you wish

void setup(){
    Serial.begin(9600);
    pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

void a(){
  for(int j=0; j<256; j++) { analogWrite(BLUEPIN, j); delay(10); }
  delay(10);
  for(int j=255; j>=0; j--) {
      analogWrite(BLUEPIN, j); 
      delay(10);
  }
}





void b(){

}

void c(){
    Serial.println("Called Function: c\n");
}

void loop(){
    if(Serial.available())
        switch(Serial.read()){
            case 'a':           //this could also be func_list[0], if you want
                FuncCall[0]();
                break;

            case 'b':
                FuncCall[1]();
                break;

            case 'c':
                FuncCall[2]();
                break;

            default:
                Serial.println("There was an error\n");
                break;
    }
}
