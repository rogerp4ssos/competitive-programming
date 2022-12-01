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
#define MAX_N 112345
#define MOD ((int)1e9+7)
  
void solve() {
    int n;

    cin >> n;

    vector<int> arr(n+1);
    vector<ll> pref(n+1, 0ll);
    for (int i=1; i<=n; ++i) {
        cin >> arr[i];

        pref[i] = pref[i-1] + arr[i];
    }

    int ans = 0;

    int j=n+1;
    for (int i=1; i<=n; ++i) {
        if (arr[i] == 0) {
            j = i;
            break;
        }

        if (pref[i] == 0)
            ans += 1;
    }


    while (j <= n) {
        map<ll, int> count;
        int mx = 1;

        count[pref[j]] += 1;

        bool done = false;
        for (int i=j+1; i<=n; ++i) {
            if (arr[i] == 0) {
                j = i;
                done = true;
                break;
            }

            count[pref[i]] += 1;
            mx = max(mx, count[pref[i]]);
        }

        ans += mx;

        if (!done)
            break;
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