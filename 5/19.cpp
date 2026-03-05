//https://codeforces.com/contest/2195/problem/B
#include <bits/stdc++.h>
using namespace std;

int odd(int x) {
    while (x % 2 == 0) x /= 2;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (odd(i + 1) != odd(a[i])) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}