#include "STCLabHelper.h"
#include <cmath>

double integ1(double x)
{
	return sqrt(0.3*x*x + 2.3) / (1.8 + sqrt(2 * x + 1.6));
}
double integ2(double x)
{
	return cos(x*x + 0.6) / (1.2 + sin(0.7 * x + 0.2));
}
double integ3(double x)
{
	return 1 / sqrt(x * x + 0.5);
}
double integ4(double x)
{
	return cos(x) / (x + 2);
}
