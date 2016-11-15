#pragma once

#include <iomanip>

void a1();
void a2();
void a3();
void e();
void i1();
void i2();
void i3();
void i4();
void i5();

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