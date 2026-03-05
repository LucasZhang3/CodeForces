//https://codeforces.com/contest/2195/problem/E
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> l(n + 1), r(n + 1), parent(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> l[i] >> r[i];
            if (l[i]) parent[l[i]] = i;
            if (r[i]) parent[r[i]] = i;
        }
        parent[1] = 0;

        vector<long long> S(n + 1, 0);
        stack<pair<int, bool>> st;
        st.push({1, false});
        while (!st.empty()) {
            auto [v, vis] = st.top();
            st.pop();
            if (!vis) {
                st.push({v, true});
                if (r[v]) st.push({r[v], false});
                if (l[v]) st.push({l[v], false});
            } else {
                if (l[v] == 0 && r[v] == 0)
                    S[v] = 1;
                else
                    S[v] = (S[l[v]] + S[r[v]] + 3) % MOD;
            }
        }

        vector<long long> ans(n + 1, 0);
        ans[0] = 0;
        stack<int> st2;
        st2.push(1);
        while (!st2.empty()) {
            int v = st2.top();
            st2.pop();
            ans[v] = (S[v] + ans[parent[v]]) % MOD;
            if (r[v]) st2.push(r[v]);
            if (l[v]) st2.push(l[v]);
        }

        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}