// g++ -std=c++17 -O2 -Wall h.cpp
#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 1123
#define MOD ((int)1e9+7)

int n, h, l;
bool is_horror[MAX_N];
vector<int> adj[MAX_N];
vector<int> horror_id(MAX_N, INF);

void bfs(int s) {
    queue<int> q;
    vector<bool> used(n, false);
    vector<int> dist(n, INF);

    q.push(s);
    used[s] = true;
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u: adj[v]) {
            if (!used[u]) {
                used[u] = true;

                if (!is_horror[u]) {                
                    q.push(u);
                    dist[u] = dist[v] + 1;
                }
            }
        }
    }

    // update horror_id
    for (int i=0; i<n; ++i)
        horror_id[i] = min(horror_id[i], dist[i]);
}

void solve() {
    int x;

    cin >> n >> h >> l;

    for (int i=0; i<h; ++i) {
        cin >> x;
        is_horror[x] = true;
        horror_id[x] = 0;
    }

    int u, v;
    for (int i=0; i<l; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=0; i<n; ++i) {
        if (is_horror[i]) 
            bfs(i);
    }

    int best = -1, ans = -1;
    for (int i=0; i<n; ++i) {
        if (horror_id[i] > best) {
            ans = i;
            best = horror_id[i];
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