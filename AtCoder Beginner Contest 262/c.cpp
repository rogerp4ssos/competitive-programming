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
  
void solve() {
    int n;

    cin >> n;
    vector<int> arr(n);

    for (int &x: arr) {
        cin >> x;
        --x;
    }

    ll cnt=0, ans=0;
    for (int i=0; i<n; ++i) {
        if (arr[i] == i) // to count fixed pairs
            ++cnt;
        else if (arr[arr[i]] == i) // swapped pairs
            ++ans;
    }
    ans/=2;
    ans += cnt*(cnt-1)/2;

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