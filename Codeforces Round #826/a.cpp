// g++ -std=c++17 -O2 -Wall a.cpp
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
    string a, b;

    cin >> a >> b;

    int n = (int)a.size(), m = (int)b.size();

    if (a[n-1] > b[m-1]) 
        cout << "<\n";
    else if (a[n-1] < b[m-1]) 
        cout << ">\n";
    else {
        if (n == m)
            cout << "=\n";
        else if (a[n-1] == 'S') {
            if (n > m)
                cout << "<\n";
            else
                cout << ">\n";
        }
        else {
            if (n > m)
                cout << ">\n";
            else
                cout << "<\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}