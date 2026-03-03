#if !__INCLUDE_LEVEL__
#include <bits/stdc++.h>
#include __FILE__

void solve() {
  
}

int main() {
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

#else
#include <atcoder/all>
using namespace std;
using namespace atcoder;
struct Init {
  Init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(13);
  }
} init;
// clang-format off
using ll = long long;
using ull = unsigned long long;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using PLL = pair<ll, ll>;
using VS = vector<string>;
using VB = vector<bool>;
using VVB = vector<VB>;

#define rep(i, n) for (ll i = 0; i < ll(n); ++i)
#define FOR(i, a, b) for (ll i = ll(a); i < ll(b); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) x.rbegin(), x.rend()

const double PI = 3.141592653589793238;
const ll INF = 1LL << 60;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& in : v)
    is >> in;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++)
    os << v[i] << (i + 1 != (int)v.size() ? " " : "");
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  return is >> p.first >> p.second;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  return os << p.first << " " << p.second;
}

void print() { cout << '\n'; }
template <typename T>
void print(const T& t) { cout << t << '\n'; }
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
inline bool chmax(T1& a, T2 b) {
  bool c = a < b;
  if (c) a = b;
  return c;
}
template <typename T1, typename T2>
inline bool chmin(T1& a, T2 b) {
  bool c = a > b;
  if (c) a = b;
  return c;
}

void YesNo(bool b) {
  cout << (b ? "Yes" : "No") << endl;
}

template <typename T>
vector<T> cumsum(const vector<T>& a) {
  int n = a.size();
  vector<T> s(n + 1, 0);
  for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
  return s;
}

vector<vector<int>> read_graph(int N, int M, bool dir = false) {
  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    G[u].push_back(v);
    if (!dir) G[v].push_back(u);
  }
  return G;
}

#endif