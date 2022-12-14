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
    int n, k, r, c;
    char table[512][512];

    cin >> n >> k >> r >> c;
    --r, --c;

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            table[i][j] = '.';
            if ((i+j)%k == (r+c)%k)
                table[i][j] = 'X';
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j)
            cout << table[i][j];
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}