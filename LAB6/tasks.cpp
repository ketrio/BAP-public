#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <functional>

#include "tasks.h"
#include "STCLabHelper.h"
#include "DYNLabHelper.h"

#define input(x, mes)                                                          \
  std::cout << mes << " = ";                                                   \
  std::cin >> x

int row_sum(std::vector<int> a) 
{
	int S = 0;
	for (auto e : a)
		S += e;
	return S;
}

int min_sum(std::vector<int> a)
{
	int min = a[0];
	for (auto e : a)
		min = std::min(e, min);
	return min;
}

void i1()
{
	int m, n;
	input(m, "m");
	input(n, "n");

	std::vector<std::vector<int>> A(m, std::vector<int>(n));
	std::vector<int> S;

	vector_in(A);
	for (auto row : A)
		S.push_back(row_sum(row));

	array_out(S);
	std::cout << min_sum(S);
}

bool positiv_cos(std::vector<double> a)
{
	int N = a.size();
	if (N == 1) return cos(a[0]) > 0;
	if (N == 2) return cos(a[0]) > 0 && cos(a[1]) > 0;

    return positiv_cos(std::vector<double>(a.begin(), a.begin() + N / 3)) &&
           positiv_cos(std::vector<double>(a.begin() + N / 3, a.end()));
}

void i2()
{
	int N;
	input(N, "N");

	std::vector<double> X(N);
	array_in(X);
	
	std::cout << (positiv_cos(X) ? "True" : "False");
}

void i3()
{
	std::vector<method_f> methods{ m1, m2, m3 };
	std::vector<integral_f> integrals{ integ1, integ2, integ3, integ4 };
	std::vector<limit_pair> limits{ { 1.6, 0.8 },{ 1.8, 0.5 },{ 2.4, 1.2 },{ 1.2, 0.4 } };

	int mchoice, ichoice, n;
	input(mchoice, "method");
	input(ichoice, "integral");
	input(n, "n");

	std::cout << "Answer = " << methods[mchoice - 1](integrals[ichoice - 1], limits[ichoice - 1], n);
}

void a1()
{
	int n, k;
	input(n, "n");
	input(k, "k");

	std::vector<std::vector<int>> A(n, std::vector<int>(k));
	std::vector<int> B;
	vector_in(A);

	int i = 0;
	while (i < std::min(n ,k)) {
		if (A[i][i] % 2 == 0)
			B.push_back(A[i][i]);
		i++;
	}

	array_out(B);

	int prod = B[0];
	for (i = 1; i < B.size(); i++)
		prod *= B[i];
	std::cout << "Product = " << prod;
}

void backward_out(std::vector<std::vector<int>> A)
{
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++)
			std::cout << A[j][i] << " ";
		std::cout << std::endl;
	}
}

void a2()
{
	int n, k;
	input(n, "n");
	input(k, "k");

	std::vector<std::vector<int>> A(n, std::vector<int>(k));
	std::vector<std::pair<int, int>> indexes;
	vector_in(A);

	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			if(A[i][j] == 0) {
				sum++;
				indexes.push_back({ i, j });
			}

	backward_out(A);
	std::cout << "sum " << sum << std::endl;;
	for (int i = 0; i < indexes.size(); i++)
		std::cout << "{ " << indexes[i].first << ", " << indexes[i].second << " }, ";
}

double vector_avg(std::vector<int> A)
{
	int sum = 0;
	for (auto e : A)
		sum += e;
	return sum / A.size();
}

void a3()
{
	int n, k;
	input(n, "n");
	input(k, "k");

	std::vector<std::vector<int>> A(n, std::vector<int>(k));
	std::vector<int> B;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j += 2)
			if (A[i][j] % 2 == 1)
				B.push_back(A[i][j]);

	std::cout << "avg = " << vector_avg(B) << std::endl;
}

int e1F(int n)
{
	if (n % 10 > 0)
		return n % 10;
	if (n == 0)
		return 0;
	return e1F(n / 10);
}

void e1()
{
	int p, q;
	input(p, "p");
	input(q, "q");

	if (p > 0 && q > 0) {
		int sum = 0;
		for (int i = p; i <= q; i++)
			sum += e1F(i);

		std::cout << sum;
	}
}

int e2F(int n, int r, int k)
{
	if (r == 0)
		return 1;
	if ( n > 0 && (0 <= r) && r < (n*(k - 1) + 1) ) {
		int sum = 0;
		for (int i = 0; i < k; i++)
			sum += e2F(n - 1, r - i, k);
		return sum;
	}
	return 0;
}

void e2()
{
	int k, n, t;
	input(k, "k");
	input(n, "n");
	input(t, "t");

	int sum = 0;
	for (int i = 0; i <= n*(k - 1); i++)
		sum += e2F(n, i, k);
	int x = sum % int(pow(10, t));

	std::cout << "x = " << x;
}

int e3F(int n)
{
	while (n % 2 == 0) n /= 2;
	return n;
}

void e3()
{
	int n;
	input(n, "n");

	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += e3F(i);

	std::cout << "sum = " << sum;
}
