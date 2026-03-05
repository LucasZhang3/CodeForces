//https://codeforces.com/contest/2197/problem/C
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll p, q;
        cin >> p >> q;
        if (p < q && 3LL * p >= 2LL * q)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
    return 0;
}