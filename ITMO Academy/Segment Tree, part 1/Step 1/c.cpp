// g++ -std=c++17 -O2 -Wall c.cpp
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

typedef struct segTree {
	int sz;
	vector<pii> values; // first: mínimo, second: número de elementos iguais ao mínimo

	pii NEUTRAL_ELEMENT = {INF, 0};

	pii combine(pii a, pii b) {
		if (a.first < b.first) return a;
		if (a.first > b.first) return b;
		return {a.first, a.second+b.second};
	}

	pii single(int val) {
		return {val, 1};
	}

	void init(int n) {
		sz = 1;
		while (sz < n)
			sz<<=1;
		values.assign(2*sz, NEUTRAL_ELEMENT);
	}

	void build(vector<int> &arr, int node, int nl, int nr) {
		if (nl == nr) {
			if (nl < sz(arr))
				values[node] = single(arr[nl]);
			return;
		}
		int mid = (nl+nr)/2;
		build(arr, 2*node+1, nl, mid);
		build(arr, 2*node+2, mid+1, nr);

		values[node] = combine(values[2*node+1], values[2*node+2]);
	}

	void build(vector<int> &arr) {
		build(arr, 0, 0, sz-1);
	}

	void set(int idx, int val, int node, int nl, int nr) {
		if (nl == nr) { // folha
			values[node] = single(val);
			return;
		}
		int mid = (nl+nr)/2;
		if (idx <= mid)
			set(idx, val, 2*node+1, nl, mid);
		else
			set(idx, val, 2*node+2, mid+1, nr);

		values[node] = combine(values[2*node+1], values[2*node+2]);
	}
	
	void set(int idx, int val) {
		set(idx, val, 0, 0, sz-1);
	}

	pii calc(int l, int r, int node, int nl, int nr) {
		if (nl > r or l > nr) return NEUTRAL_ELEMENT; // sem interseção entre [l, r] e [nl, nr]
		if (nl >= l and nr <= r) return values[node]; // [nl, nr] está contido em [l, r]

		int mid = (nl+nr)/2;

		pii s1 = calc(l, r, 2*node+1, nl, mid);
		pii s2 = calc(l, r, 2*node+2, mid+1, nr);

		return combine(s1, s2);
	}

	pii calc(int l, int r) {
		return calc(l, r, 0, 0, sz-1);
	}
}segTree;

void solve() {
    int n, m, op, i, v, l, r;
    segTree st;

    cin >> n >> m;

    vector<int> arr(n);

    for (int &a: arr) cin >> a;

	st.init(n);
	st.build(arr);

	while (m--) {
		cin >> op;

		if (op == 1) {
			cin >> i >> v;

			st.set(i, v);
		}
		if (op == 2) {
			cin >> l >> r;
			--r; // interval: [l, r-1]

			// calculates the minimum and the number of elements equal to minimum of the segment
			pii ans = st.calc(l, r);
			cout << ans.first << ' ' << ans.second << '\n';
		}
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