// g++ -std=c++17 -O2 -Wall a.cpp
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
	vector<ll> sums;

	void init(int n) {
		sz = 1;
		while (sz < n)
			sz<<=1;
		sums.assign(2*sz, 0ll);
	}

	void build(vector<ll> &arr, int node, int nl, int nr) {
		if (nl == nr) {
			if (nl < sz(arr))
				sums[node] = arr[nl];
			return;
		}
		int mid = (nl+nr)/2;
		build(arr, 2*node+1, nl, mid);
		build(arr, 2*node+2, mid+1, nr);

		sums[node] = sums[2*node+1] + sums[2*node+2];
	}

	void build(vector<ll> &arr) {
		build(arr, 0, 0, sz-1);
	}

	void set(int idx, int val, int node, int nl, int nr) {
		if (nl == nr) { // folha
			sums[node] = val;
			return;
		}
		int mid = (nl+nr)/2;
		if (idx <= mid)
			set(idx, val, 2*node+1, nl, mid);
		else
			set(idx, val, 2*node+2, mid+1, nr);

		sums[node] = sums[2*node+1] + sums[2*node+2];
	}
	
	void set(int idx, int val) {
		set(idx, val, 0, 0, sz-1);
	}

	ll sum(int l, int r, int node, int nl, int nr) {
		if (nl > r or l > nr) return 0; // sem interseção entre [l, r] e [nl, nr]
		if (nl >= l and nr <= r) return sums[node]; // [nl, nr] está contido em [l, r]

		int mid = (nl+nr)/2;

		ll s1 = sum(l, r, 2*node+1, nl, mid);
		ll s2 = sum(l, r, 2*node+2, mid+1, nr);

		return s1+s2;
	}

	ll sum(int l, int r) {
		return sum(l, r, 0, 0, sz-1);
	}
}segTree;

void solve() {
    int n, m, op, i, v, l, r;
    segTree st;

    cin >> n >> m;

    vector<ll> arr(n);

    for (ll &a: arr) cin >> a;

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

			cout << st.sum(l, r) << '\n';
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