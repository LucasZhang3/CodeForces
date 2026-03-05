//https://codeforces.com/contest/2195/problem/C
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool adj[6][6] = {};
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            if (i != j && i + j != 5)
                adj[i][j] = true;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

            vector<int> dp(6);
        for (int v = 0; v < 6; ++v)
            dp[v] = (a[0] != v + 1);

        for (int i = 1; i < n; ++i) {
            vector<int> ndp(6, INF);
            int cur = a[i];
            for (int v = 0; v < 6; ++v) {
                int cost = (cur != v + 1);
                for (int u = 0; u < 6; ++u) {
                    if (adj[u][v])
                        ndp[v] = min(ndp[v], dp[u] + cost);
                }
            }
            dp = move(ndp);
        }

        int ans = INF;
        for (int v = 0; v < 6; ++v) ans = min(ans, dp[v]);
        cout << ans << '\n';
    }
    return 0;
}