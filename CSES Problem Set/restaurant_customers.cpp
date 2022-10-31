// g++ -std=c++17 -O2 -Wall restaurant_customers.cpp
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
    int n, a, b;
    vector<pii> times;

    cin >> n;
    while (n--) {
        cin >> a >> b;

        times.push_back({a, 1});
        times.push_back({b, -1});
    }

    sort(all(times));

    int clients = 0, ans = 0;
    for (pii t: times) {
        clients += t.second;
        ans = max(ans, clients);
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