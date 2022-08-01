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
    vector<int> arr(n);

    for (int &v: arr) cin >> v;

    set<int> seen;
    int cnt = 0;
    for (int i=n-1; i>=0; --i) {
        if (seen.find(arr[i]) != seen.end()) 
            break;
        seen.insert(arr[i]);
    }
    cnt = (int)seen.size();
    cout << n-cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}