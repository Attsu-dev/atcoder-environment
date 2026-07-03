#pragma once
#include "base/template.hpp"

class LCA {
  int n, log;
  vector<vector<int>> parent;
  vector<int> depth;

public:
  LCA() : n(0), log(0) {}

  template <class Graph>
  LCA(const Graph& g, int root = 0) {
    init(g, root);
  }

  template <class Graph>
  void init(const Graph& g, int root = 0) {
    n = g.size();
    assert(0 <= root && root < n);

    log = 1;
    while ((1 << log) <= n) log++;

    parent.assign(log, vector<int>(n, -1));
    depth.assign(n, -1);

    queue<int> q;
    depth[root] = 0;
    q.push(root);

    while (!q.empty()) {
      int v = q.front();
      q.pop();

      for (auto e : g[v]) {
        int to = (int)e;
        if (to == parent[0][v]) continue;
        assert(depth[to] == -1);

        parent[0][to] = v;
        depth[to] = depth[v] + 1;
        q.push(to);
      }
    }

    for (int v = 0; v < n; v++) assert(depth[v] != -1);

    for (int k = 0; k + 1 < log; k++) {
      for (int v = 0; v < n; v++) {
        if (parent[k][v] == -1)
          parent[k + 1][v] = -1;
        else
          parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }

  int query(int u, int v) const {
    assert(0 <= u && u < n);
    assert(0 <= v && v < n);

    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for (int k = 0; k < log; k++) {
      if (diff >> k & 1) u = parent[k][u];
    }

    if (u == v) return u;

    for (int k = log - 1; k >= 0; k--) {
      if (parent[k][u] == parent[k][v]) continue;
      u = parent[k][u];
      v = parent[k][v];
    }

    return parent[0][u];
  }

  int dist(int u, int v) const {
    int w = query(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
  }

  int get_depth(int v) const {
    assert(0 <= v && v < n);
    return depth[v];
  }
};
