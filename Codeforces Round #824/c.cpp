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
#define ALPHABET_SZ 26
#define MOD ((int)1e9+7)
  
void solve() {
    char c;
    int n;
    char next[ALPHABET_SZ];

    for (int i=0; i<ALPHABET_SZ; ++i)
        next[i] = '?';

    cin >> n;

    for (int i=0; i<n; ++i) {
        cin >> c;

        bool done = false;
        for (int j=0; j<ALPHABET_SZ; ++j) {
            if (next[j] == c) {
                cout << char(j+'a');
                done = true;
                break;
            }
        }

        if (done) continue;

        vector<bool> nope(ALPHABET_SZ, false);

        int k = c-'a';
        nope[k] = true;
        int cnt_nope = 1;
        while (next[k] != '?') {
            nope[k] = true;
            k = next[k]-'a';
            ++cnt_nope;
        }
        nope[k] = true;

        if (cnt_nope == ALPHABET_SZ)
            nope[k] = false;

        for (int j=0; j<ALPHABET_SZ; ++j) {
            if (!nope[j] and next[j] == '?') {
                cout << char(j+'a');
                next[j] = c;
                break;
            }
        }
    }

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