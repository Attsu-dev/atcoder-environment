#pragma once

// O(√n)
bool is_prime(long long n) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (long long p = 3; p * p <= n; p += 2) {
    if (n % p == 0) return false;
  }
  return true;
}
