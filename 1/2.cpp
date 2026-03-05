//https://codeforces.com/contest/2189/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;
        
        long long base = 0;
        long long max_gain = LLONG_MIN;
        
        for (int i = 0; i < n; i++) {
            long long a, b, c;
            cin >> a >> b >> c;
            base += (b - 1) * a;
            max_gain = max(max_gain, b * a - c);
        }
        
        if (base >= x) {
            cout << 0 << "\n";
        } else if (max_gain <= 0) {
            cout << -1 << "\n";
        } else {
            long long needed = x - base;
            long long rollbacks = (needed + max_gain - 1) / max_gain;
            cout << rollbacks << "\n";
        }
    }
    
    return 0;
}