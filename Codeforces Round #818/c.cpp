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

    vector<int> a(n), b(n);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;

    for (int i=0; i<n; ++i) {
        if (b[i]-a[i] < 0 or (a[i]!=b[i] and b[i]>b[(i+1)%n]+1)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}