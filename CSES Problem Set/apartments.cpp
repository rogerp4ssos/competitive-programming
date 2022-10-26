// g++ -std=c++17 -O2 -Wall apartments.cpp
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
    int n, m, k, x;

    cin >> n >> m >> k;

    vector<int> desired(n);
    multiset<int> sizes;

    for (int &sz: desired) cin >> sz;

    for (int i=0; i<m; ++i) {
        cin >> x;
        sizes.insert(x);
    }

    sort(all(desired));

    for (int sz: desired) {
        auto it = sizes.lower_bound(sz-k); // *it >= sz-k

        if (it != sizes.end()) {
            if (*it <= sz+k) // and *it <= sz+k
                sizes.erase(it);
        }
    }

    // total_apartments - remaining_apartments
    cout << m-sz(sizes) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}