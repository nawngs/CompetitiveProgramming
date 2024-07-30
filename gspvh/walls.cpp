#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
ll mod, euler, fac[N], inv[N];
vector<int> dp[10005];
const int tsnt[4] = {19, 127, 467, 907};

ll Exp(ll a, ll b) {
    if (!b) return 1;
    ll tmp = Exp(a, b/2);
    tmp = tmp * tmp % mod;
    if (b&1LL) tmp = tmp * a % mod;
    return tmp;
}
// chia m keo cho n nguoi
ll ckn(int k, int n) {
    if (k > n) return 0;
    return fac[n] * inv[k] % mod * inv[n-k] % mod;
}
ll chia(int m, int n) {
    return ckn(n-1, m+n-1);
}

void solve3() {
    int n, c;
    cin >> c >> n;
    ++c;
    cout << (chia(n, c) - 1 + mod) % mod << " ";
}

void solve4() {
    ll n, c;
    cin >> n >> c;
    ll res = 1;
    int cur = (n+1)%mod;
    for (ll i = n+1; i <= c + n; i++) {
        res = res * cur % mod;
        cur++;
        if (cur >= mod) cur -= mod;
    }
    cout << (res * Exp(fac[c], mod-2) % mod - 1 + mod) % mod << " ";
}

int cnt[N][4];
ll sum[N];
void solve5() {
    int n, c;
    cin >> n >> c;
    // ckn(n+c, c)
    ll res = 1;
    for (int i = 0; i < 4; i++)
    res = res * Exp(tsnt[i], cnt[n+c][i]-cnt[c][i]-cnt[n][i]) % mod;
    res *= (sum[n+c]*Exp(sum[c], euler-1)%mod*Exp(sum[n], euler-1)%mod);
    res %= mod;
    cout << (res - 1 + mod) % mod << " ";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("walls.inp", "r", stdin);
    freopen("walls.out", "w", stdout);
    int sub, t;
    cin >> sub >> t >> mod;
    fac[0] = 1;
    for (int i = 1; i <= N-5; i++)
        fac[i] = fac[i-1] * i % mod;
    if (sub == 3) {

        inv[N-5] = Exp(fac[N-5], mod-2);
        for (int i = N-6; i >= 0; i--)
            inv[i] = inv[i+1] * (i + 1) % mod;
        while (t--) solve3();
    }
    else if (sub == 4) while (t--) solve4();
    else if (sub <= 2) {
        for (int i = 0; i <= 10000; i++)
            dp[i].resize((i+1)/2 + 2);
        for (int i = 0; i < 10000; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= (i+1)/2; j++) {
                dp[i][j] = 0;
                if (i >= j) dp[i][j] += dp[i-1][min(j-1, i-j)];
                if (i - 1 >= j) dp[i][j] += dp[i-1][min(j, i-1-j)];
                dp[i][j] %= mod;
            }
        }

        while (t--) {
            int n, c;
            cin >> c >> n;
            cout << (dp[c+n][min(c, n)] - 1 + mod) % mod << " ";
        }
    } else {
        euler = 1;
        int tmp = mod;
        for (int i = 2; i * i <= tmp; i++) {
            int dem = 0;
            while (tmp % i == 0) ++dem, tmp /= i;
            for (int j = 1; j < dem; j++) euler *= i;
            if (dem > 0) euler *= (i-1);
        }
        if (tmp > 1) euler *= (tmp - 1);
        sum[0] = 1;
        for (int i = 1; i <= N-5; i++) {
            for (int j = 0; j < 4; j++)
                cnt[i][j] = cnt[i-1][j];
            int tmp = i;
            for (int j = 0; j < 4; j++) {
                while (tmp % tsnt[j] == 0)
                cnt[i][j]++, tmp /= tsnt[j];
            }
            sum[i] = sum[i-1] * tmp % mod;
        }
        while (t--) solve5();
    }

}
/*
2 8 1022071997
5 1
2 2
3 2
1 9
9 7
2 2
2 7
7 2
*/
