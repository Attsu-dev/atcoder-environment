#pragma once
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using PLL = pair<ll, ll>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using VD = vector<double>;
using VS = vector<string>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VPLL = vector<PLL>;
using VVPLL = vector<VPLL>;

#define rep(i, n) for (ll i = 0; i < ll(n); ++i)
#define rrep(i, n) for (ll i = ll(n) - 1; i >= 0; --i)
#define FOR(i, a, b) for (ll i = ll(a); i < ll(b); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 2e18;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

template <class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
  return is >> p.first >> p.second;
}
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  return os << p.first << " " << p.second;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& in : v) is >> in;
  return is;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++)
    os << v[i] << (i + 1 != (int)v.size() ? " " : "");
  return os;
}

void print() { cout << '\n'; }
void print(const auto& t) {
  cout << t << '\n';
}
void print(const auto& head, const auto&... tail) {
  cout << head << " ";
  print(tail...);
}
template <class T>
void println(const vector<T>& v) {
  for (const auto& row : v) print(row);
}

bool chmax(auto& a, auto b) {
  bool c = a < b;
  if (c) a = b;
  return c;
}
bool chmin(auto& a, auto b) {
  bool c = a > b;
  if (c) a = b;
  return c;
}

void YesNo(bool b) { cout << (b ? "Yes" : "No") << '\n'; }

auto _ = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);
  return 0;
}();
