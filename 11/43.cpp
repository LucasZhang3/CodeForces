//https://codeforces.com/contest/2222/problem/D
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
        vector<ll> a(n);
        for(auto& x : a) cin >> x;
        
        vector<ll> c(n);
        c[0] = 0;
        for(int i = 1; i < n; i++) c[i] = c[i-1] + a[i-1];
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y){
            return c[x] > c[y];
        });
        
        vector<int> p(n);
        for(int k = 0; k < n; k++) p[idx[k]] = k + 1;
        
        for(int i = 0; i < n; i++)
            cout << p[i] << " \n"[i == n-1];
    }
    return 0;
}