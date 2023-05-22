#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll nmax = 200000;
const ll MOD = 1E9 + 7;

ll n, m, frac[nmax + 3], pow2[nmax + 3];

ll mu(ll a, ll b) {
    if (b == 0) return  1;
    ll x = mu(a, b / 2);
    x = (x * x) % MOD;
    if (b % 2 == 1) x = (x * a) % MOD;
    return x;
}

ll Ckn(ll k, ll n) {
    return (frac[n] * mu((frac[k] * frac[n - k]) % MOD, MOD - 2)) % MOD;
}

void solve() {
    cin >> n >> m;
    ll res = frac[2 * n];
    for (int i = 1; i <= m; i++) {
        ll cur = (Ckn(i, m) * frac[2 * n - i]) % MOD;
        cur = (cur * mu(2, i)) % MOD;
        if (i % 2 == 1) res -= cur;
        else res += cur;
        if (res < 0) res += MOD;
        if (res >= MOD) res -= MOD;
    }
    cout << res << '\n';
}

int main() {
    frac[0] = pow2[0] = 1;
    for (int i = 1; i <= nmax; i++) {
        frac[i] = (frac[i - 1] * i) % MOD;
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
    int t; cin >> t;
    while (t--) solve();
}
