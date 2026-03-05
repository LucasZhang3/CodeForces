//https://codeforces.com/contest/2188/problem/B
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> pos;
        for (int i = 0; i < n; ++i) if (s[i] == '1') pos.push_back(i);
        if (pos.empty()) {
            cout << (n + 2) / 3 << '\n';
            continue;
        }
        int ans = (int)pos.size();
        int left = pos.front();
        int right = n - 1 - pos.back();
        ans += (left + 1) / 3;
        ans += (right + 1) / 3;
        for (size_t i = 1; i < pos.size(); ++i) {
            int gap = pos[i] - pos[i-1] - 1;
            ans += gap / 3;
        }
        cout << ans << '\n';
    }
    return 0;
}