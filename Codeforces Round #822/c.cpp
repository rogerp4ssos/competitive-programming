// g++ -std=c++17 -O2 -Wall c.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 1123456
#define MOD ((int)1e9+7)

void solve() {
    int n;
    string bin;
    cin >> n;
    cin >> bin;

    ll ans = 0;
    for (int k=1; k<=n; ++k) { // O(n)
        if (bin[k-1] != '1') {
            for (int i=k; i<=n; i+=k) { // O(log(n))
                if (bin[i-1] == '0') {
                    ans += k;
                    bin[i-1] = '2'; // deleted
                }
                else if (bin[i-1] == '1')
                    break;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}