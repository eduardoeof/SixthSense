
#ifndef PING_SENSOR_PARALLAX_HEADER
#define PING_SENSOR_PARALLAX_HEADER

#include "ping_sensor.h"

class PingSensorParallax : public PingSensor {

public:
        PingSensorParallax(int trigEchoPin);
	long getDistance();
};

#endif
