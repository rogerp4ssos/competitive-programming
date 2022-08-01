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

int s, mem[112];

bool check_digit(int n, int dig) {
    if (n==dig)
        return true;

    while (n!=0) {
        int left = n%10;
        if (left == dig) return true;

        n/=10;
    }
    return false;
}

int cnt_digit(int n) {
    return floor(log10(n) + 1);
}

int pd(int s) {
    if (s<=9)
        return s;
    if (mem[s] != -1)
        return mem[s];

    int ans = INF;
    for (int i=1; i<=9; ++i) {
        if (i <= s) {        
            int aux = pd(s-i);

            if (!check_digit(aux, i))
                ans = min(ans, i*(int)pow(10,cnt_digit(aux))+aux);
        }
    }

    return mem[s] = ans;
}

void solve() {
    cin >> s;

    cout << pd(s) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(mem, -1, sizeof mem);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}