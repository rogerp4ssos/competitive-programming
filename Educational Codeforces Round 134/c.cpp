// g++ -std=c++17 -O2 -Wall c.cpp
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
    int n;

    cin >> n;
    vector<int> a(n), b(n), neighbor(n), dmin(n), dmax(n);

    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;

    for (int i=n-1; i>=0; --i) 
        dmin[i] = *lower_bound(all(b), a[i]) - a[i];

    multiset<int> to_match;

    for (int i=n-1; i>=0; --i) 
        neighbor[i] = b[i];

    dmax[n-1] = neighbor[n-1] - a[n-1];
    for (int i=n-2; i>=0; --i) {
        to_match.insert(neighbor[i+1]);
        to_match.insert(neighbor[i]);

        auto it = to_match.lower_bound(a[i+1]);
        to_match.erase(to_match.find(*it));

        neighbor[i] = *to_match.begin();
        dmax[i] = neighbor[i] - a[i];

        to_match.clear();
    }

    for (int x: dmin)
        cout << x << ' ';
    cout << '\n';
    for (int x: dmax)
        cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}