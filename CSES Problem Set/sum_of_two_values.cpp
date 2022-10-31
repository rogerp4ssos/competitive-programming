// g++ -std=c++17 -O2 -Wall sum_of_two_values.cpp
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
    int n, x, a;

    cin >> n >> x;

    vector<pii> arr(n);
    for (int i=0; i<n; ++i) {
        cin >> a;
        arr[i] = {a, i+1};
    }

    sort(all(arr));

    bool done = false;
    for (int i=0; i<n; ++i) {
        auto it = lower_bound(arr.begin()+i+1, arr.end(), make_pair(x-arr[i].first,-1));

        if (it != arr.end()) {
            if (it->first + arr[i].first == x) {
                cout << arr[i].second << ' ' << it->second << '\n';
                done = true;
                break;
            }
        }
    }

    if (!done) cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}