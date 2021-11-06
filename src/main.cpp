#include <Arduino.h>

#define analog A0
#define fiveVolts 2
#define relay 4
#define button 12

bool canWash = true;
bool isFirstTime = true;

void wash(){
	digitalWrite(relay, canWash);
}

void setup(){
  	Serial.begin(9600);
  
	pinMode(relay, OUTPUT);
	pinMode(button, INPUT_PULLUP);
	pinMode(fiveVolts, OUTPUT);
  	digitalWrite(fiveVolts, HIGH);
}

void loop(){
  	// int humidity = map(analogRead(analog), 1023, 0, 0, 100);
  	// Serial.println(humidity);

  	if(isFirstTime){
    	wash();

	    isFirstTime = false;
  	}

  	if(!digitalRead(button)){
    	canWash = !canWash;

    	Serial.println(canWash);

	    wash();
    	delay(1000);
	}
}
