
#include "ping_sensor_factory.h"

#include "ping_sensor_parallax.h"
#include "ping_sensor_hcsr04.h"

PingSensor * PingSensorFactory::create(PingSensorTypeEnum type, int trigPin, int echoPin) {

	if (type == PING_SENSOR_TYPE_PARALLAX)
		return new PingSensorParallax(trigPin);
	else if (type == PING_SENSOR_TYPE_HCSR04)
		return new PingSensorHCSR04(trigPin, echoPin);
	else
		return 0;	
}

