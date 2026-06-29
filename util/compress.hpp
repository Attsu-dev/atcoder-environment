#pragma once
#include "base/template.hpp"

// 座標圧縮
template <class T>
struct Compress {
  vector<T> v;

  Compress(const vector<T>& V) : v(V) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
  }

  int size() { return v.size(); }

  int to(const T& x) {
    int i = lower_bound(v.begin(), v.end(), x) - v.begin();
    assert(i < size() && v[i] == x);
    return i;
  }

  T from(int x) {
    assert(0 <= x && x < (int)v.size());
    return v[x];
  }
};
