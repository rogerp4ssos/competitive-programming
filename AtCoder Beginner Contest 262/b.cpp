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
    int n, m, u, v;

    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));

    while (m--) {
        cin >> u >> v;
        --u, --v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int ans = 0;
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            for (int k=j+1; k<n; ++k) {
                if (adj[i][j] and adj[j][k] and adj[i][k])
                    ++ans;
            }
        }
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