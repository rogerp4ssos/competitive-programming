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
    cin >> n;

    if (n == 2) {
        cout << "2 1\n";
        return;
    }
    if (n == 3) {
        cout << "-1\n";
        return;
    }

    vector<int> ans;

    ans.push_back(n-1);
    ans.push_back(n);
    n-=2;

    for (int i=1; i<=n; ++i) 
        ans.push_back(i);

    for (int x: ans) cout << x << ' ';
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