// g++ -std=c++17 -O2 -Wall chessboard_and_queens.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define BRD_SZ 8
#define MOD ((int)1e9+7)
  
char board[BRD_SZ][BRD_SZ];
int ans, covered[BRD_SZ][BRD_SZ];

void mark(int i, int j, int val) { // row, col, (1 or -1)
    // vertical
    for (int k=i+1; k<BRD_SZ; ++k) 
        if (board[k][j] == '.')
            covered[k][j] += val;

    // diagonals
    for (int r=i+1, c=j+1; r>=0 and c>=0 and r<BRD_SZ and c<BRD_SZ; ++r, ++c) 
        if (board[r][c] == '.')
            covered[r][c] += val;
    for (int r=i+1, c=j-1; r>=0 and c>=0 and r<BRD_SZ and c<BRD_SZ; ++r, --c) 
        if (board[r][c] == '.')
            covered[r][c] += val;
}

void place_queens(int row) {
    if (row == BRD_SZ) {
        ++ans;
        return;
    }

    for (int j=0; j<BRD_SZ; ++j) {
        if (board[row][j] == '.' and covered[row][j]==0) {
            mark(row, j, 1);
            place_queens(row+1);
            mark(row, j, -1);
        }
    }
}

void solve() {
    for (int i=0; i<BRD_SZ; ++i)
        for (int j=0; j<BRD_SZ; ++j)
            cin >> board[i][j];

    place_queens(0);

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