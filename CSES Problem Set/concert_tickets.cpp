// g++ -std=c++17 -O2 -Wall concert_tickets.cpp
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
    int n, m, h, t;

    cin >> n >> m;
    multiset<int> tickets;
    while (n--) {
        cin >> h;
        tickets.insert(h);
    }

    while (m--) {
        cin >> t;

        auto it = tickets.upper_bound(t);
        if (it != tickets.begin()) {
            --it;
            cout << *it << '\n';
            tickets.erase(it);
        }
        else
            cout << "-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}