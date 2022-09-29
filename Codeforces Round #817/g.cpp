// g++ -std=c++17 -O2 -Wall g.cpp
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

int xor_sum(vector<int> v) {
    int ans = 0;
    for (int x: v) 
        ans^=x;
    return ans;
}
  
void solve() {
    int n;
    vector<int> odd, even;
    cin >> n;


    if (n%4 == 1) { 
        even.push_back(0);
        n-=1;
    }
    else if (n%4 == 2) {
        even.insert(even.end(), {2,3,4});
        odd.insert(odd.end(), {1,8,12});
        n-=6;
    }
    else if (n%4 == 3) {
        even.insert(even.end(), {2,3});
        odd.push_back(1);
        n-=3;
    }

    for (int i=10; i<10+(n/2); ++i) {
        // (2*i^(2*i+1)) == 1  
        if (i%2) {
            even.push_back(2*i);
            even.push_back(2*i+1);
        }
        else {
            odd.push_back(2*i);
            odd.push_back(2*i+1);
        }
    }

    // checking answer
    // cout << xor_sum(odd) << ' ' << xor_sum(even) << "*\n";

    for (int i=0; i<(int)odd.size(); ++i) 
        cout << even[i] << ' ' << odd[i] << ' ';
    if (even.size() > odd.size())
        cout << even.back();
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