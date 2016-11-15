#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>

#include "tasks.h"

#define input(x, mes)                                                          \
  std::cout << mes << " = ";                                                   \
  std::cin >> x

std::vector<int> del_mxn(std::vector<int>& a) {
	int mini = 0, maxi = 0, min = a[0], max = a[0];

	for (int i = 0; i < a.size(); i++) {
		if (a[i] > max) {
			max = a[i];
			maxi = i;
		}
		if (a[i] < min) {
			min = a[i];
			mini = i;
		}
	}

	a.erase(a.begin() + mini);
	a.erase(a.begin() + maxi - 1);

	return a;
}

int min_detect(std::vector<std::vector<int>> a)
{
	int min = a[0][1];
	for (int x = 1; x < a.size(); x++)
		for (int y = 0; y < x; y++)
			min = std::min(min, a[y][x]);
	
	return min;
}

int prod_mx(std::vector<float> a, std::vector<float> b)
{
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
		sum += a[i] * b[i];

	return sum;
}


bool check_mx(std::vector<std::vector<float>> a){
	for (int x = 1; x < a.size(); x++)
		for (int y = 0; y <= x; y++)
			if (prod_mx(a[x], a[y]) != (x == y))
				return false;

	return true;
}

int magic(std::vector<std::vector<int>>& a)
{
	int n = a.size();
	int i = n / 2;
	int j = n - 1;

	for (int num = 1; num <= n*n; ) {
		if (i == -1 && j == n) {
			j = n - 2;
			i = 0;
		}
		else {
			if (j == n) j = 0;
			if (i < 0) i = n - 1;
		}
		if (!a[i][j]) a[i][j] = num++;
		else {
			j -= 2;
			i++;
			continue;
		}

		j++;  i--;
	}

	return 1;
}

std::vector<std::vector<int>> spiral(std::vector<std::vector<int>> a)
{
	int s = a.size();
	int l, i = 0, k = 0, g = 1;

	while (i < s*s)
	{
		k++;
		for (l = k - 1; l < s - k + 1; l++){
			a[k - 1][l] = g++;
			i++;
		}
		for (l = k; l < s - k + 1; l++){
			a[l][s - k] = g++;
			i++;
		}
		for (l = s - k - 1; l >= k - 1; l--){
			a[s - k][l] = g++;
			i++;
		}
		for (l = s - k - 1; l >= k; l--){
			a[l][k - 1] = g++;
			i++;
		}
	}

	return a;
}

int sort_triag(std::vector<std::vector<int>>& a)
{
	int n = a.size();
	std::vector<int> elements;

	for (int row = 0; row < n; row++) for (int col = 0; col < n - row; col++)
		elements.push_back(a[row][col]);

	std::sort(elements.begin(), elements.end());

	for (int row = 0; row < n; row++) for (int col = 0; col < n - row; col++) {
		a[row][col] = elements[0];
		elements.erase(elements.begin());
	}

	return 1;
}

std::vector<std::vector<int>> det_max (std::vector<std::vector<int>> a)
{
	std::vector<std::vector<int>> b(a.size(), std::vector<int>(a[0].size()));
	for (int row = 0; row < a.size(); row++) for (int col = 0; col < a[0].size(); col++) {
		int max = a[0][0];
		for (int y = 0; y <= row; y++)
			for (int x = 0; x <= col; x++)
				max = std::max(max, a[y][x]);
		b[row][col] = max;
	}


	return b;
}

void a1() {
	int k;
	input(k, "k");

	std::vector<int> arr(k);

	for (int i = 0; i < k; i++)
		std::cin >> arr[i];

	del_mxn(arr);
	for (auto e : arr)
		std::cout << e << " ";
}

void a2() {
	int m;
	input(m, "M");

	std::vector<std::vector<int>> arr(m, std::vector<int>(m));

	vector_in(arr);

	std::cout << min_detect(arr);
}

void a3()
{
	int n;
	input(n, "N");

	std::vector<std::vector<float>> mtrx(n, std::vector<float>(n));
	vector_in(mtrx);

	std::cout << "The matrix is" << (check_mx(mtrx)?" ":"n't ") << "orthonormal.";
}

void e()
{
	float max;
	int n, max_x = 0, max_y = 0;
	input(n, "n");

	std::vector<std::vector<float>> mtrx(n, std::vector<float>(n));
	vector_in(mtrx);
	std::cout << std::endl;

	max = mtrx[0][0];
	for(int y = 0; y < n; y++)
		for(int x = 0; x < n; x++)
			if(abs(mtrx[y][x]) > max){
				max_x = x;
				max_y = y;
				max = abs(mtrx[y][x]);
			}

	mtrx.erase(mtrx.begin() + max_y);
	for (int i = 0; i < mtrx.size(); i++)
		mtrx[i].erase(mtrx[i].begin() + max_x);

	vector_out(mtrx);
}
void i1()
{
	int n, m;
	input(n, "N");
	input(m, "M");

	std::vector<std::vector<float>> mtrx(n, std::vector<float>(m));
	std::map<float, int> list;

	vector_in(mtrx);
	std::cout << std::endl;

	for (auto row : mtrx) for (auto e : row)
			list[e] += 1;

	std::vector<std::vector<float>> b;

	for (auto i : list) {
		std::vector<float> temp(i.second);
		for (int x = 0; x < i.second; x++)
			temp[x] = i.first;
		b.push_back(temp);
	}

	vector_out(b);
}
void i2()
{
	int n;
	input(n, "n");

	std::vector<std::vector<int>> mag_square(n, std::vector<int> (n));

	magic(mag_square);

	std::cout << "Sum of each row or column : " <<  n*(n*n + 1)/2 << std::endl;
	vector_out(mag_square);
}
void i3(){
	int n;
	input(n, "n");

	std::vector<std::vector<int>> mtrx(n, std::vector<int>(n));

	mtrx = spiral(mtrx);

	vector_out(mtrx);
}
void i4()
{
	int n;
	input(n, "N");

	std::vector<std::vector<int>> mtrx(n, std::vector<int>(n));
	vector_in(mtrx);

	sort_triag(mtrx);

	vector_out(mtrx);
}
void i5()
{
	int n, m;
	input(n, "N");
	input(m, "M");

	std::vector<std::vector<int>> mtrx(n, std::vector<int>(m));
	std::vector<std::vector<int>> b(n, std::vector<int>(m));

	vector_in(mtrx);

	b = det_max(mtrx);

	vector_out(b);
}
