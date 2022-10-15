// g++ -std=c++17 -O2 -Wall b.cpp
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
    int n, x;
    cin >> n;

    set<int> ones, zeros;

    for (int i=0; i<n; ++i) {
        cin >> x;
        if (x == 1)
            ones.insert(i);
        else
            zeros.insert(i);
    }

    int ans = 0;
    while (!zeros.empty() and !ones.empty()) {
        auto it1 = ones.begin();
        auto it2 = zeros.end();
        --it2;

        if (*it1 > *it2)
            break;

        ones.insert(*it2);
        zeros.erase(it2);
        ones.erase(it1);

        ++ans;
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