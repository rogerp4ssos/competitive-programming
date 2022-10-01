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
    int n, x;
    string s;

    cin >> n >> x;
    cin >> s;

    string t = s;
    t+=s;

    vector<int> balance;

    int cnt0 = 0, cnt1 = 0;
    for (int i=0; i<2*n; ++i) {
        if (t[i] == '0') ++cnt0;
        else ++cnt1;

        balance.push_back(cnt0-cnt1);
    }

    int ans = !x;
    for (int i=0; i<n; ++i) {
        int grow = balance[i+n]-balance[i];

        if (!grow) {
            if (balance[i] == x) {
                ans = -1;
                break;
            }
        }

        if ( ((x-balance[i])>=0 and grow>0) or ((x-balance[i])<=0 and grow<0) ) 
            ans += ((x-balance[i])%grow == 0);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}