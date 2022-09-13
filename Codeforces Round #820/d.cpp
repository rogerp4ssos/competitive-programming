// g++ -std=c++17 -O2 -Wall d.cpp
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
    int n;

    cin >> n;
    vector<int> x(n), y(n);

    for (int &v: x) cin >> v;
    for (int &v: y) cin >> v;

    int zeros = 0;
    deque<int> pos, neg;
    for (int i=0; i<n; ++i) {
        if (x[i]==y[i])
            ++zeros;
        else if (y[i] > x[i])
            pos.push_back(y[i]-x[i]);
        else
            neg.push_back(x[i]-y[i]);
    }

    sort(all(pos));
    sort(all(neg));

    int ans = zeros/2;
    zeros = zeros%2;

    while (!pos.empty()) {
        int a = pos.front();
        pos.pop_front();

        if (neg.empty()) {
            if (!pos.empty()) {
                pos.pop_front();
                ++ans;
            }
            else
                ans += zeros;

            continue;
        }

        if (a >= neg.front()) {
            neg.pop_front();
            ++ans;
        }
        else {
            if (!pos.empty()) {
                int b = pos.front();
                pos.pop_front();

                if (b >= neg.front()) {
                    neg.pop_front();
                    pos.push_front(a);
                }

                ++ans;
            }
            else
                ans+=zeros;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}