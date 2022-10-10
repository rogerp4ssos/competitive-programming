#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    string s;

    cin >> n >> c;

    vector<string> all_strings;

    for (int i=0; i<n; ++i) {
        cin >> s;
        for (int j=0; j<c; ++j) {
            if (s[j] == '*') {
                for (char k='a'; k<='z'; ++k) {
                    s[j] = k;
                    all_strings.push_back(s);
                }

                break;
            }
        }
    }

    sort(all(all_strings));

    string ans = all_strings[0];
    int max_cnt = 1;

    int cnt = 1;
    for (int i=1; i<(int)all_strings.size(); ++i) {
        if (all_strings[i] == all_strings[i-1])
            ++cnt;
        else {
            if (cnt > max_cnt) {
                ans = all_strings[i-1];
                max_cnt = cnt;
            }
            cnt = 1;
        }
    }

    if (cnt > max_cnt) {
        ans = all_strings.back();
        max_cnt = cnt;
    }

    cout << ans << ' ' << max_cnt << '\n';

    return 0;
}