#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
 
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MOD ((int)1e9+7)
 
void solve() {
    ll n;
    cin >> n;
  
    for (ll k=1; k<=n; ++k) {
        ll all_pairs = (k*k*(k*k-1))/2;
        ll attacking_pairs = (k-1)*(k-2)*2*2;

        cout << all_pairs - attacking_pairs << '\n';
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