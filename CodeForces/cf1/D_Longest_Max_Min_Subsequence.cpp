#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> A(n);
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
    vector<ll> cnt(n + 1);
    for(int i = 0 ; i < n ; i++){
        cnt[A[i]]++;
    }
    ll i = 0, j = 0, curr = 1;
    vector<ll> fin_ans;
    vector<bool> used(n+1);
    set<vector<ll>> st_lef, st_rig;
    while(j < n){
        if(!used[A[j]]){
            if(cnt[A[j]] == 1){
                // cout << j << endl;
                st_lef.insert({A[j], -1*j});
                st_rig.insert({A[j], j});
                while(!used[A[j]] && i <= j){
                    // cout <<  << endl;
                    ll ind = -1;
                    ll val = -1;
                    if(curr%2 != 0){
                        auto it = st_lef.end();
                        it--;
                        while(used[(*it)[0]]){
                            auto temp_it = it;
                            temp_it--;
                            st_lef.erase(it);
                            it = temp_it;
                        }
                        fin_ans.push_back((*it)[0]);
                        // cout << ((*it)[0]) << " ";
                        ind = -1*(*it)[1];
                        val = (*it)[0];
                    }
                    else{
                        auto it = st_rig.begin();
                        while(used[(*it)[0]]){
                            auto temp_it = it;
                            temp_it++;
                            st_rig.erase(it);
                            it = temp_it;
                        }
                        fin_ans.push_back((*it)[0]);
                        // cout << ((*it)[0]) << " ";
                        ind = (*it)[1];
                        val = (*it)[0];
                    }
                    curr++;
                    while(i <= ind){
                        if(!used[A[i]]){
                            st_lef.erase({A[i], -1*i});
                            st_rig.erase({A[i], i});
                        }
                        i++;
                    }
                    used[val] = true;
                }
                auto it_lef = st_lef.begin();
                while(it_lef != st_lef.end()){
                    if(used[(*it_lef)[0]]){
                        auto it = it_lef;
                        it++;
                        st_lef.erase(it_lef);
                        it_lef = it;
                    }
                    else{
                        it_lef++;
                    }
                }
                it_lef = st_rig.begin();
                while(it_lef != st_rig.end()){
                    if(used[(*it_lef)[0]]){
                        auto it = it_lef;
                        it++;
                        st_rig.erase(it_lef);
                        it_lef = it;
                    }
                    else{
                        it_lef++;
                    }
                }
            }
            else{
                st_lef.insert({A[j], -1*j});
                st_rig.insert({A[j], j});
                cnt[A[j]]--;
            }
        }
        j++;
    }
    
    cout << fin_ans.size() << endl;
    for(auto x : fin_ans){
        cout << x << " ";
    }
    cout << endl;
}
 
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin >> t;
    while(t--){
        // x++;
        solve();
    }
	return 0;
}