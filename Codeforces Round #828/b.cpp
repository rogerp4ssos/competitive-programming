// g++ -std=c++17 -O2 -Wall b.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 112345
#define MOD ((int)1e9+7)
  
void solve() {
    int n, q, t, x;
    ll cnt_odd = 0, cnt_even = 0, sum_odd = 0, sum_even = 0;

    cin >> n >> q;
    
    while (n--) {
        cin >> x;

        if (x%2 == 0) {
            sum_even += x;
            ++cnt_even;
        }
        else {
            sum_odd += x;
            ++cnt_odd;
        }
    }

    while (q--) {
        cin >> t >> x;

        if (t == 0) {
            sum_even += cnt_even*x;
            if (x%2 != 0) {
                sum_odd += sum_even;
                cnt_odd += cnt_even;

                sum_even = cnt_even = 0;
            }
        }
        else {
            sum_odd += cnt_odd*x;
            if (x%2 != 0) {
                sum_even += sum_odd;
                cnt_even += cnt_odd;

                sum_odd = cnt_odd = 0;
            }
        }

        cout << sum_even + sum_odd << '\n';
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