// g++ -std=c++17 -O2 -Wall grid_paths.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define GRID_SZ 9
#define PATH_SZ 48
#define MOD ((int)1e9+7)

bool marked[GRID_SZ][GRID_SZ];
string target;
int cnt;

bool closed(int i, int j) {
	if ((marked[i+1][j] and marked[i-1][j] and !marked[i][j+1] and !marked[i][j-1]) or 
		(!marked[i+1][j] and !marked[i-1][j] and marked[i][j+1] and marked[i][j-1])) 
		return true;
	return false;
}

void calc(int i, int j, int idx) {
	if (i<=0 or i>=8 or j<=0 or j>=8)
		return;
	if (marked[i][j] or closed(i, j))
		return;

	if (i == 7 and j == 1) {
		if (idx == PATH_SZ)
			++cnt;
		return;
	}

	marked[i][j] = true;

	switch(target[idx]) {
		case 'U':
			calc(i-1, j, idx+1);
			break;
		case 'R':
			calc(i, j+1, idx+1);
			break;
		case 'D':
			calc(i+1, j, idx+1);
			break;
		case 'L':
			calc(i, j-1, idx+1);
			break;
		case '?':
			calc(i-1, j, idx+1);
			calc(i, j+1, idx+1);
			calc(i+1, j, idx+1);
			calc(i, j-1, idx+1);
			break;
	}

	marked[i][j] = false;
}

void solve() {
    cin >> target;

    for (int i=0; i<GRID_SZ; ++i)
    	marked[0][i] = marked[8][i] = marked[i][8] = marked[i][0] = true;

    calc(1, 1, 0);

    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}