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
  
void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int &x: arr) {
        cin >> x;
        
        x += x%10;
        x += x%10;
    }
    
    bool ref = ( (arr[0]%10) == 0); // first element cannot be changed

    for (int x: arr) {
        if (( (x%10)==0 ) != ref) {
            cout << "NO\n";
            return;
        }
    }

    if (!ref) { // every element with arr[i]%10 != 0 (can be changed)
        for (int &x: arr) {
            while (x%10 != 2) // equalizing mods 
                x += x%10;
        }
    }

    // checking if all elements are already or can be made equal
    int mod = 2+4+8+6;
    for (int i=1; i<n; ++i) {
        if ((arr[i]%10 == 0 and arr[i]!=arr[i-1]) or arr[i]%mod != arr[i-1]%mod) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}