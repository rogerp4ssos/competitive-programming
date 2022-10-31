// g++ -std=c++17 -O2 -Wall maximum_subarray_sum.cpp
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

    ll sum = 0, ans = -INF;
    while (n--) {
        cin >> x;

        sum += x;
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
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