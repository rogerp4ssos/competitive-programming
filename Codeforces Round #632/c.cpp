// g++ -std=c++17 -O2 -Wall c.cpp
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
    int n;

    cin >> n;
    vector<ll> arr(n);
    for (ll &x: arr) cin >> x;

    vector<ll> pref = {0};
    for (ll x: arr)
        pref.push_back(pref.back() + x);

    int safe_idx = 0; // guarantees that in the interval (safe_idx+1, i] there are only good subarrays
    ll ans = 0;
    map<ll, int> last; // last[pref[i]] = j, the idx of the last prefix with same sum as pref[i]
    for (int i=1; i<=n; ++i) {
        int j;
        if (last.find(pref[i]) == last.end())  
            j = safe_idx;
        else
            j = max(safe_idx, last[pref[i]]);

        // count the number of good subarrays ending in the i-th idx
        ans += i-j;
        if (pref[i] == pref[j]) {
            --ans;
            safe_idx = max(safe_idx, j+1);
        }

        // update
        last[pref[i]] = i;
    }

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