
#ifndef VIBRATOR_HEADER
#define VIBRATOR_HEADER

enum VibratorStatusEnum {
	VIBRATOR_STATUS_ACTIVATED,
	VIBRATOR_STATUS_DISACTIVATED
};

class Vibrator {

public:
	Vibrator(int pin);
	void activateVibration();
	void deactivateVibration();
	int isTimeToActivateVibration(int distance);
	int isTimeToDisactivateVibration();
	VibratorStatusEnum getStatus();
	void incrementDelayAccumulated(int delay);

private:
	int _pin;
	int _delayAccumulated;
	VibratorStatusEnum _status;
};

#endif
