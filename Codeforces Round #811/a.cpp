// g++ -std=c++17 -O2 -Wall a.cpp
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
    int n, H, M, h, m;

    cin >> n >> H >> M;

    vector<pii> alarms;
    for (int i=0; i<n; ++i) {
        cin >> h >> m;

        alarms.push_back({h,m});
    }

    sort(all(alarms));

    auto it = lower_bound(all(alarms), make_pair(H,M));

    int ans_h, ans_m;
    if (it == alarms.end()) {
        it = alarms.begin();
        h = it->first;
        m = it->second;

        ans_h = 24-H+h;
        if (m<M) {
            --ans_h;
            m+=60;
        }
        ans_m = m-M;
    }
    else {
        h = it->first;
        m = it->second;

        ans_h = h-H;
        if (m<M) {
            --ans_h;
            m+=60;
        }
        ans_m = m-M;
    }

    cout << ans_h << ' ' << ans_m << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}