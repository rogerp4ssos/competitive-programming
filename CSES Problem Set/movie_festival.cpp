// g++ -std=c++17 -O2 -Wall movie_festival.cpp
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
    vector<pii> movies(n);
    for (auto &[a, b]: movies) 
        cin >> a >> b;

    sort(all(movies));

    pii last = movies[0];
    int cnt = 1;

    for (int i=1; i<sz(movies); ++i) {
        if (movies[i].first >= last.second) {
            last = movies[i];
            ++cnt;
        }
        else if (movies[i].second < last.second) 
                last = movies[i];
    }

    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}