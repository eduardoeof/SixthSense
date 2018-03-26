
#include "ping_sensor.h"

#include <Arduino.h>

#define DELAY_TO_PING 250

PingSensor::PingSensor(int trigPin, int echoPin) {
	_trigPin = trigPin;
	_echoPin = echoPin;
	_distance = 0;

	// Start with max value to permit the capture of distance on the first time
	_delayAccumulated = DELAY_TO_PING;	
}

int PingSensor::isTimeToGetNewDistance() {

	if (_delayAccumulated >= DELAY_TO_PING) {
		return true;
	} else {
		return false;
	}
}

void PingSensor::incrementDelayAccumulated(int delay) {
	_delayAccumulated += delay;
}

