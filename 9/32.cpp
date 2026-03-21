//https://codeforces.com/contest/2209/problem/A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll c, k;
        cin >> n >> c >> k;

        vector<ll> a(n);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) {
            if (a[i] <= c) {
                ll f = min(k, c - a[i]);
                c += a[i] + f;
                k -= f;
            }
        }

        cout << c << "\n";
    }
    return 0;
}