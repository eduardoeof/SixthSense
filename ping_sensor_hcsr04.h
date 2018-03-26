
#ifndef PING_SENSOR_HCSR04_HEADER
#define PING_SENSOR_HCSR04_HEADER

#include "ping_sensor.h"

class PingSensorHCSR04 : public PingSensor {

public:
        PingSensorHCSR04(int trigPin, int echoPin);
	long getDistance();
};

#endif
