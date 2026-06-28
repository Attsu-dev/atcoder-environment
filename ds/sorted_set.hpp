#pragma once
#include <atcoder/fenwicktree>
using namespace atcoder;
#include "base/template.hpp"

class SortedSet {
  int MAX, sz;
  fenwick_tree<int> fw;
  vector<bool> exists;

 public:
  SortedSet(int MAX) : MAX(MAX), sz(0), fw(MAX), exists(MAX, false) {}

  bool contains(int x) { return exists[x]; }

  int size() { return sz; }

  bool add(int x) {
    if (exists[x]) return false;
    exists[x] = true;
    fw.add(x, 1);
    sz++;
    return true;
  }

  bool erase(int x) {
    if (!exists[x]) return false;
    exists[x] = false;
    fw.add(x, -1);
    sz--;
    return true;
  }

  int operator[](int k) {
    int l = -1, r = MAX;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (fw.sum(0, m + 1) > k)
        r = m;
      else
        l = m;
    }
    return r;
  }

  int order(int x) { return fw.sum(0, x); }
};