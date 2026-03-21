//https://codeforces.com/contest/2209/problem/B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fh(ll s) { return s >= 0 ? s/2 : (s-1)/2; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto& x : a) cin >> x;
        for (int i = 0; i < n; i++) {
            int init = 0;
            vector<pair<ll,int>> ev;
            for (int j = i+1; j < n; j++) {
                ll s = a[i] + a[j];
                if (a[j] > a[i])      ev.push_back({fh(s)+1,    +1});
                else if (a[j] < a[i]) { init++; ev.push_back({fh(s-1)+1, -1}); }
            }
            sort(ev.begin(), ev.end());
            int cur = init, best = init;
            for (int e = 0; e < (int)ev.size(); ) {
                ll k = ev[e].first;
                while (e < (int)ev.size() && ev[e].first == k) cur += ev[e++].second;
                best = max(best, cur);
            }
            cout << best << " \n"[i==n-1];
        }
    }
}