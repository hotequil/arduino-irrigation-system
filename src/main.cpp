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
	int result = analogRead(analog);

	Serial.println(result);

	result < 900 ? digitalWrite(relay, HIGH) : digitalWrite(relay, LOW);
}
