#pragma once
#include "base/template.hpp"

template <class T>
T knapsack(vector<T>& w, vector<T>& v, int W) {
  int N = w.size();

  vector<T> dp(W + 1);

  for (int i = 0; i < N; i++) {
    for (int j = W; j >= w[i]; j--) {
      chmax(dp[j], dp[j - w[i]] + v[i]);
    }
  }

  return *max_element(dp.begin(), dp.end());
}