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

int count_distinct(int l, int r, vector<vector<int>>& count_pref) {
    int cnt = 0;

    for (int k=0; k<10; ++k) {
        cnt += (count_pref[r][k]>count_pref[l-1][k]);
    }

    return cnt;
}

int max_occur(int l, int r, vector<vector<int>>& count_pref) {
    int ans = -1;

    for (int k=0; k<10; ++k)
        ans = max(ans, count_pref[r][k] - count_pref[l-1][k]);

    return ans;
}

void solve() {
    int n;
    char c;

    cin >> n;
    vector<vector<int>> count_pref(n+1, vector<int>(10, 0));


    for (int i=1; i<=n; ++i) {
        cin >> c;

        for (int k=0; k<10; ++k)
            count_pref[i][k] = count_pref[i-1][k];

        count_pref[i][c-'0'] += 1;
    }

    int cnt = 0;
    for (int i=1; i<=n; ++i) {
        for (int j=i; j<=n; ++j) {
            int mx = max_occur(i, j, count_pref);
            if (mx > 10)
                break;

            int dis = count_distinct(i, j, count_pref);

            if (mx <= dis)
                cnt+=1;
        }
    }
    
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}