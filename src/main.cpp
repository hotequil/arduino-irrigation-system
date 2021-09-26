#include <Arduino.h>

#define analog A0
#define fiveVolts 2
#define relay 4

void setup(){
    Serial.begin(9600);
	
	pinMode(relay, OUTPUT);
	pinMode(fiveVolts, OUTPUT);
	digitalWrite(fiveVolts, HIGH);
}

void loop(){
	int result = map(analogRead(analog), 1023, 0, 0, 100);

	Serial.println('debug humidity result: ' + result);

	result >= 6 ? digitalWrite(relay, HIGH) : digitalWrite(relay, LOW);
}
