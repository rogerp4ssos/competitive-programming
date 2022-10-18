// g++ -std=c++17 -O2 -Wall c.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 212345
#define MOD ((int)1e9+7)

int arr[MAX_N], mem[MAX_N][2];
bool covered[MAX_N];

int dp(int i, int to_cover) {
    if (i == 0) {
        if (covered[i] or to_cover)
            return arr[0];
        return 0;
    }

    if (mem[i][to_cover] != -1)
        return mem[i][to_cover];

    ll ans;
    if (to_cover) 
        ans = arr[i] + dp(i-1, covered[i]);
    else {
        if (covered[i]) 
            ans = max(arr[i]+dp(i-1, 0), dp(i-1, 1));
        else
            ans = dp(i-1, 0);
    }

    return mem[i][to_cover] = ans;
}

void solve() {
    int n;
    char c;

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> c;
        covered[i] = (c=='1');
    }

    for (int i=0; i<n; ++i) {
        cin >> arr[i];
        mem[i][0] = mem[i][1] = -1;
    }

    cout << dp(n-1, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}