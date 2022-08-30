// g++ -std=c++17 -O2 -Wall b.cpp
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
    ll n, k, b, s;

    cin >> n >> k >> b >> s;
    
    if (b*k>s or (s!=b and k==1)) {
        cout << "-1\n";
        return;
    }

    vector<ll> ans(n, 0);    
    for (int i=0; i<n; ++i) {
        if (i == 0) {
            ans[i] = b*k;
            s -= ans[i];
        }

        ans[i] += min(s, k-1);
        s -= min(s, k-1);
    }

    if (s != 0) {
        cout << "-1\n";
        return;
    }

    for (ll a: ans)
        cout << a << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}