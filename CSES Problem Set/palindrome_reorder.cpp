// g++ -std=c++17 -O2 -Wall palindrome_reorder.cpp
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
#define ALPHABET_SZ 26
#define MOD ((int)1e9+7)
  
void solve() {
    string s;
    cin >> s;

    vector<int> cnt(ALPHABET_SZ, 0);
    for (char c: s)
        cnt[c-'A']++;

    int cnt_odd = 0;
    for (int i=0; i<ALPHABET_SZ; ++i)
        if (cnt[i]%2 != 0) ++cnt_odd;

    if (cnt_odd > 1) {
        cout << "NO SOLUTION\n";
        return;
    }

    string ans = "";
    string mid = "";
    for (int i=0; i<ALPHABET_SZ; ++i) {
        if (cnt[i]%2 != 0) {
            mid = i+'A';
            --cnt[i];
        }
        ans.append(cnt[i]/2, i+'A');
    }
    ans += mid;

    for (int i=ALPHABET_SZ-1; i>=0; --i) 
        ans.append(cnt[i]/2, i+'A');

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