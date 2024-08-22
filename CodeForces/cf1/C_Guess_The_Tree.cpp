#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define F fflush(stdout);
#define endl "\n"
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);


int main(){
    ll t;cin>>t;
    while(t--){
        ll n,i,j,cnt=0,in=2;cin>>n; F
        vector<ll> ans;
        while(cnt!=n-1){
            ll x=1,y=in;in++;
            while(true){
                cout<<"? "<<x<<" "<<y<<endl; F
                ll z;cin>>z;
                if(z==x){cnt++;ans.push_back(x);ans.push_back(y);break;}
                else{x=z;}
            }
        }
        cout<<"! "; F
        for(i=0;i<(ll)ans.size();i++){
            cout<<ans[i]<<" "; F
        } 
        cout<<endl; F
    }
}