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

template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  return is >> p.first >> p.second;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  return os << p.first << " " << p.second;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& in : v) is >> in;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++)
    os << v[i] << (i + 1 != (int)v.size() ? " " : "");
  return os;
}

void print() { cout << '\n'; }
template <typename T>
void print(const T& t) {
  cout << t << '\n';
}
template <typename Head, typename... Tail>
void print(const Head& head, const Tail&... tail) {
  cout << head << " ";
  print(tail...);
}
template <typename T>
void println(const vector<T>& v) {
  for (const auto& row : v) print(row);
}

template <typename T1, typename T2>
bool chmax(T1& a, T2 b) {
  bool c = a < b;
  if (c) a = b;
  return c;
}
template <typename T1, typename T2>
bool chmin(T1& a, T2 b) {
  bool c = a > b;
  if (c) a = b;
  return c;
}

void YesNo(bool b) { cout << (b ? "Yes" : "No") << '\n'; }

template <typename T>
vector<T> cumsum(const vector<T>& a) {
  int n = a.size();
  vector<T> s(n + 1, 0);
  for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
  return s;
}

auto _ = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);
  return 0;
}();