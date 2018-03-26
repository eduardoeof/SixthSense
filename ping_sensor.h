
#ifndef PING_SENSOR_HEADER
#define PING_SENSOR_HEADER

class PingSensor {

public:
	virtual long getDistance() = 0;
	
	PingSensor(int trigPin, int echoPin = 0);
	int isTimeToGetNewDistance();
	void incrementDelayAccumulated(int delay);

protected:
	int _trigPin;
	int _echoPin;
	int _distance;
	int _delayAccumulated;
};

#endif
