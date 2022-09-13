// g++ -std=c++17 -O2 -Wall d.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 112345
#define MAX_X 5
#define MOD ((int)1e9+7)

int n, tt, coord[MAX_N];
ll sz[MAX_N];
ll mem[MAX_N][MAX_X];

ll dp(int t, int x) {
    if (t == MAX_N)
        return 0;

    if (mem[t][x] != -1)
        return mem[t][x];

    ll stop = 0, back = 0, forth = 0;
    stop = dp(t+1, x);
    if (x > 0)
        back = dp(t+1, x-1);
    if (x < 4)
        forth = dp(t+1, x+1);

    return mem[t][x] = max({stop, back, forth}) + ((coord[t]==x) ? sz[t] : 0ll);
}

void solve() {
    cin >> n;

    memset(coord, -1, sizeof(coord));
    memset(mem, -1, sizeof(mem));

    for (int i=0; i<n; ++i) {
        cin >> tt;
        cin >> coord[tt] >> sz[tt];
    } 

    cout << dp(0, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}