//https://codeforces.com/contest/2188/problem/C
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        b = a;
        sort(b.begin(), b.end());
        if (a == b) {
            cout << -1 << '\n';
            continue;
        }
        ll mn = b.front(), mx = b.back();
        ll ans = (1LL<<62);
        for (int i = 0; i < n; ++i) if (a[i] != b[i]) {
            ll cur = max(a[i] - mn, mx - a[i]);
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
    return 0;
}