
#ifndef PING_SENSOR_FACTORY_HEADER
#define PING_SENSOR_FACTORY_HEADER

#include "ping_sensor.h"

enum PingSensorTypeEnum {
	PING_SENSOR_TYPE_PARALLAX,
	PING_SENSOR_TYPE_HCSR04
};

class PingSensorFactory {

public:
	PingSensor * create(PingSensorTypeEnum type, int trigPin, int echoPin = 0);
};

#endif

