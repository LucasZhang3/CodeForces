//https://codeforces.com/contest/2195/problem/F
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool lt(int i, int j, const vector<ll>& a, const vector<ll>& b, const vector<ll>& c) {
    if (a[i] < a[j]) {
        ll A = a[j] - a[i];
        ll B = b[j] - b[i];
        ll C = c[j] - c[i];
        ll disc = B * B - 4 * A * C;
        return disc < 0;
    }
    if (a[i] == a[j])
        return b[i] == b[j] && c[i] < c[j];
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i] >> c[i];

        vector<vector<int>> adj(n), radj(n);
        vector<int> indeg_fwd(n, 0), indeg_rev(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (lt(i, j, a, b, c)) {
                    adj[i].push_back(j);
                    radj[j].push_back(i);
                    indeg_fwd[j]++;
                    indeg_rev[i]++;
                }
            }
        }

        vector<int> L(n, 0);
        queue<int> q;
        vector<int> indeg = indeg_fwd;
        for (int i = 0; i < n; ++i)
            if (indeg[i] == 0) {
                q.push(i);
                L[i] = 1;
            }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (L[v] < L[u] + 1) L[v] = L[u] + 1;
                if (--indeg[v] == 0) q.push(v);
            }
        }

        vector<int> R(n, 0);
        queue<int> q2;
        vector<int> indegR = indeg_rev;
        for (int i = 0; i < n; ++i)
            if (indegR[i] == 0) {
                q2.push(i);
                R[i] = 1;
            }
        while (!q2.empty()) {
            int u = q2.front(); q2.pop();
            for (int v : radj[u]) {
                if (R[v] < R[u] + 1) R[v] = R[u] + 1;
                if (--indegR[v] == 0) q2.push(v);
            }
        }

        for (int i = 0; i < n; ++i)
            cout << L[i] + R[i] - 1 << " \n"[i == n - 1];
    }
    return 0;
}