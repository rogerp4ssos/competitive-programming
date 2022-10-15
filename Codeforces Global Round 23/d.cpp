// g++ -std=c++17 -O2 -Wall d.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 212345
#define MOD ((int)1e9+7)

int n, k;
ll score[MAX_N];
vector<int> adj[MAX_N];
map<pii,ll> mem;

bool cmp(pair<ll,ll> &a, pair<ll,ll> &b) {
    return a.first-a.second > b.first-b.second;
}

ll dp(int u, int paths) {
    if (paths == 0) 
        return 0;
    if (sz(adj[u]) == 0) 
        return score[u]*paths;

    if (mem.find({u, paths}) != mem.end())
        return mem[{u, paths}];

    ll ans = 0;
    if (paths%sz(adj[u]) == 0) {
        int div = paths/sz(adj[u]);
        for (int v: adj[u])
            ans += dp(v, div);
    }
    else {
        vector<pair<ll,ll>> candidates;

        int div = 1 + paths/sz(adj[u]);
        int md = paths%sz(adj[u]);
        for (int v: adj[u]) {
            ll up = dp(v, div);
            ll down = dp(v, div-1);

            candidates.push_back({up, down});
        }

        sort(all(candidates), cmp);

        for (int i=0; i<sz(candidates); ++i) {
            if (i<md) 
                ans += candidates[i].first;
            else 
                ans += candidates[i].second;
        }
    }

    return mem[{u, paths}] = ans + score[u]*paths;
}
  
void solve() {
    cin >> n >> k;

    for (int i=0; i<n; ++i)
        adj[i].clear();

    int p;
    for (int i=1; i<n; ++i) {
        cin >> p;
        --p;

        adj[p].push_back(i);
    }

    for (int i=0; i<n; ++i) 
        cin >> score[i];

    mem.clear();
    cout << dp(0, k) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}