#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

using namespace std;

const int MOD = 998244353;
const int NMAX = 1E7;

ll n, k, a, b;

bool IsPrime[NMAX + 3];

vector < int > prime;

void sieve() {
    for (int i = 2; i <= NMAX; i++)
        IsPrime[i] = 1;
    for (int i = 2; i * i <= NMAX; i++)
        if (IsPrime[i])
            for (int j = i * i; j <= NMAX; j+=i)
                IsPrime[j] = false;
    for (int i = 2; i <= NMAX; i++) {
        if (IsPrime[i]) prime.push_back(i);
    }
}

ll mu(ll a, ll b) {
    if (b == 0) return 1;
    ll x = mu(a, b / 2);
    x = (x * x) % MOD;
    if (b % 2 == 1) x = (x * a) % MOD;
    return x;
}

namespace sub2 {
    map < int, int > fk, f[33], tmp;
    int res2 = 0;
    void back_track(int pos) {
        if (pos == n + 1) {
            for (auto x : fk)
                if (tmp[x.fi] < x.se) return ;
            res2 ++;
            return ;
        }
        for (int i = a; i <= b; i++) {
            for (auto x : f[i - a]) tmp[x.fi] += x.se;
            back_track(pos + 1);
            for (auto x : f[i - a]) tmp[x.fi] -= x.se;
        }
    }
    void solve() {
        ll val = k;
        for (auto x : prime) {
            while (val % x == 0) {
                fk[x] ++;

                val /= x;
            }
        }
        if (val != 1) fk[val] ++;
        for (ll i = a; i <= b; i++) {
            val = i;
            for (auto x : prime) {
                while (val % x == 0) {
                    f[i - a][x] ++;
                    val /= x;
                }
            }
            if (val != 1) f[i - a][val] ++;
        }
        res2 = 0;
        back_track(1);
        cout << res2 << '\n';
    }
}

namespace sub4 {
    ll fac[303], inv[303];
    ll C(ll k, ll n) {
        return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
    }
    void solve() {
        fac[0] = 1; inv[0] = mu(fac[0], MOD - 2);
        for (int i = 1; i <= n; i++) {
            fac[i] = (fac[i - 1] * i) % MOD;
            inv[i] = mu(fac[i], MOD - 2);
        }
        ll div = b / k - (a + k - 1) / k + 1;
        ll total = 0;
        for (int i = 1; i <= n; i++) {
            if (i & 1) total = (total + C(i, n) * mu(div, i) % MOD * mu((b - a + 1) % MOD, n - i)) % MOD;
            else total = (total - C(i, n) * mu(div, i) % MOD * mu((b - a + 1) % MOD, n - i)) % MOD;
            total = (total + MOD) % MOD;
        }
        cout << total << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("debaisieungan.inp", "r", stdin);
    freopen("debaisieungan.out", "w", stdout);
    sieve();
    //cout << prime.size() << '\n';
    cin >> n >> k >> a >> b;
    if (k == 1) {
        cout << mu((b - a + 1) % MOD, n) << '\n';
        return 0;
    }
    if (n <= 5 && b - a <= 30) {
        sub2::solve();
        return 0;
    }
    sub4::solve();
}


