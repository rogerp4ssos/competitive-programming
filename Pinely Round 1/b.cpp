// g++ -std=c++17 -O2 -Wall b.cpp
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

bool is_bad(vector<int>& arr) {
    int n = sz(arr);
    for (int i=0; i<n; ++i) {
        if (arr[(i-1+n)%n] != arr[(i+1)%n])
            return false;
    }

    return true;
}

void solve() {
    int n;

    cin >> n;
    vector<int> seq(n);

    for (int &x: seq) cin >> x;

    if (n%2 == 0 and is_bad(seq))
        cout << 1+n/2 << '\n';
    else
        cout << n << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}