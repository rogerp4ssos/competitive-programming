// g++ -std=c++17 -O2 -Wall c.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_E 25
#define MOD ((int)1e9+7)

int find_max_divisor(int n) { // except n
    for (int i=2; i*i<=n; ++i)
        if (n%i == 0)
            return n/i;

    return 1;
}

void solve() {
    int n;
    cin >> n;

    int rightmost_one = -1;
    bool only_ones = true;
    for (int i=MAX_E-1; i>=0; --i) {
        if ( n&(1<<i) ) {
            if (rightmost_one == -1)
                rightmost_one = i;
        }
        else if (rightmost_one != -1)
            only_ones = false;
    }

    if (only_ones) {
        cout << find_max_divisor(n) << '\n';
    } 
    else 
        cout << ((1<<(rightmost_one+1))-1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}