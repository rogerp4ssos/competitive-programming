// g++ -std=c++17 -O2 -Wall b.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define all(v) v.begin(), v.end()
#define INF LLONG_MAX
#define MAX_N 112345
#define MOD ((int)1e9+7)
  
void solve() {
    ll n, k;

    cin >> n >> k;
    vector<ll> arr(n);

    for (ll &x: arr) cin >> x;

    ll ans = -INF;
    for (ll i=n-1; i>=0; --i) {
        for (ll j=i-1; j>=max(0ll, i-k); --j) {
            ans = max(ans, (i+1)*(j+1)-k*(arr[i]|arr[j]));
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}