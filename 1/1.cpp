//https://codeforces.com/contest/2189/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;     
        int both = 0, only_h = 0, only_l = 0;
        int mn = min(h, l);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a <= mn) both++;
            else if (a <= h) only_h++;
            else if (a <= l) only_l++;
        }     
        int ans = 0;
        for (int r_both = 0; r_both <= both; r_both++) {
            int c_both = both - r_both;
            int rows = r_both + only_h;
            int cols = c_both + only_l;
            ans = max(ans, min(rows, cols));
        }    
        cout << ans << '\n';
    }
    return 0;
}