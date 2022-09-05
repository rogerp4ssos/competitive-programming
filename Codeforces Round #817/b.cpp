// g++ -std=c++17 -O2 -Wall b.cpp
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
    string row1, row2;
    cin >> n;
    cin >> row1;
    cin >> row2;

    bool ok = true;
    for (int i=0; i<n; ++i) {
        if ((row1[i] == 'R' or row2[i] == 'R') and row1[i]!=row2[i]) {
            ok = false;
            break;
        }
    }

    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}