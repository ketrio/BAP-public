#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "tasks.h"

int main() {
  std::vector<std::string> coms = {"a1", "a2", "a3", "e", "i1",
                                   "i2", "i3", "i4", "i5"};
  std::vector<std::function<void()>> comsf = {a1, a2, a3, e, i1,
                                              i2, i3, i4, i5};
  std::string com;

  for (auto c : coms)
    std::cout << c << " " << std::endl;
  std::cout << ">>> ";
  std::cin >> com;
  if (find(coms.begin(), coms.end(), com) != coms.end()) {
    system("cls");
    comsf[find(coms.begin(), coms.end(), com) - coms.begin()]();
    std::cout << std::endl;
  }
}
