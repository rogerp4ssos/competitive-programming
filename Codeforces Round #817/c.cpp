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

int size_to_point(int sz) {
    if (sz == 1) return 3;
    if (sz == 2) return 1;
    return 0;
}

void solve() {
    int n;
    string s;
    vector<string> p1, p2, p3;
    map<string, set<int>> mark;

    cin >> n;

    for (int i=0; i<n; ++i) {
        cin >> s;
        p1.push_back(s);
        mark[s].insert(1);
    }
    for (int i=0; i<n; ++i) {
        cin >> s;
        p2.push_back(s);
        mark[s].insert(2);
    }
    for (int i=0; i<n; ++i) {
        cin >> s;
        p3.push_back(s);
        mark[s].insert(3);
    }

    int tot1=0, tot2=0, tot3=0;
    for (int i=0; i<n; ++i) {
        tot1 += size_to_point(mark[p1[i]].size());
        tot2 += size_to_point(mark[p2[i]].size());
        tot3 += size_to_point(mark[p3[i]].size());
    }

    cout << tot1 << ' ' << tot2 << ' ' << tot3 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}