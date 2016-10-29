#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "tasks.h"

int main() {
  std::vector<std::string> coms = {"a1", "a2", "e1", "e2",
                                   "e3", "e4", "i1", "i2"};
  std::vector<std::function<void()>> comsf = {a1, a2, e1, e2, e3, e4, i1, i2};
  std::string com;

  for (auto c : coms)
    std::cout << c << " " << std::endl;
  std::cout << ">>> ";
  std::cin >> com;
  if (find(coms.begin(), coms.end(), com) != coms.end())
    comsf[find(coms.begin(), coms.end(), com) - coms.begin()]();

  system("pause");
}
