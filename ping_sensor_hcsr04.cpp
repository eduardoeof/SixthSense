
#include "ping_sensor_hcsr04.h"

#include <Arduino.h>

PingSensorHCSR04::PingSensorHCSR04(int trigPin, int echoPin) : PingSensor(trigPin, echoPin) {
        // DOES NOTHING  
}

long PingSensorHCSR04::getDistance() {

	pinMode(_trigPin, OUTPUT);

	digitalWrite(_trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_trigPin, LOW);

	pinMode(_echoPin, INPUT);
	long d = pulseIn(_echoPin, HIGH)/58;

	// Erase delay accumulated
	_delayAccumulated = 0;

	return d;
}

