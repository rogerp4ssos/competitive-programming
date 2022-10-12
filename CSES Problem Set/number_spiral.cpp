// g++ -std=c++17 -O2 -Wall number_spiral.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 112345
#define MOD ((int)1e9+7)
  
void solve() {
    ll x, y;
    cin >> y >> x;

    ll m = max(x,y);
    ll diag = m*m - (m-1);
    ll diff = y-x;

    if (m%2 != 0) 
        diff*=-1;

    cout << diag+diff << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}