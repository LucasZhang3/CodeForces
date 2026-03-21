//https://codeforces.com/contest/2209/problem/E
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        vector<int> ql(q), qr(q);
        map<int, vector<int>> byl;
        for (int i = 0; i < q; i++) {
            cin >> ql[i] >> qr[i];
            ql[i]--; qr[i]--;
            byl[ql[i]].push_back(i);
        }

        vector<ll> ans(q);

        for (auto& [l0, ids] : byl) {
            int slen = n - l0;

            vector<int> Z(slen, 0);
            Z[0] = slen;
            for (int i = 1, li = 0, ri = 0; i < slen; i++) {
                if (i < ri) Z[i] = min(ri - i, Z[i - li]);
                while (i + Z[i] < slen && s[l0 + Z[i]] == s[l0 + i + Z[i]])
                    Z[i]++;
                if (i + Z[i] > ri) { li = i; ri = i + Z[i]; }
            }

            int K = 0;
            for (int id : ids) K = max(K, qr[id] - l0 + 1);


            vector<int> mR(K + 2, 0);
            mR[0] = slen;  
            vector<ll> pre(K + 1, 0);
            int cur = 0;

            for (int j = 1; j <= K; j++) {
                while (cur > 0 && mR[cur] < j) cur--;
                int dpj = cur + 1;
                int zj = (j < slen) ? Z[j] : 0;
                mR[dpj] = j + zj;
                if (zj > 0) cur = dpj;
                pre[j] = pre[j - 1] + dpj;
            }

            for (int id : ids)
                ans[id] = pre[qr[id] - l0 + 1];
        }

        for (int i = 0; i < q; i++) cout << ans[i] << "\n";
    }
    return 0;
}