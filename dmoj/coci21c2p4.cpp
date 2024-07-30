#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 50;
const int M = 2E4;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, l, a[N + 3], inv[M + 3], fac[M + 3];

int dp[N + 3][N + 3][M + 3];

int mul(int a, int b) {
	return 1ll * a * b % MOD;
}

void add(int &x, int y) {
	if ((x += y) >= MOD) x -= MOD;
}

int mu(int a, int b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

int C(int k, int n) {
	return mul(fac[n], mul(inv[n - k], inv[k]));
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> l;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[1][1][1] = 1;
	for (int i = 1; i < n; i++) 
	for (int j = 1; j <= i; j++)
	for (int len = 0; len <= l; len++) if (dp[i][j][len] != 0) {
		int &x = dp[i][j][len];
		// cout << i << " " << j << " " << len << " " << x << '\n';
		add(dp[i + 1][j + 1][len + 1], mul(x, j + 1));
		if (len + 2 * a[i + 1] - 1 <= l) 
			add(dp[i + 1][j - 1][len + 2 * a[i + 1] - 1], mul(x, j - 1));
		if (len + a[i + 1] <= l)
			add(dp[i + 1][j][len + a[i + 1]], mul(x, 2 * j));
	}
	// for (int len = 0; len <= l; len++) cout << len << " " << dp[n][1][len] << '\n';
	fac[0] = 1;
	for (int i = 1; i <= 2 * l; i++) fac[i] = mul(fac[i - 1], i);
	for (int i = 0; i <= 2 * l; i++) inv[i] = mu(fac[i], MOD - 2);
	int res = 0;
	for (int len = 0; len <= l; len++) add(res, mul(C(n, l - len + n), dp[n][1][len]));
	cout << res;
}
// n + 1