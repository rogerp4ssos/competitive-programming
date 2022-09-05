// g++ -std=c++17 -O2 -Wall e.cpp
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

ll areas_ds[MAX_N][MAX_N], areas_pref[MAX_N][MAX_N];

void solve() {
    int n, q, h, w, hs, ws, hb, wb;

    cin >> n >> q;

    for (int i=0; i<MAX_N; ++i) {
        for (int j=0; j<MAX_N; ++j) 
            areas_ds[i][j] = areas_pref[i][j] = 0;
    }

    while (n--) {
        cin >> h >> w;
        areas_ds[h][w] += h*w;
    }

    for (int i=1; i<MAX_N; ++i) {
        for (int j=1; j<MAX_N; ++j) 
            areas_pref[i][j] = areas_ds[i][j] + areas_pref[i-1][j] + areas_pref[i][j-1] - areas_pref[i-1][j-1];
    }

    while (q--) {
        cin >> hs >> ws >> hb >> wb;

        cout << max(0ll, areas_pref[hb-1][wb-1] - areas_pref[hs][wb-1] - areas_pref[hb-1][ws] + areas_pref[hs][ws]) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}