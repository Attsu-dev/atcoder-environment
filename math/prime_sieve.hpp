#pragma once
#include "base/template.hpp"

// 線形篩：O(n)
class PrimeSieve {
  int n;
  vector<int> min_factor_list;
  vector<int> prime_list;

public:
  PrimeSieve(int n = 0) { init(n); }

  void init(int n) {
    assert(n >= 0);
    this->n = n;
    min_factor_list.assign(n + 1, 0);
    prime_list.clear();

    for (int i = 2; i <= n; i++) {
      if (min_factor_list[i] == 0) {
        min_factor_list[i] = i;
        prime_list.emplace_back(i);
      }
      for (int p : prime_list) {
        if (p > min_factor_list[i] || 1LL * i * p > n) break;
        min_factor_list[i * p] = p;
      }
    }
  }

  int size() const { return n; }

  const vector<int>& primes() const { return prime_list; }

  int min_factor(int x) const {
    assert(0 <= x && x <= n);
    return min_factor_list[x];
  }

  bool is_prime(int x) const {
    assert(0 <= x && x <= n);
    return x >= 2 && min_factor_list[x] == x;
  }

  vector<pair<int, int>> factorize(int x) const {
    assert(1 <= x && x <= n);
    vector<pair<int, int>> res;
    while (x > 1) {
      int p = min_factor_list[x];
      int cnt = 0;
      while (x % p == 0) {
        x /= p;
        cnt++;
      }
      res.emplace_back(p, cnt);
    }
    return res;
  }
};
