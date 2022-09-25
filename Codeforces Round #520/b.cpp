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

unordered_map<int,int> factorize(int n) {
    unordered_map<int,int> ans;

    int k = n;
    while (k%2 == 0) {
        ans[2]+=1;
        k/=2;
    }

    for (int i=3; i*i<=n; i+=2) {
        while (k%i == 0) {
            ans[i]+=1;
            k/=i;
        }
    }

    if (k>1)
        ans[k]+=1;
    return ans;
}

void solve() {
    int n, min_n = 1, op = 0;

    cin >> n;

    unordered_map<int,int> factors = factorize(n);

    int max_cnt = 1;
    for (auto [p, cnt]: factors) {
        max_cnt = max(cnt, max_cnt);

        min_n*=p;
    }

    if ( (max_cnt&(max_cnt-1)) != 0 ) { // if max_cnt is not a power of two
        int rightmost_one = 0;
        for (int i=0; i<32; ++i) {
            if ((max_cnt&(1<<i)) != 0)
                rightmost_one = i;
        }

        max_cnt = 1<<(rightmost_one+1); // make it the next power of two > max_cnt
    }

    for (auto [p, cnt]: factors) {
        if (cnt != max_cnt) {
            ++op;
            break;
        }
    }

    while (max_cnt%2 == 0) {
        max_cnt/=2;
        ++op;
    }

    cout << min_n << ' ' << op << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}