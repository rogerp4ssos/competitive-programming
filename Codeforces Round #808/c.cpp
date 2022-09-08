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

int n, q;

bool find_ans(int k, vector<int> &arr, vector<int> &ans) {
    int iq = q;

    for (int i=0; i<k; ++i) {
        if (arr[i] <= iq) ans[i] = 1;
        else ans[i] = 0;
    }
    for (int i=k; i<n; ++i) {
        if (!iq) return false; 
        
        ans[i] = 1;
        if (arr[i] > iq)
            --iq;
    }

    return true; 
}

void solve() {

    cin >> n >> q;
    vector<int> arr(n), ans(n, 0);

    for (int &x: arr) cin >> x;

    int l = -1; // find_ans(l) = false
    int r = n; // find_ans(r) = true
    while (l+1<r) {
        int mid = (r+l)/2;

        if (find_ans(mid, arr, ans)) 
            r = mid;
        else 
            l = mid;
    }

    // i=r is the min index such that find_ans(i) = true
    find_ans(r, arr, ans);
    for (int b: ans)
        cout << b;
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}