// g++ -std=c++17 -O2 -Wall gray_code.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 112345
#define MOD ((int)1e9+7)

void solve() {
    int n;
    cin >> n;

    for (int i=0; i<(1<<n); ++i) {
        cout << (i&(1<<(n-1))?"1":"0"); 
        for (int b=n-2; b>=0; --b) {
            bool prev_bit = (i&(1<<(b+1))) != 0;
            bool curr_bit = (i&(1<<b)) != 0;

            cout << (curr_bit!=prev_bit?"1":"0");
        }
        cout << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}