// g++ -std=c++17 -O2 -Wall c.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_A 1123456
#define MOD ((int)1e9+7)

map<int,ll> cnt;
void solve() {
    ll n;

    cin >> n;
    vector<ll> a(n);
    cnt.clear();

    for (ll &x: a) {
        cin >> x;
        cnt[x] += 1;
    }

    sort(all(a));

    ll ans = (n*(n-1))/2;
    ll tot = 0;
    for (ll x: a) {
        if (cnt[x] == n) {
            ans = n/2;
            break;
        }
        if (cnt[x]) {
            ans -= cnt[x]*min(tot, n-tot-cnt[x]);
            ans -= (cnt[x]*(cnt[x]-1))/2;

            tot += cnt[x];
        }

        cnt[x] = 0;
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