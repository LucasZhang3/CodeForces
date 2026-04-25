//https://codeforces.com/contest/2222/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<int> a(n);
        for(auto &x:a) scanf("%d",&x);
        
        int maxs = 100*n;
        vector<bool> dp(maxs+1,false);
        dp[0]=true;
        
        for(int i=0;i<n;i++){
            int s=100/a[i]; // step size
            vector<bool> ndp(maxs+1,false);
            // ndp[j] = true if exists k in [0,a[i]] s.t. dp[j-k*s] is true
            // sliding window OR with lookback of a[i] steps of size s
            for(int r=0;r<s;r++){
                int in_win=0;
                int p=0;
                for(int v=r;v<=maxs;v+=s,p++){
                    if(dp[v]) in_win++;
                    int out=v-(a[i]+1)*s;
                    if(out>=r && dp[out]) in_win--;
                    ndp[v]=(in_win>0);
                }
            }
            dp=ndp;
        }
        
        bool ok=true;
        for(int j=0;j<=maxs;j++) if(!dp[j]){ok=false;break;}
        puts(ok?"Yes":"No");
    }
}