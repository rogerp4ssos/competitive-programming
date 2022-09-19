// g++ -std=c++17 -O2 -Wall d.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 112
#define MOD ((int)1e9+7)
  
int max_diff, n;
int mem[MAX_N][MAX_N][MAX_N];
string queueue;

int dp(int p1, int p2, int diff) {
    if (p2 == n) {
        int val = queueue[p2] == 'W' ? 1:-1;

        if (abs(diff + val) <= max_diff)
            return 1;
        return 0;
    }

    if (mem[p1][p2][diff] != -1)
        return mem[p1][p2][diff];

    int val1 = queueue[p1] == 'W' ? 1:-1;
    int val2 = queueue[p2] == 'W' ? 1:-1;

    int ans = 0;
    if (abs(diff + val1) <= max_diff)
        ans = max(ans, dp(p2, p2+1, diff+val1)+1);
    if (abs(diff + val2) <= max_diff)
        ans = max(ans, dp(p1, p2+1, diff+val2)+1);

    return mem[p1][p2][diff] = ans;
}

void solve() {

    cin >> max_diff;
    cin >> queueue;

    n = queueue.size();

    if (n == 1) {
        cout << "1\n";
        return;
    }

    memset(mem, -1, sizeof mem);

    cout << dp(0, 1, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}