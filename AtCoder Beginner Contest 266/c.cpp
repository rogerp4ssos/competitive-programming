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

typedef struct pt {
    int x, y;

    pt operator-(pt p) {
        return {x-p.x, y-p.y};
    }
}pt;

int cross(pt a, pt b) {
    return a.x*b.y - a.y*b.x;
}

int signed_area_parallelogram(pt a, pt b, pt c) {
    return cross(b-a, c-b);
}

int orientation(pt a, pt b, pt c) {
    int area = signed_area_parallelogram(a, b, c);
    if (area < 0) return -1; // clockwise
    if (area > 0) return +1; // counter clockwise
    return 0;
}

void solve() {

    vector<pt> quad(4);
    for (pt &p: quad)
        cin >> p.x >> p.y;

    bool f = 1;
    for (int i=0; i<4; ++i) {
        pt a = quad[i];
        pt b = quad[(i+1)%4];
        pt c = quad[(i+2)%4];

        if (orientation(a,b,c)!=1)
            f=0;
    }
    
    if (f)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}