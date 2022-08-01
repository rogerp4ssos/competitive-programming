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

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n); 
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

vector<int> find_occurrences(string t, string s) {
    // KMP

    string to_find = s+'#'+t;

    vector<int> pi = prefix_function(to_find);

    vector<int> ans;
    for (int i=0; i<(int)to_find.length(); ++i) {
        if (pi[i] == (int)s.length()) 
            ans.push_back(i-2*(int)s.length());
    } 
    return ans;
}

vector<pii> minimal_coverage(vector<tiii> &intervals, int start, int end) {
    // given a set of segments, find the minimal subset that covers the integer interval [start, end]

    sort(all(intervals));
    intervals.push_back({INF,INF,INF});

    int curr_s = start, curr_e = -1;

    vector<pii> ans;
    for (int i=0; i<(int)intervals.size();) {
        int l = get<0>(intervals[i]), r = get<1>(intervals[i]);
        int indc = get<2>(intervals[i]);

        if (l <= curr_s) {
            if (r > curr_e) {
                if (i!=0)
                    ans.pop_back();
                ans.push_back({indc, l});

                curr_e = r;
            }
            ++i;
        }
        else {
            if (curr_e >= end or l>curr_e+1) 
                break;
            
            curr_s = curr_e+1;

            ans.push_back({indc, l});
        }
    }

    if (curr_e < end) 
        ans.clear();

    return ans;
}

void solve() {
    int n;
    string t, s;

    cin >> t;
    cin >> n;

    vector<tiii> intervals;
    for (int i=0; i<n; ++i) {
        cin >> s;

        vector<int> oc = find_occurrences(t, s);

        for (int l: oc) {
            int r = l+s.length()-1;

            intervals.push_back({l,r,i});
        }
    }

    int start = 0, end = (int)t.length()-1;
    vector<pii> ans = minimal_coverage(intervals, start, end);
   
    if (ans.empty()) {
        cout << "-1" << '\n';
        return;
    }

    cout << (int)ans.size() << '\n';
    for (auto a: ans) 
        cout << a.first+1 << ' ' << a.second+1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}