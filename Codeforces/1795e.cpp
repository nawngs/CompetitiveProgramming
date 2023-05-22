#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, a[300003], s[300003], f[300003], g[300003];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = i;
        if (a[i] - 1 >= a[i - 1]) f[i] = f[i - 1];
    }
    g[n] = n;
    for (int i = n - 1; i >= 1; i--) {
        g[i] = i;
        if (a[i] - 1 >= a[i + 1]) g[i] = g[i + 1];
    }
    ll res = 1e15;
    for (int i = 1; i <= n; i++) {
        cout << i << " " << f[i] << " " << g[i] << '\n';
        res = min(res, s[f[i] - 1] + a[i] + (s[n] - s[g[i]]));
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t--) solve();
}
