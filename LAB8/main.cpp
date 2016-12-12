#include <map>
#include <functional>

#include "library.h"

int main()
{
	API api;
	api.init();
	std::map<std::string, std::function<void()>> coms{
		{ "init", std::bind(&API::init, &api) },
		{ "add", std::bind(static_cast<void(API::*)(void)>(&API::add), &api) },
		{ "list", std::bind(&API::list, &api) },
		{ "find", std::bind(&API::find, &api) },
		{ "sort", std::bind(&API::sort, &api) },
		{ "push", []() { std::cout << "pull" << std::endl; } },
		{ "exit", nullptr }
	};

	for (std::string com; (com = dialog("Task", coms)) != "exit";) coms[com](); //// 33.0.pxe.e3xxe.pxe-0
}
