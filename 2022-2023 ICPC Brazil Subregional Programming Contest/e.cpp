#include <bits/stdc++.h>

using namespace std;

#define MAX_H 1123456
#define MAX_N 512345
#define all(v) v.begin(), v.end()

vector<int> pos[MAX_H];
bool done[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x;
    cin >> n;

    vector<int> h(n);

    for (int i=0; i<n; ++i)  {
        cin >> x;

        h[i] = x;
        done[i] = false;
        pos[x].push_back(i);
    }

    int ans = 0;
    for (int i=0; i<n; ++i) {
        int j = i;

        if (!done[j])
            ans += 1;
        while (!done[j]) {
            int x = h[j];

            done[j] = true;

            auto it = lower_bound(all(pos[x-1]), j);

            if (it != pos[x-1].end()) {
                while (it != pos[x-1].end() and done[*it])
                    ++it;
                
                if (it == pos[x-1].end())
                    break;
                else
                    j = *it;
            }
            else
                break;
        }
    }

    cout << ans << '\n';

    return 0;
}