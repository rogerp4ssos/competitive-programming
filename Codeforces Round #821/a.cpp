// g++ -std=c++17 -O2 -Wall a.cpp
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
    int n, k;
    ll x;

    cin >> n >> k;
    vector<ll> max_mod(k, 0);

    for (int i=0; i<n; ++i) {
        cin >> x;

        max_mod[i%k] = max(max_mod[i%k], x);
    }

    cout << accumulate(all(max_mod), 0ll) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}