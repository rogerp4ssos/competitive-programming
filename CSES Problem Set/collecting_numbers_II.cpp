// g++ -std=c++17 -O2 -Wall collecting_numbers_II.cpp
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
#define MOD ((int)1e9+7)

pii state(int pos, vector<pii>& numbers) {
    int a = (pos==0 ? 0:
            numbers[pos].second < numbers[pos-1].second);
    int b = (pos==sz(numbers)-1 ? 0:
            numbers[pos+1].second < numbers[pos].second);

    return {a, b};
}

int diff(pii x_prev, pii x) {
    return x.first-x_prev.first +  x.second-x_prev.second;
}

void solve() {
    int n, m, x, a, b;
 
    cin >> n >> m;
    vector<pii> numbers(n);

    for (int i=0; i<n; ++i) {
        cin >> x;
        numbers[i] = {x, i};
    }
 
    sort(all(numbers));

    vector<int> pos_map(n);
    for (int i=0; i<n; ++i) 
        pos_map[numbers[i].second] = i;

    int ans = 0;
    // initial ans
    for (int i=1; i<n; ++i) {
        if (numbers[i].second < numbers[i-1].second)
            ++ans;
    }

    while (m--) {
        cin >> a >> b;
        --a, --b;

        if (pos_map[a] > pos_map[b])
            swap(a,b);

        pii a_prev_s = state(pos_map[a], numbers);
        pii b_prev_s = state(pos_map[b], numbers);

        swap(numbers[pos_map[a]], numbers[pos_map[b]]);

        pii a_s = state(pos_map[a], numbers);
        pii b_s = state(pos_map[b], numbers);

        ans += diff(a_prev_s, a_s);
        ans += diff(b_prev_s, b_s);

        // intersection
        if (pos_map[b]-pos_map[a] == 1)
            ans -= a_s.second - a_prev_s.second;

        swap(pos_map[a], pos_map[b]);

        cout << ans+1 << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
    while (t--) solve();
 
    return 0;
}