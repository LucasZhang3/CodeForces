//https://codeforces.com/contest/2209/problem/C
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        int ans = 2*n;
        bool found = false;
        
        auto ask = [&](int i, int j) -> bool {
            if(found) return true;
            cout << "? " << i << " " << j << "\n";
            cout.flush();
            int r; cin >> r;
            if(r == -1) exit(0);
            if(r == 1){ ans = i; found = true; return true; }
            return false;
        };
        
        ask(1,2); ask(1,3); ask(2,3);
        for(int i = 4; !found && i <= 2*n-2; i += 2)
            ask(i, i+1);
        
        cout << "! " << ans << "\n";
        cout.flush();
    }
    
    return 0;
}