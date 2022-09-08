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

vector<int> find_divisors(int n) {
    vector<int> divisors;
    for (ll i=1; i*i<=n; ++i) {
        if (n%i == 0) {
            int j = n/i;
            if (i!=j)
                divisors.push_back(j);
            divisors.push_back(i);
        }
    }

    return divisors;
}

ll sequence_sum(ll a1, ll r, ll k) {
    return (k*(2*a1 + (k-1)*r))/2;
}

void solve() {
    int n;

    cin >> n;

    vector<int> divisors = find_divisors(n);

    set<ll> ans;
    for (int d: divisors) 
        ans.insert(sequence_sum(1, d, n/d));

    for (ll fun: ans)
        cout << fun << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}