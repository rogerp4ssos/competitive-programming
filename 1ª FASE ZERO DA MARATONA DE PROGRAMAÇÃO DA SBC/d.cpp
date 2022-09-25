// g++ -std=c++17 -O2 -Wall d.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 21
#define MOD ((int)1e9+7)

int n, m, mem[21][21];
string r, s;

int dp(int i, int j) {
    if (i == n) 
        return m-j;
    if (j == m) 
        return n-i;

    if (mem[i][j] != -1) return mem[i][j];

    if (r[i] == s[j])
        return mem[i][j] = dp(i+1, j+1);
    return mem[i][j] = min({dp(i+1,j), dp(i, j+1), dp(i+1,j+1)}) + 1;
}

void solve() {
    int k;
    cin >> k;

    vector<double> pts(6, 0);

    while (k--) {
        cin >> r;
        n = r.size();

        int best = INF;
        vector<int> students;
        for (int i=1; i<=5; ++i) {
            cin >> s;
            m = s.size();

            memset(mem, -1, sizeof(mem));
            int changes = dp(0,0);

            if (changes < best) {
                students.clear();

                best = changes;
                students.push_back(i);
            }
            else if (changes == best)
                students.push_back(i);
        }

        if (best == 0) 
            for (int a: students) pts[a]+=1;
        else
            for (int a: students) pts[a]+=0.5;
    }

    double max_pts = *max_element(all(pts));
    vector<int> ans;
    for (int i=1; i<=5; ++i)
        if (fabs(pts[i]-max_pts) < DBL_EPSILON)
            ans.push_back(i);

    cout << fixed << setprecision(1) << max_pts << '\n';
    cout << ans[0];
    for (int i=1; i<(int)ans.size(); ++i)
        cout << ' ' << ans[i];
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}