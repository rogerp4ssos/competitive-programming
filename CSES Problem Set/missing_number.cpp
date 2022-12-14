// g++ -std=c++17 -O2 -Wall missing_number.cpp
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

    cin >> n;
    vector<bool> marked(n, false);

    for (int i=0; i<n-1; ++i) {
    	cin >> x;
    	--x;
    	marked[x] = true;
    }

    for (int i=0; i<n; ++i) {
    	if (!marked[i]) {
    		cout << i+1 << '\n';
    		break;
    	}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}