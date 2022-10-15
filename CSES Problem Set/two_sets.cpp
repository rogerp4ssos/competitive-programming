// g++ -std=c++17 -O2 -Wall two_sets.cpp
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

void fill_sets(int l, int r, vector<int> &set_a, vector<int> &set_b) {
    while (l < r) {
        if (l%2) {
            set_a.push_back(l);
            set_a.push_back(r);
        }
        else {
            set_b.push_back(l);
            set_b.push_back(r);
        }
        ++l, --r;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> set_a, set_b;
    if (n%2 == 0 and n%4 == 0) 
        fill_sets(1, n, set_a, set_b);
    else if (n%2 != 0 and (n-1)%4 != 0) {
        fill_sets(1, n-1, set_a, set_b);
        set_b.push_back(n);
    }
    else {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << sz(set_a) << '\n';
    for (int x: set_a) 
        cout << x << ' ';
    cout << '\n' << sz(set_b) << '\n';
    for (int x: set_b) 
        cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}