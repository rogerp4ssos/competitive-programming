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

bool cmp (pair<char,int> a, pair<char,int> b) {
    if (a.first == b.first) 
        return a.second < b.second;
    return a.first > b.first;
}

void solve() {
    string s;
    vector<pair<char, int>> to_jump;
    vector<int> ans;

    cin >> s;
    int n = s.size();

    for (int i=0; i<n; ++i) 
        to_jump.push_back({s[i], i});
    
    if (s[0] <= s[n-1])
        sort(all(to_jump));
    else
        sort(all(to_jump), cmp);

    int j;
    for (int i=0; i<n; ++i) {
        if (to_jump[i].second == 0) {
            j = i;
            break;
        }
    }

    for (int i=j; to_jump[i].second != n-1; ++i) 
        ans.push_back(to_jump[i].second+1);
    ans.push_back(n);

    cout << abs(s[0]-s[n-1]) << ' ' << ans.size() << '\n';
    for (int idx: ans) cout << idx << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}