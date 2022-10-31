// g++ -std=c++17 -O2 -Wall stick_lengths.cpp
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

    vector<int> sticks(n);
    for (int &p: sticks) cin >> p;

    sort(all(sticks));
    
    int median = sticks[n/2];
    if (n%2 == 0)
        median = (median+sticks[(n/2)-1])/2;
    ll ans = 0;

    for (int p: sticks)
        ans += abs(p-median);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}