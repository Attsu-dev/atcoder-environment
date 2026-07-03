import random
import sys


def main():
    seed = int(sys.argv[1]) if len(sys.argv) >= 2 else random.randrange(1 << 60)
    random.seed(seed)

    # ここを問題に合わせて書き換える。小さい制約で naive と比較するとよい。

    # N と配列
    n = random.randint(1, 10)
    a = [random.randint(0, 20) for _ in range(n)]
    print(n)
    print(*a)

    # 複数テストケース:
    # t = random.randint(1, 5)
    # print(t)
    # for _ in range(t):
    #     n = random.randint(1, 10)
    #     a = [random.randint(0, 20) for _ in range(n)]
    #     print(n)
    #     print(*a)

    # 順列:
    # n = random.randint(1, 10)
    # p = list(range(1, n + 1))
    # random.shuffle(p)
    # print(n)
    # print(*p)

    # 重複なし:
    # n = random.randint(1, 10)
    # a = random.sample(range(0, 21), n)
    # print(n)
    # print(*a)

    # 文字列:
    # n = random.randint(1, 20)
    # s = "".join(random.choice("abc") for _ in range(n))
    # print(n)
    # print(s)

    # 区間 [l, r]:
    # n = random.randint(1, 10)
    # print(n)
    # for _ in range(n):
    #     l = random.randint(0, 20)
    #     r = random.randint(0, 20)
    #     if l > r:
    #         l, r = r, l
    #     print(l, r)

    # グリッド:
    # h = random.randint(1, 8)
    # w = random.randint(1, 8)
    # grid = ["".join(random.choice(".#") for _ in range(w)) for _ in range(h)]
    # print(h, w)
    # for row in grid:
    #     print(row)

    # S, G 付きグリッド:
    # h = random.randint(2, 8)
    # w = random.randint(2, 8)
    # grid = gen_grid_with_start_goal(h, w, wall_prob=0.25)
    # print(h, w)
    # for row in grid:
    #     print(row)

    # 木:
    # n = random.randint(1, 10)
    # edges = gen_tree(n)
    # print(n)
    # for a, b in edges:
    #     print(a, b)

    # 重み付き連結グラフ:
    # n = random.randint(2, 10)
    # m = random.randint(n - 1, min(20, n * (n - 1) // 2))
    # edges = gen_connected_graph(n, m)
    # print(n, m)
    # for a, b in edges:
    #     w = random.randint(1, 20)
    #     print(a, b, w)

    # クエリ:
    # n = random.randint(1, 10)
    # q = random.randint(1, 20)
    # a = [random.randint(0, 20) for _ in range(n)]
    # print(n, q)
    # print(*a)
    # for _ in range(q):
    #     t = random.randint(1, 2)
    #     if t == 1:
    #         i = random.randint(1, n)
    #         x = random.randint(0, 20)
    #         print(1, i, x)
    #     else:
    #         l = random.randint(1, n)
    #         r = random.randint(l, n)
    #         print(2, l, r)

    # 端ケース混ぜ:
    # mode = random.randint(0, 4)
    # if mode == 0:
    #     n = 1
    #     a = [0]
    # elif mode == 1:
    #     n = 10
    #     a = [0] * n
    # elif mode == 2:
    #     n = 10
    #     a = list(range(n))
    # elif mode == 3:
    #     n = 10
    #     a = list(range(n, 0, -1))
    # else:
    #     n = random.randint(1, 10)
    #     a = [random.randint(0, 20) for _ in range(n)]
    # print(n)
    # print(*a)


def gen_grid_with_start_goal(h, w, wall_prob=0.25):
    """S, G を 1 個ずつ置いたグリッド。到達可能性は保証しない。"""
    assert h * w >= 2
    grid = []
    for _ in range(h):
        row = []
        for _ in range(w):
            row.append("#" if random.random() < wall_prob else ".")
        grid.append(row)

    si, sj = random.randrange(h), random.randrange(w)
    gi, gj = random.randrange(h), random.randrange(w)
    while (gi, gj) == (si, sj):
        gi, gj = random.randrange(h), random.randrange(w)

    grid[si][sj] = "S"
    grid[gi][gj] = "G"
    return ["".join(row) for row in grid]


def gen_tree(n, one_indexed=True):
    """n 頂点の木。各 v を 0..v-1 のどれかにつなぐので必ず連結。"""
    edges = []
    for v in range(1, n):
        p = random.randrange(v)
        edges.append((p, v))
    if one_indexed:
        edges = [(a + 1, b + 1) for a, b in edges]
    random.shuffle(edges)
    return edges


def gen_graph(n, m, directed=False, self_loop=False, multi_edge=False, one_indexed=True):
    """一般グラフ。単純グラフ指定なら作れない m を assert で弾く。"""
    if not multi_edge:
        if directed:
            max_m = n * n if self_loop else n * (n - 1)
        else:
            max_m = n * (n - 1) // 2 + (n if self_loop else 0)
        assert m <= max_m

    edges = []
    used = set()
    while len(edges) < m:
        a = random.randrange(n)
        b = random.randrange(n)
        if not self_loop and a == b:
            continue

        key = (a, b) if directed else (min(a, b), max(a, b))
        if not multi_edge and key in used:
            continue

        used.add(key)
        edges.append((a, b))

    if one_indexed:
        edges = [(a + 1, b + 1) for a, b in edges]
    return edges


def gen_connected_graph(n, m, one_indexed=True):
    """連結な無向単純グラフ。m >= n - 1 が必要。"""
    assert m >= n - 1
    assert m <= n * (n - 1) // 2

    edges = [(a - 1, b - 1) for a, b in gen_tree(n, one_indexed=True)]
    used = {(min(a, b), max(a, b)) for a, b in edges}

    while len(edges) < m:
        a = random.randrange(n)
        b = random.randrange(n)
        if a == b:
            continue
        key = (min(a, b), max(a, b))
        if key in used:
            continue
        used.add(key)
        edges.append((a, b))

    random.shuffle(edges)
    if one_indexed:
        edges = [(a + 1, b + 1) for a, b in edges]
    return edges


def gen_dag(n, m, one_indexed=True):
    """DAG。小さい番号から大きい番号へ辺を張る。"""
    assert n >= 1
    assert m <= n * (n - 1) // 2
    edges = set()
    while len(edges) < m:
        a = random.randrange(n - 1)
        b = random.randrange(a + 1, n)
        edges.add((a, b))

    edges = list(edges)
    random.shuffle(edges)
    if one_indexed:
        edges = [(a + 1, b + 1) for a, b in edges]
    return edges


if __name__ == "__main__":
    main()
