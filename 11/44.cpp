//https://codeforces.com/contest/2222/problem/E
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll maxVal = (1LL << n) - 1;
        
        cout << 0 << "\n"; cout.flush();
        
        cout << "I 0\n"; cout.flush();
        int sz; cin >> sz;
        if(sz == -1) return 0;
        
        bool k1 = (sz == 1);
        if(k1){
            cout << "I " << maxVal << "\n"; cout.flush();
            cin >> sz;
            if(sz == -1) return 0;
        }
        
        ll lo = 1, hi = maxVal;
        while(lo < hi){
            ll mid = (lo + hi + 1) / 2;
            cout << "Q " << mid << "\n"; cout.flush();
            int cnt; cin >> cnt;
            if(cnt == -1) return 0;
            if(cnt >= 1) lo = mid;
            else hi = mid - 1;
        }
        ll c = lo;
        
        int k = 0;
        if(k1){
            k = 1;
        } else {
            if((c & (c - 1)) == 0){
                int b = __builtin_ctzll(c);
                int bp = (b + 1) % n;
                ll x = c | (1LL << bp);
                cout << "I " << x << "\n"; cout.flush();
                int s; cin >> s;
                if(s == -1) return 0;
                cout << "Q " << x << "\n"; cout.flush();
                int cnt; cin >> cnt;
                if(cnt == -1) return 0;
                k = (cnt == 1) ? 2 : 3;
            } else {
                ll x = c & (-c);
                cout << "I " << x << "\n"; cout.flush();
                int s; cin >> s;
                if(s == -1) return 0;
                k = (s == 2) ? 2 : 3;
            }
        }
        
        cout << "A " << k << " " << c << "\n"; cout.flush();
    }
    return 0;
}