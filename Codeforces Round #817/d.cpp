// g++ -std=c++17 -O2 -Wall d.cpp
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
    string line;

    cin >> n;
    cin >> line;

    ll value = 0;
    vector<ll> change(n);
    for (int i=0; i<n; ++i) {
        if (line[i] == 'L') {
            value += i;
            change[i] = (n-i-1)-i;
        }
        else {
            value += (n-i-1);
            change[i] = i-(n-i-1);
        }
    }

    sort(all(change));
    reverse(all(change));

    for (int i=0; i<n; ++i) {
        if (change[i] > 0) 
            value += change[i];
        cout << value << ' ';
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