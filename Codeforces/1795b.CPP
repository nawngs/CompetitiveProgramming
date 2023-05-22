#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    bool th1, th2; th1 = th2 = false;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        if (x == k) th1 = 1;
        if (y == k) th2 = 1;
    }
    cout << (th1 && th2 ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t--) solve();
}
