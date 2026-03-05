//https://codeforces.com/contest/2197/problem/D
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
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int B = (int)sqrt(n) + 1;
        ll ans = 0;

        for (int i = 1; i <= n; ++i) {
            int ai = a[i];
            if (ai > n || ai <= B) continue;
            for (int k = 1; k <= B; ++k) {
                ll j = i + (ll)ai * k;
                if (j > n) break;
                if (a[j] == k) ++ans;
            }
        }

        for (int j = 1; j <= n; ++j) {
            int aj = a[j];
            if (aj > n || aj <= B) continue;
            for (int k = 1; k <= B; ++k) {
                ll i = j - (ll)aj * k;
                if (i < 1) break;
                if (a[i] == k) ++ans;
            }
        }

        for (int i = 1; i <= n; ++i) {
            int ai = a[i];
            if (ai > n || ai > B) continue;
            for (int k = 1; k <= B; ++k) {
                ll j = i + (ll)ai * k;
                if (j > n) break;
                if (a[j] == k) ++ans;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}