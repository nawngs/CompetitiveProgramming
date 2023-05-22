#include <bits/stdc++.h>

#define int ll
#define ll long long

using namespace std;

const ll INF = 1E17;
const ll nmax = 3e5;

ll n, q, a[4][nmax + 3], it[8 * nmax + 3], lazy[8 * nmax + 3], dp[4][nmax + 3];

struct Key {
    ll l, r, k;
} b[nmax + 3];


main() {
    cin >> n >> q;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 1; i <= q; i++) cin >> b[i].l >> b[i].r >> b[i].k;
    sort(b + 1, b + q + 1, [&](Key &x, Key &y) {
        return x.l < y.l;
    });
    for (int j = 1; j <= n; j++) dp[1][j] = dp[1][j - 1] + a[1][j];
}
