// g++ -std=c++17 -O2 -Wall d1.cpp
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
    ll x, y;
    string a, b;

    cin >> n >> x >> y;
    cin >> a;
    cin >> b;

    vector<int> to_flip;
    for (int i=0; i<n; ++i) 
    	if (a[i]!=b[i]) to_flip.push_back(i);

    int cnt = (int)to_flip.size();
    if (cnt%2 != 0)
    	cout << "-1\n";
    else {
    	ll ans = 0;
    	if (cnt == 2) {
    		if (to_flip[0]+1 == to_flip[1])
    			ans = min(x, 2*y);
    		else
    			ans = y; 
    	}
    	else
    		ans = y*(cnt/2);
    	cout << ans << "\n";
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