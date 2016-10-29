#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

#include "tasks.h"

#define input(x, mes)                                                          \
  std::cout << mes << " = ";                                                   \
  std::cin >> x

std::string convert(std::string num, int from_n, int to_n) {
  int x = 0, i;
  std::string ans;

  for (i = num.length() - 1; i >= 0; i--)
    x += (isdigit(num[i]) ? int(num[i]) - '0' : int(num[i]) - 'A' + 10) *
         pow(from_n, num.size() - i - 1);

  while (x > 0) {
    i = x % to_n;
    ans = char(0 <= i && i <= 9 ? '0' + i : 'A' + i - 10) + ans;
    x /= to_n;
  }

  return ans;
}

int gcd(int u, int v) {
  int shl = 0;

  while (u && v && u != v) {
    bool eu = !(u & 1);
    bool ev = !(v & 1);

    if (eu && ev) {
      ++shl;
      u >>= 1;
      v >>= 1;
    } else if (eu && !ev)
      u >>= 1;
    else if (!eu && ev)
      v >>= 1;
    else if (u >= v)
      u = (u - v) >> 1;
    else {
      int tmp = u;
      u = (v - u) >> 1;
      v = tmp;
    }
  }

  return !u ? v << shl : u << shl;
}

void a1() {
  std::string x;

  input(x, "x");

  std::cout << convert(x, 12, 9) << std::endl;
}

void a2() {
  int x, num[] = {5, 29, 223};
  input(x, "x");
  for (auto a : num) {
    bool flag = x >= a && gcd(x, a) == a;
    std::cout << (flag ? "The number is divisible by "
                       : "The number isn't divisible by ")
              << a << std::endl;
  }
}

int minlvl(int lvl) { return int(pow(10, lvl - 1)); }

std::string maxlvl(int lvl, int nsys) {
  char key = (nsys > 10 ? int('A') + nsys - 11 : int('0') + nsys - 1);
  return std::string(lvl, key);
}

void e1() {
  std::cout << "a) MIN = " << minlvl(7) << "; MAX = " << maxlvl(7, 6)
            << std::endl;
  std::cout << "a) MIN = " << minlvl(2) << "; MAX = " << maxlvl(2, 16)
            << std::endl;
  std::cout << "a) MIN = " << minlvl(5) << "; MAX = " << maxlvl(5, 2)
            << std::endl;
}

bool exist(std::string a, int nsys) {
  for (auto x : a)
    if ((isdigit(x) && x > '0' + nsys) ||
        (x >= int("A") && x > int("A") + nsys - 10))
      return false;
  return true;
}

void e2() {
  std::vector<int> keys = {5, 8, 16};
  std::vector<std::vector<std::string>> nums = {{"701", "158", "46200"},
                                                {"14205", "100023", "4390"},
                                                {"1A2C", "96480", "AEC0"}};

  for (int i = 0; i < 3; i++)
    for (int i2 = 0; i2 < 3; i2++)
      std::cout << nums[i][i2] << " : " << keys[i] << " = "
                << exist(nums[i][i2], keys[i]) << std::endl;
}

void e3() {
  int nsys;

  input(nsys, "nsys");

  std::cout << convert(std::to_string(stoi(convert("1A9B16", nsys, 10)) +
                                      stoi(convert("52C316", nsys, 10))),
                       10, nsys)
            << std::endl;
}

void e4() {
  int nsys;

  input(nsys, "nsys");

  std::cout << convert(std::to_string(stoi(convert("CEA16", nsys, 10)) -
                                      stoi(convert("9EC16", nsys, 10))),
                       10, nsys)
            << std::endl;
}

void i1() {
  std::string x, x2;
  int n;
  input(n, "n");

  for (int i = 1;; i++) {
    x = convert(std::to_string(i), 10, 2);
    x2 = convert(x, 10, 2);

    if (x == x2.substr(x2.length() - x.length(), x.length()))
      n--;
    if (n == 0) {
      std::cout << x << std::endl;
      break;
    }
  }
}

void i2() {
  std::string k, ans;

  input(k, "k");

  ans = convert(k, 10, 3);
  for (int i = 0; i < k.length(); i++)
    k[i] = char(int(k[i]) - 47);

  std::cout << ans;
}
