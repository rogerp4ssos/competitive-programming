// g++ -std=c++17 -O2 -Wall e.cpp
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

double expected_value(int n) {
    if (n==1)
        return (1+2+3+4+5+6)/6.;
    
    double prev = expected_value(n-1);

    double result = 0;
    for (int i=1; i<=6; ++i)
        result += max(1.*i, prev);
    result /= 6.;

    return result;
}

void solve() {
    int n;

    cin >> n;

    cout << setprecision(10);
    cout << expected_value(n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}