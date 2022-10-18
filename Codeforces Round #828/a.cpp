// g++ -std=c++17 -O2 -Wall a.cpp
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

    vector<int> arr(n);
    for (int &x: arr) cin >> x;

    string s;
    cin >> s;

    map<int, char> m;
    for (int i=0; i<n; ++i) {
        if (m.find(arr[i]) != m.end()) {
            if (m[arr[i]] != s[i]) {
                cout << "NO\n";
                return;
            }
        }
        else
            m[arr[i]] = s[i];
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