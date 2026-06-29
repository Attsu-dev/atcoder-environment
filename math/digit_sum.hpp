#pragma once
#include "base/template.hpp"

long long digit_sum(long long x) {
  assert(x >= 0);
  long long res = 0;
  while (x > 0) {
    res += x % 10;
    x /= 10;
  }
  return res;
}
