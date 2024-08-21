#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_map<int,int>m;
        for(int i : arr){
            m[i] += 1;
        }
        int mx = -1;
        int cnt = 0;
        for(auto i : m){
            if(i.second > cnt){
                mx = i.first;
                cnt = i.second;
            }
        }
        cout<<(n - cnt)<<endl;
    }
}