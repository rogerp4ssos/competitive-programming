// g++ -std=c++17 -O2 -Wall repetitions.cpp
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
    string dna;
    cin >> dna;

    int n = (int)dna.size(), cnt = 1, max_cnt = 1;
    for (int i=1; i<n; ++i) {
        if (dna[i]==dna[i-1]) ++cnt;
        else {
            if (cnt > max_cnt) max_cnt = cnt;
            cnt = 1;
        }
    }
    if (cnt > max_cnt) max_cnt = cnt;
    cout << max_cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}