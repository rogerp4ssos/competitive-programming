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
    string t, s;

    cin >> n;
    cin >> t;

    for (int i=n-1; i>=0; ) {
        string snum;

        if (t[i] == '0') {
            snum = {t[i-2], t[i-1]};
            i-=3;
        }
        else {
            snum = {t[i]};
            --i;
        }

        s.push_back((stoi(snum)-1)+'a');
    }

    reverse(all(s));

    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}