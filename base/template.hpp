#pragma once
// clang-format off
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using VLL = vector<ll>;
using VVLL = vector<vector<ll>>;
using VVVLL = vector<vector<vector<ll>>>;
using VD = vector<double>;
using VS = vector<string>;
using VB = vector<bool>;
using VVB = vector<vector<bool>>;
using PLL = pair<ll, ll>;
using VPLL = vector<pair<ll, ll>>;
using VVPLL = vector<vector<pair<ll, ll>>>;
#define rep(i, n) for (ll i = 0; i < ll(n); ++i)
#define rrep(i, n) for (ll i = ll(n) - 1; i >= 0; --i)
#define FOR(i, a, b) for (ll i = ll(a); i < ll(b); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const ll INF = 2e18;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
void print(const auto& x) { cout << x << '\n'; }
void printv(const auto& v) { for (int i = 0, n = v.size(); i < n; ++i) cout << v[i] << " \n"[i + 1 == n]; if (v.empty()) cout << '\n'; }
void printvv(const auto& vv) { for (const auto& v : vv) printv(v); }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << '\n'; }
bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }
bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }
// clang-format on
