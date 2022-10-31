// g++ -std=c++17 -O2 -Wall playlist.cpp
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

    vector<int> playlist(n);
    unordered_map<int, bool> songs;

    int ans = 1, l = 0; 
    for (int i=0; i<n; ++i) {
        cin >> playlist[i];

        while (songs.find(playlist[i]) != songs.end())
            songs.erase(playlist[l++]);

        songs[playlist[i]] = true;

        ans = max(ans, sz(songs));
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