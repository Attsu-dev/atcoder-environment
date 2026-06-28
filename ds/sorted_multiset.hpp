#pragma once
#include <atcoder/fenwicktree>
using namespace atcoder;
#include "base/template.hpp"

class SortedMultiSet {
  int MAX, sz;
  fenwick_tree<int> fw;
  vector<int> cnt;

 public:
  SortedMultiSet(int MAX) : MAX(MAX), sz(0), fw(MAX), cnt(MAX, 0) {}

  int count(int x) { return cnt[x]; }

  int size() { return sz; }

  void add(int x) {
    cnt[x]++;
    fw.add(x, 1);
    sz++;
  }

  bool erase(int x) {
    if (cnt[x] == 0) return false;
    cnt[x]--;
    fw.add(x, -1);
    sz--;
    return true;
  }

  bool erase_all(int x) {
    if (cnt[x] == 0) return false;
    fw.add(x, -cnt[x]);
    sz -= cnt[x];
    cnt[x] = 0;
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