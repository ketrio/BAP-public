#include "library.h"

#include <string>

int dialog(std::string text, std::vector<std::string> vars, bool show_vars, std::string aftertext, std::string separator)
{
	std::string ch;
	for (ch; std::find(vars.begin(), vars.end(), ch) == vars.end(); std::cin >> ch) {
		std::cout << text;
		if (show_vars) {
			for (unsigned int i = 0; i < vars.size(); i++) {
				std::cout << (i > 0 ? separator : aftertext) << vars[i];
			}
			std::cout << std::endl;
		}
	}
	return std::find(vars.begin(), vars.end(), ch) - vars.begin();
}

std::ostream& operator<<(std::ostream& os, Book& book)
{
	os << "ISBN >> " << book.ISBN << std::endl;
	os << "Author >> " << book.author << std::endl;
	os << "Original Title >> " << book.title << std::endl;
	os << "Publication Date >> " << book.year << std::endl;
	os << "Publisher >> " << book.publisher << std::endl;
	os << "Number of pages >> " << book.pages << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, Book& book)
{
	std::cout << "ISBN << ";
	is >> book.ISBN;
	std::cout << "Author << ";
	is.seekg(0);
	std::getline(is, book.author);
	std::cout << "Original Title << ";
	is.seekg(0);
	std::getline(is, book.title);
	std::cout << "Publication Date << ";
	is >> book.year;
	std::cout << "Publisher << ";
	is.seekg(0);
	std::getline(is, book.publisher);
	std::cout << "Number of pages << ";
	is >> book.pages;
	return is;
}

void API::init()
{
	books.clear();
	std::cout << "Enter books for library" << std::endl;
	do {
		add();
	} while (dialog("Wanna enter more? << ", std::vector<std::string>{ "no", "yes" }, false));
}

void API::add(Book book)
{
	books.push_back(book);
}

void API::add()
{
	add(read<Book>());
}

void API::list()
{
	for (size_t i = 0; i < books.size(); i++) std::cout << "book #" << i + 1 << ":" << std::endl << books[i] << std::endl;
}

void API::find()
{
	switch (dialog("Key", std::vector<std::string>{
		"ISNB",
		"author",
		"title",
		"year",
		"publisher",
		"pages"
	}))
	{
	case 0:
	{
		int value;
		std::cout << "ISNB << ";
		std::cin >> value;
		auto i = books.begin();
		while ((i = std::find_if(i, books.end(), [value](Book book) {
			return book.ISBN == value;
		})) != books.end()) {
			std::cout << *i << std::endl;
			i++;
		}
	}
	break;
	case 1:
	{
		std::string value;
		std::cout << "Author << ";
		std::cin.seekg(0);
		std::getline(std::cin, value);
		auto i = books.begin();
		while ((i = std::find_if(i, books.end(), [value](Book book) {
			return book.author == value;
		})) != books.end()) {
			std::cout << *i << std::endl;
			i++;
		}
	}
	break;
	case 2:
	{
		std::string value;
		std::cout << "Title << ";
		std::cin.seekg(0);
		std::getline(std::cin, value);
		auto i = books.begin();
		while ((i = std::find_if(i, books.end(), [value](Book book) {
			return book.title == value;
		})) != books.end()) {
			std::cout << *i << std::endl;
			i++;
		}
	}
	break;
	case 3:
	{
		int value;
		std::cout << "Year << ";
		std::cin >> value;
		auto i = books.begin();
		while ((i = std::find_if(i, books.end(), [value](Book book) {
			return book.year == value;
		})) != books.end()) {
			std::cout << *i << std::endl;
			i++;
		}
	}
	break;
	case 4:
	{
		std::string value;
		std::cout << "Publisher << ";
		std::cin.seekg(0);
		std::getline(std::cin, value);
		auto i = books.begin();
		while ((i = std::find_if(i, books.end(), [value](Book book) {
			return book.publisher == value;
		})) != books.end()) {
			std::cout << *i << std::endl;
			i++;
		}
	}
	break;
	case 5:
	{
		int value;
		std::cout << "Pages << ";
		std::cin >> value;
		auto i = books.begin();
		while ((i = std::find_if(i, books.end(), [value](Book book) {
			return book.pages == value;
		})) != books.end()) {
			std::cout << *i << std::endl;
			i++;
		}
	}
	break;
	}
	std::cout << "All occurrences displayed above" << std::endl;
}

void API::sort()
{
	switch (dialog("Key", std::vector<std::string>{
		"ISNB",
		"author",
		"title",
		"year",
		"publisher",
		"pages"
	}))
	{
	case 0:
		std::sort(books.begin(), books.end(), [](Book p1, Book p2) {
			return p1.ISBN < p2.ISBN;
		});
		break;
	case 1:
		std::sort(books.begin(), books.end(), [](Book p1, Book p2) {
			return p1.author < p2.author;
		});
		break;
	case 2:
		std::sort(books.begin(), books.end(), [](Book p1, Book p2) {
			return p1.title < p2.title;
		});
		break;
	case 3:
		std::sort(books.begin(), books.end(), [](Book p1, Book p2) {
			return p1.year < p2.year;
		});
		break;
	case 4:
		std::sort(books.begin(), books.end(), [](Book p1, Book p2) {
			return p1.publisher < p2.publisher;
		});
		break;
	case 5:
		std::sort(books.begin(), books.end(), [](Book p1, Book p2) {
			return p1.pages < p2.pages;
		});
		break;
	}
}
