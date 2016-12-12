#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <map>

template<typename K, typename V>
K dialog(std::string text, std::map<K, V> vars, bool show_vars = true, std::string aftertext = ": ", std::string separator = ", ")
{
	K ch;
	for (ch; vars.find(ch) == vars.end(); std::cin >> ch) {
		std::cout << text;
		if (show_vars) {
			for (auto i = vars.begin(); i != vars.end(); i++) {
				std::cout << (i != vars.begin() ? separator : aftertext) << i->first;
			}
			std::cout << std::endl;
		}
	}
	return ch;
}

int dialog(std::string, std::vector<std::string>, bool show_vars = true, std::string aftertext = ": ", std::string separator = ", ");

template<typename T>
T read()
{
	T x;
	std::cin >> x;
	return x;
}

struct Book
{
	int ISBN;
	std::string author;
	std::string title;
	int year;
	std::string publisher;
	int pages;
};

std::ostream& operator<<(std::ostream&, Book&);
std::istream& operator >> (std::istream&, Book&);

struct API {
	std::vector<Book> books;
	void init();
	void add(Book book);
	void add();
	void list();
	void find();
	void sort();
};
