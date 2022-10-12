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

    int ans = n, first_seg_sum = 0;
    // r of the first segment
    for (int r=0; r<n-1; ++r) {
        first_seg_sum += arr[r];

        int thickness = r+1, next_seg_sum = 0, next_seg_size = 0;
        for (int i=r+1; i<n; ++i) {
            next_seg_sum += arr[i];
            next_seg_size += 1;

            if (next_seg_sum == first_seg_sum) {
                thickness = max(thickness, next_seg_size);
                next_seg_size = next_seg_sum = 0;
            }
            else if (next_seg_sum > first_seg_sum) {
                thickness = INF;
                break;
            }
        }

        if (next_seg_sum and next_seg_sum < first_seg_sum) 
            thickness = INF;

        ans = min(ans, thickness);
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