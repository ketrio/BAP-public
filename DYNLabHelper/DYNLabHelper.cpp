#include "DYNLabHelper.h"
#include <utility>
#include <functional>

double m1(std::function<double(double)> integral, std::pair<double, double> limits, int n)
{
	double a = limits.first;
	double b = limits.second;
	double h = (b - a) / n, sum = 0;

	for (int i = 0; i < n; i++)
		sum += integral(a + h*i);

	return sum;
}
double m2(std::function<double(double)> integral, std::pair<double, double> limits, int n)
{
	double a = limits.first;
	double b = limits.second;
	double h = (b - a) / n, sum = 0;

	for (int i = 1; i <= n; i++)
		sum += integral(a + h*i);

	return sum;
}
double m3(std::function<double(double)> integral, std::pair<double, double> limits, int n)
{
	double a = limits.first;
	double b = limits.second;
	double h = (b - a) / n, sum = 0;

	for (int i = 0; i < n; i++)
		sum += integral(a + h*i + h / 2);

	return sum;
}
