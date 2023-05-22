#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define cout cerr
#define db(val) "[" #val " = " << (val) << "] "
using namespace std;
const int maxn = 1e5 + 4;
const int N = 10;
const int INF = 1e9;
const ll mod = 1e9 + 7;

string a, b;
int n, k, d;
ll dp[20][1030][2][2], res[1030], finv[11];

ll Ckn(ll n, int k) {
    if (n < k) return 0;
    ll ans = finv[k];
    for (int i = 0; i < k; i++)
        ans = ans * ((n - i) % mod) % mod;
    return ans;
}

void Solve() {
    cin >> a >> b >> k >> d;
    while (a.size() < b.size()) a = '0' + a;
    n = a.size();
    memset(dp, 0, sizeof dp);
    memset(res, 0, sizeof res);
    dp[0][0][0][0] = 1;
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != '0') flag = 1;
        for (int mask = 0; mask < (1 << N); mask++) {
            for (int f1 = 0; f1 < 2; f1++)
                for (int f2 = 0; f2 < 2; f2++) {
                    int lo = f1 ? 0 : a[i] - '0';
                    int hi = f2 ? 9 : b[i] - '0';
                    for (int t = lo; t <= hi; t++) {
                        int nxtmask = f1 || flag || t > 0 ? mask | (1 << t) : mask;
                        dp[i + 1][nxtmask][f1 || t > lo][f2 || t < hi] += dp[i][mask][f1][f2];
                    }
                }
        }
    }
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int f1 = 0; f1 < 2; f1++)
            for (int f2 = 0; f2 < 2; f2++)
                res[mask] += dp[n][mask][f1][f2];
    }
    for (int i = 0; i < N; i++) 
        for (int mask = 0; mask < (1 << N); mask++)
            if (mask >> i & 1)
                res[mask ^ (1 << i)] += res[mask];
    ll ans = 0;
    for (int mask = 0; mask < (1 << N); mask++)
        if (__builtin_popcount(mask) == d) {
            for (int mask2 = 0; mask2 < (1 << N); mask2++) if ((mask2 & mask) == mask) {
                int num = __builtin_popcount(mask2) - d;
                (ans += (num & 1 ? -1 : 1) * Ckn(res[mask2], k)) %= mod;
            }
        }
    cout << (ans + mod) % mod << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    finv[10] = 283194722;
    for (ll i = 9; i >= 0; i--)
        finv[i] = finv[i + 1] * (i + 1) % mod;
    int t; cin >> t;
    while (t--) {
        Solve();
    }
}