// g++ -std=c++17 -O2 -Wall c.cpp
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
    char c;
    string tl; // traffic light string

    cin >> n >> c;
    cin >> tl;

    if (c == 'g') {
        cout << "0\n";
        return;
    }

    tl+=tl;

    vector<int> start, end;

    for (int i=0; i<2*n; ++i) {
        if (tl[i] == c)
            start.push_back(i);
        if (tl[i] == 'g')
            end.push_back(i);
    }

    int ans = -1;
    for (int x: start) {
        auto it = upper_bound(all(end), x);

        if (it != end.end()) 
            ans = max(ans, *it - x);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}