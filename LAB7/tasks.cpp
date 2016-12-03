#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <functional>
#include <regex>

#include "tasks.h"
#include <string>
#include <type_traits>
#include <map>

#define input(x, mes)                                                          \
  std::cout << mes << " = ";                                                   \
  std::cin >> x

void i1()
{
	std::string text;
	std::cin.seekg(0);
	getline(std::cin, text);

	std::smatch m;
	std::regex e ("[1-9][0-9]*\.?[0-9]*([Ee][+-]?[0-9]+)?");

	while (regex_search (text, m, e)) {
		for (auto x:m) std::cout << x << " ";
		std::cout << std::endl;
		text = m.suffix().str();
	}

}

bool filter(std::string str, int n)
{
	std::string consonants = "bcdfghjlmnpqrstvwx";

	if (str.size() != n)
		return false;

	bool flag = false;
	for (int i = 0; i < 18; i++)
		if (tolower(str[0]) == consonants[i])
			flag = true;

	if (flag == false)
		return false;

	return true;
}

void i2()
{
	std::cin.seekg(0);

	std::string text;
	std::cout << "Enter the text: ";
	getline(std::cin, text);

	int n;
	input(n, "n");

	std::string formated;

	std::istringstream buf(text);
	for (std::string word; buf >> word; ) 
		if (!filter(word, n)) formated += word + ' ';

	std::cout << "Formatted text: " << formated;
}

int int_length (int a) {
	int length = 0;

	do {
		++length;
		a /= 10;
	} while (a);

	return length;
}

char* itoc(int a) {
	int size = int_length(a);
	char *converted = new char[size];
	
	for (int i = 1; i <= size; i++)
		converted[size - i] = 48 + a % int(pow(10, i)) / pow(10, i - 1);

	return converted;
}

int getfrac(double a, int n) {
	return int(round(a*pow(10, n)));
}

char* dtoc(double a, int n) {
	int integer = int(a);
	int integerSize = int_length(integer);
	int fractionSize = n - integerSize - 1;
	int fraction = getfrac(a - int(a), fractionSize);

	char *answer = new char[n];
	int i = 0, j = 0;
	while (j < integerSize) {
		answer[i] = itoc(integer)[j];
		i++; j++;
	}

	answer[i] = '.';
	i++;

	j = 0;
	while (j < fractionSize) {
		answer[i] = itoc(fraction)[j];
		i++; j++;
	}

	return answer;
}

double ctod(char *a, int n) {
	double d = 0;
	int point_i = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == '.')
			point_i = i;

	int i = n - 1;
	while (i > point_i) {
		d += (a[i] - 48)*pow(0.1, i - point_i);
		i--;
	}
	i--;
	while (i >= 0) {
		d += (a[i] - 48)*pow(10, point_i - i - 1);
		i--;
	}

	return d;
}

void i3_1()
{
	int a;
	std::cout << "Your input: ";
	std::cin >> a;

	std::cout << "Output: "; 
	for (int i = 0; i < int_length(a); i++)
		std::cout << itoc(a)[i];
}

void i3_2()
{
	int size;
	std::cout << "Size of double: ";
	std::cin >> size;

	double d;
	std::cout << "Your input: ";
	std::cin >> d;

	std::cout << "Output: ";
	for(int i = 0; i < size; i++)
		std::cout << dtoc(d, size)[i];
}

void i3_3()
{
	int n;
	std::cout << "Size of double: ";
	std::cin >> n;

	char *line = new char[n];
	std::cout << "Your input: ";
	for (int i = 0; i < n; i++)
		std::cin >> line[i];

	std::cout << "Output: " << ctod(line, n);
}

void i3()
{
	std::cout << "List of functions:" << std::endl;
	std::cout << "1. int to string" << std::endl;
	std::cout << "2. double to string" << std::endl;
	std::cout << "3. string to double" << std::endl;

	int switcher;
	std::cout << "Your choice: "; std::cin >> switcher;
	std::map<int, std::function<void()>> list =  { {1, i3_1}, { 2, i3_2 }, { 3, i3_3 } };
	list[switcher]();
}

void a1()
{
	std::string str;
	std::cin.seekg(0);
	std::getline(std::cin, str);
	int n = str.size();

	for (int i = 0; i < n; i++)
		if (str[i] == 'c') {
			if (i == n - 1) str[i] = 'k';
			else if (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y') str[i] = 's';
			else str[i] = 'k';
		}
		else if (str[i] == 'q') {
			if (i == n - 1) str[i] = 'k';
			else if (str[i + 1] == 'u') {
				str[i] = 'k';
				str[i + 1] = 'v';
			}
		}
		else if (str[i] == 'x') {
			str[i] = 'k';
			str.insert(i, "s");
		}
		else if (str[i] == 'w') {
			str[i] = 'v';
		}
		else if (str.substr(i, 2) == "ph") {
			str[i] = 'f';
			str.erase(i + 1, 1);
			n--;
		}
		else if (str.substr(i, 2) == "oo") {
			str[i] = 'u';
			str.erase(i + 1, 1);
			n--;
		}
		else if (str.substr(i, 3) == "you") {
			str.erase(i, 2);
			n -= 2;
		}
		else if (str.substr(i, 3) == "ee") {
			str[i] = 'i';
			str.erase(i, 1);
			n--;
		}
		else if (str.substr(i, 2) == "th") {
			str[i] = 'u';
			str.erase(i, 1);
			n--;
		}
	
	for (int i = 0; i < n - 1; i++)
		if (str[i] == str[i + 1]) {
			str.erase(i, 1); 
			i--; n--;
		}
	std::cout << std::endl << str << std::endl;

}

std::string match(std::string mins, std::string maxs)
{
	std::string matched;
	int mins_len = mins.length();

	for( int i = 0; i < mins.length(); i++)
		if (mins.substr(i, mins_len - i) == maxs.substr(0, mins_len - i)) {
			maxs.erase(0, mins_len - i);
			break;
		}
	
	return mins + maxs;
}

void a2()
{
	int repeats;
	std::cin >> repeats;
	std::vector<int> answers;

	for(int ni = 0; ni < repeats; ni++) {
		int l, m;
		std::cin >> l;
		std::cin >> m;
		std::string s1;
		std::string s2;
		std::cin >> s1;
		std::cin >> s2;

		
		std::string matchs = s1.length() < s2.length() ? match(s2, s1) : match(s1, s2);
		if (matchs.length() > l)
			answers.push_back(0);
		else if (matchs.length() == l)
			answers.push_back(1);
		else
			answers.push_back((int(pow(26, l - matchs.length())) * 2) % m);
	}

	for (auto c : answers)
		std::cout << c << std::endl;
}

int fact (int a)
{
	return (a == 1 || a == 0) ? 1 : fact(a - 1) * a;
}

void a3()
{
	std::map<char, int> count;
	std::string line;
	input(line, "text");
	int div = fact(line.size());

	for (auto c : line) count[c]++;
	for (auto p : count) div /= fact(p.second);

	std::cout << div << std::endl;
}
