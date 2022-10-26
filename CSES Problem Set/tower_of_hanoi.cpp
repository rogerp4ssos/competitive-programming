// g++ -std=c++17 -O2 -Wall tower_of_hanoi.cpp
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
  
void solve_hanoi(int n, int left, int mid, int right) {
    if (n == 1) {
        cout << left << ' ' << right << '\n';
        return;
    }

    solve_hanoi(n-1, left, right, mid);
    cout << left << ' ' << right << '\n';
    solve_hanoi(n-1, mid, left, right);
}

void solve() {
    int n;

    cin >> n;

    cout << (1<<n)-1 << '\n';
    solve_hanoi(n, 1, 2, 3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}