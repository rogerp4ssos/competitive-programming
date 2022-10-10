// g++ -std=c++17 -O2 -Wall a.cpp
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

    cin >> n;
    vector<int> a(n), b(n);
    int cnt1_a=0, cnt1_b=0;

    for (int &x: a) {
        cin >> x;
        if (x) ++cnt1_a;
    }
    for (int &x: b) {
        cin >> x;
        if (x) ++cnt1_b;
    }

    // equaling the number of 1-bits of a and b
    int ans = 0, diff = abs(cnt1_a-cnt1_b);
    for (int i=0; i<n; ++i) {
        if (diff) {
            if (a[i] != b[i]) { // flip
                a[i] = b[i];
                --diff;
                ++ans;
            }
        }
        else
            break;
    }
    
    // if necessary, rearranging
    for (int i=0; i<n; ++i) {
        if (a[i] != b[i]) {
            ++ans;
            break;
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