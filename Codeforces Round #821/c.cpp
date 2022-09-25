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

    for (int &x: arr) cin >> x;

    vector<pii> aux, ans;
    for (int i=0; i<n; ++i)
        aux.push_back({arr[i], i});
    
    sort(all(aux));

    // putting the smallest number with same parity as a[0] in its place
    for (auto [v, i]: aux) {
        if (i==0)
            break;
        if (v%2 == arr[0]%2) {
            ans.push_back({0,i});
            arr[0] = v;
            break;
        }
    }

    // replacing all numbers with different parity for a[0]
    for (int i=0; i<n; ++i) {
        if (arr[i]%2 != arr[0]%2) {
            arr[i] = arr[0];
            ans.push_back({0,i});
        }
    }

    // ensuring non-decreasing order
    int mini = n-1;
    for (int i=n-2; i>=0; --i) {
        if (arr[i] > arr[mini]) {
            ans.push_back({i, mini});
            arr[i] = arr[mini];
        }
        else {
            mini = i;
        }
    }

    cout << (int)ans.size() << '\n';
    for (auto [l,r]: ans) cout << l+1 << ' ' << r+1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}