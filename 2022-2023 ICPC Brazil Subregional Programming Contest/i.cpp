#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int b;
    bool ok = true;
    for (int i=0; i<8; ++i) { 
        cin >> b;

        if (b == 9)
            ok = false;
    }

    if (ok) cout << "S\n";
    else cout << "F\n";

    return 0;
}