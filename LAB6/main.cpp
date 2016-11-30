#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "tasks.h"

int main() {
	std::map<std::string, std::function<void()>> coms {
		{ "i1", i1 },{ "i2", i2 },{ "i3", i3 },{ "a1", a1 },{ "a2", a2 },
		{ "a3", a3 },{ "e1", e1 },{ "e2", e2 },{ "e3", e3 } };
	std::string com;

	for (auto c : coms)
		std::cout << c.first << " " << std::endl;
	std::cout << ">>> ";
	std::cin >> com;
	if (coms.find(com) != coms.end()) {
		system("cls");
		coms[com]();
		std::cout << std::endl;
	}
	
	system("pause");
}
