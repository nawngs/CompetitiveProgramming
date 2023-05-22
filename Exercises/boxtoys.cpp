#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "boxtoys";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, cnt[23], dem1[(1 << 21)];

vector < ll > a[1000003];

ll val[103], dp[103][(1 << 15)];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

bool getbit(ll pos, ll x) {
	return (x & 1 << pos);
}

void sub1() {
	for (int i = 1; i <= n; i++) {
		for (auto x : a[i]) val[i] += (1 << (x - 1));
	}
	dp[1][val[1]] = 1;
	dp[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (1 << m); j++) {
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= MOD;
			dp[i + 1][j | val[i + 1]] += dp[i][j];
			dp[i + 1][j | val[i + 1]] %= MOD;
		}
	}
	cout << dp[n][(1 << m) - 1] << '\n';
}

void sub2() {
	for (int i = 1; i <= n; i++) {
		ll tam = 1;
		sort(a[i].begin(), a[i].end());
		int pos = 1;
		for (auto x : a[i]) {
			while (pos < x) {
				tam *= (1 << (pos - 1));
				pos ++;
			}
			pos ++;	
		}
		while (pos <= m) {
				tam *= (1 << (pos - 1));
				pos ++;
		}
		dem1[tam] ++;		
	}
	ll ans = mu(2, n);
	for (int i = 1; i < (2 << m); i++) {
		ll tam = dem1[i];
		int dem = 0;
		for (int j = 0; j < m; j++) {
			if (!getbit(j, i)) {
				int gt = i + (1 << j);
				tam += dem1[gt];
				dem ++;
			}
		}
		dem = m - dem;
		if (dem % 2 == 0) ans = (ans - tam + MOD) % MOD;
		else ans = (ans + tam) % MOD;
	}
	cout << ans;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		a[i].resize(k);
		for (auto &x : a[i]) cin >> x;
	}
	if (n <= 100 && m <= 15) sub1();
	else sub2();
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
