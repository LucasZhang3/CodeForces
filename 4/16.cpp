//https://codeforces.com/contest/2194/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        ll n, w;
        cin >> n >> w;
        ll blocks = n / w;
        ll rem = n % w;
        cout << blocks * (w - 1) + rem << "\n";
    }
    return 0;
}