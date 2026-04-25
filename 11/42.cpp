//https://codeforces.com/contest/2222/problem/C
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(auto &x:a) cin>>x;
        
        vector<int> s=a;
        sort(s.begin(),s.end());
        int M=s[n/2];
        
        vector<int> dp(n+1,-1);
        dp[0]=0;
        
        for(int j=0;j<n;j++){
            if(dp[j]<0) continue;
            int sb=0,sc=0;
            for(int i=j;i<n;i++){
                sb += (a[i]>=M ? 1 : -1);
                sc += (a[i]<=M ? 1 : -1);
                int len=i-j+1;
                if(len%2==1 && sb>=1 && sc>=1){
                    dp[i+1]=max(dp[i+1],dp[j]+1);
                }
            }
        }
        
        cout<<dp[n]<<"\n";
    }
}