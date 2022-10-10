// g++ -std=c++17 -O2 -Wall g.cpp
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
    string s;
    cin >> s;

    int n = (int)s.size();
    for (int i=0; i<n; ++i) {
        if ( (i!=n-1 and s[i] == s[i+1]) or (i!=0 and s[i]==s[i-1]) )
            cout << s[i];
        else
            cout << s[i] << s[i];
    }
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