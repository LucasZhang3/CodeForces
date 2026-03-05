//https://codeforces.com/contest/2194/problem/B
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
        ll x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        for (ll &v : a) cin >> v;
        
        ll totalExtracted = 0;
        ll maxRemain = 0; // max of a[i] - (a[i]/x)*y
        
        for (ll v : a) {
            ll k = v / x;
            totalExtracted += k * y;
            ll remain = v - k * y;
            maxRemain = max(maxRemain, remain);
        }
        
        cout << totalExtracted + maxRemain << "\n";
    }
    return 0;
}