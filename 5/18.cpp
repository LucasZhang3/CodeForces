//https://codeforces.com/contest/2195/problem/A
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
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x == 67) ok = true;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}