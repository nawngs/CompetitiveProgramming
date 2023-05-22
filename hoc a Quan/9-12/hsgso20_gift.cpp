#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = -301;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, dp[303][90000 - base + 5];

pll a[303];

int get_id(int x) {
	return x - base; 
}

void add(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

ll calc(ll x) {
	if (x < -300) return 0;
	memset(dp, 0, sizeof(dp));
	for (int i = a[1].fi; i <= a[1].se; i++)
		dp[1][get_id(i)] = 1;
	for (int i = -300; i <= x; i++)
		add(dp[1][get_id(i)], dp[1][get_id(i) - 1]);
	for (int i = 2; i <= n; i++) 
		for (int j = a[i].fi; j <= x; j++) {
			if (a[i].fi <= j && j <= a[i].se) 
				add(dp[i][get_id(j)], dp[i - 1][get_id(-1)]);
			int val_l = max(-1ll, j - a[i].se - 1);
			int val_r = min(j - a[i].fi, x * 1ll);
			//if (i == 4 && j == -4) cout << val_r << " " << dp[i][get_id(j)] << " " << dp[i - 1][get_id(val_l) - 1] << '\n';
			if (val_r >= -300 && val_r >= val_l) 
				add(dp[i][get_id(j)], dp[i - 1][get_id(val_r)] - dp[i - 1][max(0, get_id(val_l))]);
			add(dp[i][get_id(j)], dp[i][get_id(j) - 1]);
		}
	return dp[n][get_id(x)];
}

int main() {
	fast;
	//fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].fi >> a[i].se;
	cout << (calc(k) -calc(k - 1) + MOD) % MOD << '\n';
}