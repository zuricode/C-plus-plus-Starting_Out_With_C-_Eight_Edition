#ifndef TEMPERATURE_H
#define TEMPERATURE_H

class Temperature {

private:

	float temp;

public:

	Temperature() { temp = 0; }

	void setTemp(float t) { temp = t; }
	const float getTemp() { return temp; }

	bool isEthylFreezing();
	bool isEthylBoiling();
	bool isOxygenFreezing();
	bool isOxygenBoiling();
	bool isWaterFreezing();
	bool isWaterBoiling();

};

#endif