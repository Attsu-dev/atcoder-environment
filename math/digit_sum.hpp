#pragma once

long long digit_sum(long long x) {
  long long res = 0;
  if (x < 0) x = -x;
  while (x > 0) {
    res += x % 10;
    x /= 10;
  }
  return res;
}
