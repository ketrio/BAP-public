#pragma once

#include <iomanip>

typedef std::function<double(std::function<double(double)>, std::pair<double, double>, int)> method_f;
typedef std::function<double(double)> integral_f;
typedef std::pair<double, double> limit_pair;

void i1();
void i2();
void i3();
void a1();
void a2();
void a3();
void e1();
void e2();
void e3();

template <typename T>
void vector_in(std::vector<std::vector<T>>& a)
{
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[0].size(); j++)
			std::cin >> a[i][j];
}

template <typename T>
void vector_out(std::vector<std::vector<T>> a)
{
	for (auto row : a) {
		for (auto e : row)
			std::cout << std::setw(4) << e;
		std::cout << std::endl;
	}
}

template <typename T>
void array_in(std::vector<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		std::cin >> a[i];
}

template <typename T>
void array_out(std::vector<T> a)
{
	std::cout << "{ ";
	for (auto e : a)
		std::cout << e << " ";
	std::cout << "}" << std::endl;
}
