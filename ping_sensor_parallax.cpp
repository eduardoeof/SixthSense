
#include "ping_sensor_parallax.h"

#include <Arduino.h>

PingSensorParallax::PingSensorParallax(int trigEchoPin) : PingSensor(trigEchoPin) {
        // DOES NOTHING  
}

long PingSensorParallax::getDistance() {

	pinMode(_trigPin, OUTPUT);

	digitalWrite(_trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_trigPin, LOW);

	pinMode(_trigPin, INPUT);
	long d = pulseIn(_trigPin, HIGH)/58;

	// Erase delay accumulated
	_delayAccumulated = 0;

	return d;
}

