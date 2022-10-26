// g++ -std=c++17 -O2 -Wall apple_division.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
 
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define INF LLONG_MAX
#define MAX_N 20
#define MOD ((int)1e9+7)
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> apples(n);
    for (int &a: apples) cin >> a;
 
    ll ans = INF;
    for (int mask=0; mask<=(1<<n)-1; ++mask) {
 
        ll diff = 0;
        for (int b=0; b<n; ++b) {
            if (mask&(1<<b))
                diff += apples[b];
            else
                diff -= apples[b];
        }
 
        ans = min(abs(diff), ans);
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