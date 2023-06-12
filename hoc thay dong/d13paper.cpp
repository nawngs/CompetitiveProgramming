#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll c, n, m, k, cnt1[1003], cnt2[1003], pw[1003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

void sol() {
	cin >> c >> n >> m >> k;
	for (int i = 1; i <= max(m, n); i++)
		pw[i] = mu(i, c);
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++) {
			ll a = l, b = n - r + 1;
			ll val = ((pw[a] * pw[b]) % MOD) - (pw[a - 1] * pw[b] % MOD) - (pw[a] * pw[b - 1] % MOD) + (pw[a - 1] * pw[b - 1] % MOD);
			val %= MOD; val = (val + MOD) % MOD;
			cnt1[r - l + 1] = (cnt1[r - l + 1] + val) % MOD;
		}
	for (int l = 1; l <= m; l++)
		for (int r = l; r <= m; r++) {
			ll a = l, b = m - r + 1;
			ll val = ((pw[a] * pw[b]) % MOD) - (pw[a - 1] * pw[b] % MOD) - (pw[a] * pw[b - 1] % MOD) + (pw[a - 1] * pw[b - 1] % MOD);
			val %= MOD; val = (val + MOD) % MOD;
			cnt2[r - l + 1] = (cnt2[r - l + 1] + val) % MOD;
		}
	ll res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (i * j < k) continue;
			res = (res + cnt1[i] * cnt2[j]) % MOD;
		}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}