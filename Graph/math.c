#include "includes.h"

double ln(double x) {
	x--;
	double res = 0;
	double temp = -1;
	for (int i = 1; i < 1e6; i++) {
		temp *= -x;
		res += temp/i;
	}
	return res;
}

double sin(double x) {
	x -= 6.28 * ((int)(x / 6.28));
	double res = x;
	double temp = x;
	for (int i = 3; i < 1e6; i+=2) {
		temp *= -((x*x) / (i*(i-1)));
		res += temp;
	}
	return res;
}

double exp(double x) {
	double res = 1;
	double temp = 1;
	for (int i = 1; i < 1e6; i++) {
		temp *= x / i;
		res += temp;
	}
	return res;
}