// g++ -std=c++17 -O2 -Wall b.cpp
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
    int n, x, y;

    cin >> n >> x >> y;

    if (!(x==0 or y==0)) {
        cout << "-1\n";
        return;
    }

    if (x < y)
        swap(x,y);

    int a = 1, b = 2, curr_wins = 0;
    vector<int> ans;
    for (int i=1; i<n; ++i) {   
        if (curr_wins < x) {
            ans.push_back(a);
            ++b;
            ++curr_wins;
        }
        else {
            a = b;
            b = a+1;

            ans.push_back(a);
            curr_wins = 1;
        }
    }

    if (curr_wins != x) {
        cout << "-1\n";
        return;
    }

    for (int x: ans) cout << x << ' ';
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