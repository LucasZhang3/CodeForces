//https://codeforces.com/contest/2197/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n), a(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> pos(n + 1);
        for (int i = 0; i < n; ++i) pos[p[i]] = i;

        bool ok = true;
        int prev = -1;
        for (int i = 0; i < n; ++i) {
            int cur = pos[a[i]];
            if (cur < prev) {
                ok = false;
                break;
            }
            prev = cur;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}