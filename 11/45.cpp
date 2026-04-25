//https://codeforces.com/contest/2222/problem/F
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<tuple<int,int,int>> edges(m);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = {u, v, w};
        }
        vector<int> c(q);
        for (int i = 0; i < q; ++i) cin >> c[i];
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        int q_prime = c.size();
        vector<int> s_comp_init(n + 1, -1);
        for (int i = 0; i < q_prime; ++i) s_comp_init[c[i]] = i;
        vector<int> full_p(n + 1), full_sz(n + 1, 1);
        iota(full_p.begin(), full_p.end(), 0);
        function<int(int)> full_find = [&](int x) {
            while (full_p[x] != x) {
                full_p[x] = full_p[full_p[x]];
                x = full_p[x];
            }
            return x;
        };
        auto full_union = [&](int u, int v) {
            u = full_find(u); v = full_find(v);
            if (u == v) return;
            if (full_sz[u] < full_sz[v]) swap(u, v);
            full_p[v] = u;
            full_sz[u] += full_sz[v];
        };
        for (auto &[u, v, w] : edges) full_union(u, v);
        bool possible = true;
        int root = full_find(c[0]);
        for (int i = 1; i < q_prime; ++i) {
            if (full_find(c[i]) != root) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            cout << -1 << '\n';
            continue;
        }

        set<int> ws;
        for (auto &[u, v, w] : edges) ws.insert(w);
        int M = 0;
        while (ws.count(M)) ++M;

        vector<vector<pair<int,int>>> tree(4 * (M + 2));
        function<void(int,int,int,int,int,int,int)> add_edge =
            [&](int node, int l, int r, int ql, int qr, int u, int v) {
            if (ql > r || qr < l) return;
            if (ql <= l && r <= qr) {
                tree[node].emplace_back(u, v);
                return;
            }
            int mid = (l + r) >> 1;
            add_edge(node*2, l, mid, ql, qr, u, v);
            add_edge(node*2+1, mid+1, r, ql, qr, u, v);
        };
        for (auto &[u, v, w] : edges) {
            if (u == v) continue;
            if (w > M) add_edge(1, 0, M, 0, M, u, v);
            else {
                if (w > 0) add_edge(1, 0, M, 0, w-1, u, v);
                if (w < M) add_edge(1, 0, M, w+1, M, u, v);
            }
        }

        vector<int> parent(n + 1, -1);
        vector<int> s_comp = s_comp_init;
        vector<int> hist;

        vector<int> s_p(q_prime), s_sz(q_prime, 1);
        iota(s_p.begin(), s_p.end(), 0);
        function<int(int)> s_find = [&](int x) {
            while (s_p[x] != x) {
                s_p[x] = s_p[s_p[x]];
                x = s_p[x];
            }
            return x;
        };
        auto s_unite = [&](int a, int b) {
            a = s_find(a); b = s_find(b);
            if (a == b) return;
            if (s_sz[a] < s_sz[b]) swap(a, b);
            s_p[b] = a;
            s_sz[a] += s_sz[b];
        };

        ll total_cost = 0;
        int components = q_prime;
        int cur_L = 0;

        auto resolve = [&](int c1, int c2) -> int {
            if (c1 == -1) return c2;
            if (c2 == -1) return c1;
            int r1 = s_find(c1), r2 = s_find(c2);
            if (r1 == r2) return r1;
            s_unite(r1, r2);
            total_cost += cur_L;
            --components;
            return s_find(r1);
        };

        function<int(int)> find = [&](int x) {
            while (parent[x] >= 0) x = parent[x];
            return x;
        };
        auto unite = [&](int u, int v) {
            u = find(u); v = find(v);
            if (u == v) return;
            if (-parent[u] < -parent[v]) swap(u, v);
            int sz_u = -parent[u], sz_v = -parent[v];
            hist.push_back(u);
            hist.push_back(parent[u]);
            hist.push_back(s_comp[u]);
            hist.push_back(v);
            hist.push_back(parent[v]);
            parent[v] = u;
            parent[u] = -(sz_u + sz_v);
            s_comp[u] = resolve(s_comp[u], s_comp[v]);
        };
        auto rollback = [&](int checkpoint) {
            while ((int)hist.size() > checkpoint) {
                int pv = hist.back(); hist.pop_back();
                int v = hist.back(); hist.pop_back();
                parent[v] = pv;
                int su = hist.back(); hist.pop_back();
                int pu = hist.back(); hist.pop_back();
                int u = hist.back(); hist.pop_back();
                parent[u] = pu;
                s_comp[u] = su;
            }
        };
        function<void(int,int,int)> dfs = [&](int node, int l, int r) {
            int checkpoint = hist.size();
            cur_L = l;
            for (auto &e : tree[node]) unite(e.first, e.second);
            if (l == r) {
                // leaf
            } else {
                int mid = (l + r) >> 1;
                dfs(node*2, l, mid);
                dfs(node*2+1, mid+1, r);
            }
            rollback(checkpoint);
        };

        dfs(1, 0, M);
        if (components == 1) cout << total_cost << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}