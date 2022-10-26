// g++ -std=c++17 -O2 -Wall ferris_wheel.cpp
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
    int n, x, p;
    cin >> n >> x;

    multiset<int> weights;

    while (n--) {
        cin >> p;
        weights.insert(p);
    }

    int cnt = 0;
    while (!weights.empty()) {
        int w = *weights.rbegin();
        weights.erase(weights.find(w));

        auto it = weights.upper_bound(x-w);
        if (it != weights.begin()) {
            --it;

            weights.erase(it);
        }
        ++cnt;
    }

    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}