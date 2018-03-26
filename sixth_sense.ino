
#include "ping_sensor.h"
#include "ping_sensor_factory.h"
#include "vibrator.h"

#define PIN_PING_TRIG_1 7
#define PIN_PING_TRIG_2 6
#define PIN_PING_ECHO_2 5

#define PIN_VIBRATOR_1 8 
#define PIN_VIBRATOR_2 9 

#define DELAY_LOOP 50

#define NUMBER_PING_SENSORS 2
#define NUMBER_VIBRATORS    2

int distances[NUMBER_PING_SENSORS];
PingSensor * pings[NUMBER_PING_SENSORS];
Vibrator * vibras[NUMBER_VIBRATORS];

void setup() {
  
	Serial.begin(9600);

	// Init all sensors distances with zero
	for(int i = 0; i < NUMBER_PING_SENSORS; i++)
		distances[i] = 0;

 	PingSensorFactory factory;
	pings[0] = factory.create(PING_SENSOR_TYPE_PARALLAX, PIN_PING_TRIG_1);
	pings[1] = factory.create(PING_SENSOR_TYPE_HCSR04, PIN_PING_TRIG_2, PIN_PING_ECHO_2);

	vibras[0] = new Vibrator(PIN_VIBRATOR_1);
	vibras[1] = new Vibrator(PIN_VIBRATOR_2);
}

void loop() {

	for(int i = 0; i < NUMBER_PING_SENSORS; i++) {
		if (pings[i]->isTimeToGetNewDistance() == true)
			distances[i] = pings[i]->getDistance();
		
		pings[i]->incrementDelayAccumulated(DELAY_LOOP);
	}

	for(int i = 0; i < NUMBER_VIBRATORS; i++) {
		if (vibras[i]->getStatus() == VIBRATOR_STATUS_DISACTIVATED && 
		    vibras[i]->isTimeToActivateVibration(distances[i]) == true)
			vibras[i]->activateVibration();
		else if (vibras[i]->getStatus() == VIBRATOR_STATUS_ACTIVATED &&
			 vibras[i]->isTimeToDisactivateVibration() == true)
			vibras[i]->deactivateVibration();

		vibras[i]->incrementDelayAccumulated(DELAY_LOOP);
	}

	for(int i = 0; i < NUMBER_PING_SENSORS; i++) {
		Serial.print(i);
		Serial.print(":");
		Serial.print(distances[i]);
		Serial.print(" ");
	}
 	
        Serial.println(" ");
  
	delay(DELAY_LOOP);
}

