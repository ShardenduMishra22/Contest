#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if(!(n % 2)){
            cout<<-1<<endl;
        }else{
            for(int i = 1; i <= n/2;i++) {
                cout << i << " ";
            }
            for(int i = n; i > n/2;i--) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
