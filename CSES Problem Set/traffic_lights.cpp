// g++ -std=c++17 -O2 -Wall traffic_lights.cpp
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
    int x, n;
    cin >> x >> n;

    vector<int> pos(n), ans(n);
    set<int> traffic_lights = {0, x};

    for (int &p: pos) {
        cin >> p;
        traffic_lights.insert(p);
    }

    ans[n-1] = 0;
    for (auto it=traffic_lights.begin(); it!=traffic_lights.end(); ++it) {
        if (it != traffic_lights.begin()) {
            auto prev_it = --it;
            ++it;

            ans[n-1] = max(ans[n-1], *it-*prev_it);
        }
    }

    for (int i=n-2; i>=0; --i) {
        auto it = traffic_lights.find(pos[i+1]);

        auto it_prev = --it;
        ++it;
        auto it_next = ++it;
        --it;

        int gap = *it_next - *it_prev;
        ans[i] = max(ans[i+1], gap);

        traffic_lights.erase(it);
    }

    for (int l: ans) cout << l << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}