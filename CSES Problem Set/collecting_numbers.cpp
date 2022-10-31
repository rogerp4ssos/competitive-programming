// g++ -std=c++17 -O2 -Wall collecting_numbers.cpp
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
    int n, x;
 
    cin >> n;
    vector<pii> numbers(n);
 
    for (int i=0; i<n; ++i) {
        cin >> x;
        numbers[i] = {x, i};
    }
 
    sort(all(numbers));
    
    int ans = 1;
    for (int i=1; i<n; ++i) {
        if (numbers[i].second < numbers[i-1].second)
            ++ans;
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