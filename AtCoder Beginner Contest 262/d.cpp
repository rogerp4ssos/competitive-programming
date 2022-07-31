// g++ -std=c++17 -O2 -Wall d.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 112
#define MOD 998244353

int n, tot;
int arr[MAX_N], mem[MAX_N][MAX_N][MAX_N];

int pd(int i, int cnt, int mod) {
    if (cnt==tot) return !mod;
    if (i==n+1) return 0;

    if (mem[i][cnt][mod]!=-1)
        return mem[i][cnt][mod];

    int a = pd(i+1, cnt+1, (mod+arr[i]%tot)%tot)%MOD;
    int b = pd(i+1, cnt, mod)%MOD;

    return mem[i][cnt][mod] = (a+b)%MOD;
}

void solve() {
    cin >> n;

    for (int i=1; i<=n; ++i)
        cin >> arr[i];

    ll ans = 0;
    for (int i=1; i<=n; ++i) { // foreach subset size
        tot = i;

        for (int j=0; j<=n; ++j) 
            for (int k=0; k<=tot; ++k) 
                for (int l=0; l<=tot; ++l)
                    mem[j][k][l] = -1;

        ans += pd(1, 0, 0);
        ans%=MOD;
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