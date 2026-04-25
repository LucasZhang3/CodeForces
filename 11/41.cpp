///https://codeforces.com/contest/2222/problem/B
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<ll> og,eg;
        ll tot=0;
        for(int i=1;i<=n;i++){
            ll v; cin>>v;
            tot+=v;
            if(i%2==1) og.push_back(v);
            else eg.push_back(v);
        }
        sort(og.rbegin(),og.rend());
        sort(eg.rbegin(),eg.rend());
        
        int co=0,ce=0;
        for(int i=0;i<m;i++){
            int x; cin>>x;
            if(x%2==1) co++; else ce++;
        }
        
        ll marked=0;
        if(co>0){
            int lim=min(co,(int)og.size());
            marked+=og[0];
            for(int i=1;i<lim;i++){
                if(og[i]>0) marked+=og[i];
                else break;
            }
        }
        if(ce>0){
            int lim=min(ce,(int)eg.size());
            marked+=eg[0];
            for(int i=1;i<lim;i++){
                if(eg[i]>0) marked+=eg[i];
                else break;
            }
        }
        
        cout<<tot-marked<<"\n";
    }
}