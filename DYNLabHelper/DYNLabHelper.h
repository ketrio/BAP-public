#pragma once

#ifdef DYNLabHelper_EXPORTS
#define DYNLabHelper_API __declspec(dllexport) 
#else
#define DYNLabHelper_API __declspec(dllimport) 
#endif

#include <utility>
#include <functional>

double DYNLabHelper_API m1(std::function<double(double)>, std::pair<double, double>, int);
double DYNLabHelper_API m2(std::function<double(double)>, std::pair<double, double>, int);
double DYNLabHelper_API m3(std::function<double(double)>, std::pair<double, double>, int);
