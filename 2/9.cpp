//https://codeforces.com/contest/2188/problem/A
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
        vector<int> p(n);
        p[0] = (n + 1) / 2;
        for (int k = 1; k < n; ++k) {
            if (k % 2 == 1) {
                p[k] = p[k - 1] + k;
            } else {
                p[k] = p[k - 1] - k;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << p[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}