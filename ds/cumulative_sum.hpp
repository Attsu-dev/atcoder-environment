#pragma once
#include "base/template.hpp"

// s[i] = a[0] + a[1] + ... + a[i - 1] となる累積和を返す。
template <class T>
vector<T> cumsum(const vector<T>& a) {
  int n = a.size();
  vector<T> s(n + 1, T{});
  for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
  return s;
}
