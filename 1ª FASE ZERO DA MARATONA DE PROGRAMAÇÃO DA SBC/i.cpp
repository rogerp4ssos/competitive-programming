// g++ -std=c++17 -O2 -Wall i.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_E 18
#define MOD ((int)1e9+7)

map<ull, ull> mag;

int cnt_digits(ull n) {
    return floor(log10(n))+1;
}

void fill_mag() {
    ull idx = 1, pot = 1;
    mag[idx] = 1;
    for (int i=1; i<=MAX_E; ++i) {
        pot *= 10;

        idx += cnt_digits(pot/10)*(pot-pot/10);
        mag[idx] = pot;
    }
}

char find_digit(ull k) {
    if (k == 0)
        return '0';

    auto it = mag.upper_bound(k);
    --it;

    ull ref_idx = it->first;

    string number = to_string(mag[ref_idx] + (k-ref_idx)/cnt_digits(mag[ref_idx]));
    int dig = (k-ref_idx)%cnt_digits(mag[ref_idx]);

    return number[dig];
}

void solve() {
    int k;
    ull L, R;

    fill_mag();

    cin >> k >> L >> R;

    string subs = "";
    for (ull idx = L; idx <= R; ++idx)
        subs.append(1, find_digit(idx));

    ull ans = 0;
    for (int i=0; i<sz(subs); ++i) {
        string num = "";
        for (int j=i; j<i+k; ++j) {
            num.append(1, subs[j]);

            ull cand = stoull(num);

            ans = max(ans, cand);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}