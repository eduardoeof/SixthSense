
#include "vibrator.h"

#include <Arduino.h>

#define DISTANCE_10 300
#define DISTANCE_9  250
#define DISTANCE_8  200
#define DISTANCE_7  150
#define DISTANCE_6  100
#define DISTANCE_5  90
#define DISTANCE_4  80
#define DISTANCE_3  70
#define DISTANCE_2  60
#define DISTANCE_1  50

#define DELAY_TO_DISTANCE_10 2000
#define DELAY_TO_DISTANCE_9  1500
#define DELAY_TO_DISTANCE_8  1000
#define DELAY_TO_DISTANCE_7   750
#define DELAY_TO_DISTANCE_6   500
#define DELAY_TO_DISTANCE_5   400
#define DELAY_TO_DISTANCE_4   300
#define DELAY_TO_DISTANCE_3   200
#define DELAY_TO_DISTANCE_2   100
#define DELAY_TO_DISTANCE_1     0

#define DELAY_DESACTIVATED    100

Vibrator::Vibrator(int pin){

	_pin = pin;
	_delayAccumulated = 0;
	_status = VIBRATOR_STATUS_DISACTIVATED;

	pinMode(_pin, OUTPUT);
}

int Vibrator::isTimeToActivateVibration(int distance) {
    
	if (_status == VIBRATOR_STATUS_DISACTIVATED &&
	    (distance >= DISTANCE_10 && _delayAccumulated >= DELAY_TO_DISTANCE_10 ||
             distance >= DISTANCE_9 && distance < DISTANCE_1 &&
	  	 _delayAccumulated >= DELAY_TO_DISTANCE_9 ||
	     distance >= DISTANCE_8 && distance < DISTANCE_9 &&
	 	 _delayAccumulated >= DELAY_TO_DISTANCE_8 ||
	     distance >= DISTANCE_7 && distance < DISTANCE_8 &&
		 _delayAccumulated >= DELAY_TO_DISTANCE_7 ||
	     distance >= DISTANCE_6 && distance < DISTANCE_7 &&
		 _delayAccumulated >= DELAY_TO_DISTANCE_6 ||
	     distance >= DISTANCE_5 && distance < DISTANCE_6 &&
		 _delayAccumulated >= DELAY_TO_DISTANCE_5 ||
	     distance >= DISTANCE_4 && distance < DISTANCE_5 &&
		 _delayAccumulated >= DELAY_TO_DISTANCE_4 ||
	     distance >= DISTANCE_3 && distance < DISTANCE_4 &&
		 _delayAccumulated >= DELAY_TO_DISTANCE_3 ||
	     distance >= DISTANCE_2 && distance < DISTANCE_3 &&
		 _delayAccumulated >= DELAY_TO_DISTANCE_2 ||
	     distance >= DISTANCE_1 && distance < DISTANCE_2 &&
		 _delayAccumulated >= DELAY_TO_DISTANCE_1 ||
	     distance <  DISTANCE_1))
		return true;
	else
		return false;
}

int Vibrator::isTimeToDisactivateVibration() {

	if (_status == VIBRATOR_STATUS_ACTIVATED && _delayAccumulated >= DELAY_DESACTIVATED)
		return true;
	else
		return false;
}

void Vibrator::activateVibration() {
 
	digitalWrite(_pin, LOW);
	delayMicroseconds(5);
	digitalWrite(_pin, HIGH);
	delayMicroseconds(5);
	
	_status = VIBRATOR_STATUS_ACTIVATED;
	_delayAccumulated = 0;
}

void Vibrator::deactivateVibration() {

	digitalWrite(_pin, LOW); 
	delayMicroseconds(5);

	_status = VIBRATOR_STATUS_DISACTIVATED;
	_delayAccumulated = 0;
}

VibratorStatusEnum Vibrator::getStatus() {
	return _status;
}

void Vibrator::incrementDelayAccumulated(int delay) {
	_delayAccumulated += delay;
}

