// g++ -std=c++17 -O2 -Wall d.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 312345
#define MOD ((int)1e9+7)

const int K = floor(log2(MAX_N));

bool nope;
int lg[MAX_N+1];
int sparse_min[MAX_N][K+1], sparse_max[MAX_N][K+1];

int get_min(int L, int R) {
    int j = lg[R-L+1];
    return min(sparse_min[L][j], sparse_min[R - (1 << j) + 1][j]);
}

int get_max(int L, int R) {
    int j = lg[R-L+1];
    return max(sparse_max[L][j], sparse_max[R - (1 << j) + 1][j]);
}

int get_ans(int L, int R) {
    if (nope) return 0;

    if (L >= R) return 0;

    int mid = (L+R)/2;

    int min_l = get_min(L, mid);
    int max_l = get_max(L, mid);
    int min_r = get_min(mid+1, R);
    int max_r = get_max(mid+1, R);

    if ( !(max_r-min_r == (R-L)/2 and max_l-min_l == (R-L)/2) ) {
        nope = true;
        return 0;
    }

    bool to_swap = false;
    if (min_l > min_r)
        to_swap = true;

    return to_swap + get_ans(L, mid) + get_ans(mid+1, R);
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int &x: p) cin >> x;

    for (int i=0; i<n; ++i) 
        sparse_max[i][0] = sparse_min[i][0] = p[i];

    int K = lg[n];
    for (int j=1; j<=K; ++j) {
        for (int i = 0; i+(1<<j) <= n; ++i) {
            sparse_min[i][j] = min(sparse_min[i][j-1], sparse_min[i + (1 << (j-1))][j-1]);
            sparse_max[i][j] = max(sparse_max[i][j-1], sparse_max[i + (1 << (j-1))][j-1]);
        }
    }

    nope = false;
    int ans = get_ans(0, n-1);
    if (nope) 
        cout << "-1\n";
    else
        cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lg[1] = 0;
    for (int i = 2; i <= MAX_N; ++i)
        lg[i] = lg[i/2] + 1;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}