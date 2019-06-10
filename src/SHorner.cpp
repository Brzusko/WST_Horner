#include "SHorner.h"
#include <iostream>
#include <cmath>

float Horner(float* tab, int size, float argument) {
	float retunValue = 0;
	for (int i = 0; i < size; i++)
		retunValue = tab[i] + retunValue * argument;
	return retunValue;
}

float Piechota(float* tab, int size, float argument) {
	float returnValue = 0.0f;
	int index = 0;
	for (int i = size - 1; i >= 0; i--) {
		float helper = tab[index] * PowerValue(argument, i);
		returnValue = returnValue + helper;
		index++;
	}
	return returnValue;
}

float PowerValue(float valToPower, int valHowManyPowers) {
	float returnValue = 1;
	if (valHowManyPowers <= 0.0)
		return 1.0f;
	for (int i = 0; i < valHowManyPowers; i++) {
		returnValue = returnValue * valToPower;
	}
	return returnValue;
}