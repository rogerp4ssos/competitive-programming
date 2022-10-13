#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
 
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_MVS 4
#define MOD ((int)1e9+7)
 
int mv[MAX_MVS][2] = {{+1,-2},
                      {-1,-2},
                      {+2,-1},
                      {-2,-1}};
 
bool is_valid(int x, int y, ll N) {
    return (x>=0 and x<N) and (y>=0 and y<N);
}
 
ll count_safe(int x, int y, ll N) {
    ll cnt_nope = 0;
    for (int i=0; i<MAX_MVS; ++i) {
        int dx = mv[i][0];
        int dy = mv[i][1];
 
        cnt_nope += is_valid(x+dx, y+dy, N);
    }
 
    return N*N - 1 - cnt_nope;
}
 
void solve() {
    int n;
    cin >> n;
 
    vector<ll> ans = {0};
 
    for (int k=1; k<n; ++k) {
        ll new_pairs = 0, N = k+1;
        for (int i=0; i<k; ++i) 
            new_pairs += count_safe(i, k, N);
        new_pairs = 2*new_pairs + count_safe(k, k, N);
 
        ll duplicate = ((2*N-1)*(2*N-2))/2 - (N<3?0:2);
 
        ans.push_back(ans.back() + new_pairs - duplicate);
    }
 
    for (ll x: ans) cout << x << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
    while (t--) solve();
 
    return 0;
}