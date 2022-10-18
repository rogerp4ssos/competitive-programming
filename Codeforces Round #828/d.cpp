// g++ -std=c++17 -O2 -Wall d.cpp
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

    int k = 0;
    for (int i=0; i<n; ++i) {
        cin >> x;
        k += __builtin_ctz(x);
    }

    if (k > n) {
        cout << "0\n";
        return;
    }

    vector<int> to_add;
    for (int i=1; i<=n; ++i) {
        int b = __builtin_ctz(i);
        to_add.push_back(b);
    }

    sort(all(to_add));
    reverse(all(to_add));

    int target = n-k;
    int ans = 0;
    for (int a: to_add) {
        if (target > 0 and a<=target) {
            target -= a;
            ++ans;
        } 
    }

    if (!target) cout << ans << '\n';
    else cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}