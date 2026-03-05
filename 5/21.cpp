//https://codeforces.com/contest/2195/problem/D
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> f(n);
        for (int i = 0; i < n; ++i) cin >> f[i];
        if (n == 2) {
            cout << f[1] << ' ' << f[0] << '\n';
            continue;
        }
        vector<ll> a(n);
        ll P = 0, Q = 0;
        for (int i = 1; i <= n - 2; ++i) {
            ll val = (f[i + 1] - 2 * f[i] + f[i - 1]) / 2;
            a[i] = val;
            P += val * i;
            Q += val * (n - i - 1);
        }
        a[0] = (f[n - 1] - Q) / (n - 1);
        a[n - 1] = (f[0] - P) / (n - 1);
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}
