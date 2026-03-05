//https://codeforces.com/contest/2197/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dsum(ll n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        int ans = 0;
        for (int s = 0; s <= 100; ++s) {
            ll y = x + s;
            if (dsum(y) == s) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}