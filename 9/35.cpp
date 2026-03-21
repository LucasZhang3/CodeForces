//https://codeforces.com/contest/2209/problem/D
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000006;
int col[MAXN];
char out[MAXN + 2];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int cnt[3];
        scanf("%d %d %d", &cnt[0], &cnt[1], &cnt[2]);

        int dom = (int)(max_element(cnt, cnt+3) - cnt);
        int others = cnt[0]+cnt[1]+cnt[2] - cnt[dom];
        cnt[dom] = min(cnt[dom], others + 1);

        int n = cnt[0]+cnt[1]+cnt[2];

        for (int i = 0; i < n; i++) {
            int f1 = i >= 1 ? col[i-1] : -1;
            int f3 = i >= 3 ? col[i-3] : -1;
            int p2 = i >= 2 ? col[i-2] : -1;

            int best = -1;
            for (int c = 0; c < 3; c++) {
                if (!cnt[c] || c == f1 || c == f3) continue;
                if (best == -1 || cnt[c] > cnt[best] ||
                    (cnt[c] == cnt[best] && c == p2))
                    best = c;
            }

            col[i] = best;
            cnt[best]--;
        }

        for (int i = 0; i < n; i++) out[i] = "RGB"[col[i]];
        out[n] = '\n';
        fwrite(out, 1, n+1, stdout);
    }
}