#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
const ll mod = 998244353;

int n, a[N];
ll fac[N], inv[N];

ll Exp(ll a, int b) {
    if (!b) return 1;
    ll tmp = Exp(a, b/2);
    tmp = tmp * tmp % mod;
    if (b&1) tmp = tmp * a % mod;
    return tmp;
}

ll C(int n, int k) {
    if (k > n) return 0;
    return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

using pii = pair<int, int>;
#define fi first
#define se second

vector<pii> exist;

int pre[N];
bool check(int l, int r) {

    return (pre[r] - pre[l-1] == 0 || l > r);
}

ll solve(int l, int r) {
    ll res = 1;
    //cout << "doan : " << l << " " << r << '\n';
    for (int i = 1; i < exist.size(); i++) {
        // cout << "doan : " << l << " " << r << '\n';
        int pos = exist[i].se;
        if (pos < l) {
            int b = a[pos] - (r - l + 1) - 1 - (l - pos - 1);

            if (b < 0 || r + b > n || !check(r+1, r+b)) return 0;

            res *= C(b + l - pos - 1, b);
            res %= mod;
            l = pos;
            r = l + a[pos] - 1;
        } else if (pos > r) {
            int b = a[pos] - (r - l + 1) - 1 - (pos - r - 1);
            if (b < 0 || l - b < 1 || !check(l-b, l-1)) return 0;

            res *= C(b + pos - r - 1, b);
            res %= mod;
            r = pos;
            l = pos - a[pos] + 1;
        } else return 0;
    }
    // cout << res << " " << l << " " << r << '\n';
    res *= C( l - 1 + n - r, l - 1);
//     cout << l << " " << r << " " << chia(n-r, l) << '\n';
    res %= mod;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("cinema.inp", "r", stdin);
    //freopen("cinema.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    fac[0] = 1;
    for (int i = 1; i <= N-5; i++)
    fac[i] = fac[i-1] * i % mod;

    inv[N-5] = Exp(fac[N-5], mod-2);

    for (int i = N-6; i >= 0; i--)
    inv[i] = inv[i+1] * (i+1) % mod;

    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) exist.emplace_back(a[i], i);
        pre[i] = pre[i-1] + (a[i] > 0);
    }

    sort(exist.begin(), exist.end());

    ll res = 0;
    if (exist.empty()) return cout << Exp(2, n-1), 0;
    if (exist[0].fi == 1) {
        res = solve(exist[0].se, exist[0].se);
    } else {
        int b = exist[0].fi - 1;
        if (exist[0].se - b > 0 && check(exist[0].se - b, exist[0].se-1)) {
            res += Exp(2, exist[0].fi-2) * solve(exist[0].se-b, exist[0].se) % mod;
            res %= mod;
        }
        // cout << res << '\n';
        if (exist[0].se + b <= n && check(exist[0].se + 1, exist[0].se + b)) {
            res += Exp(2, exist[0].fi-2) * solve(exist[0].se, exist[0].se+b) % mod;
            res %= mod;
        }
        // clog << Exp(2, exist[0].fi-2);
    }
    cout << res;
}
/*
10
0 0 0 0 3 0 0 7 0 0
*/