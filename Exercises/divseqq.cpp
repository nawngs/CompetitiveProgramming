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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, q, m, a[100003], dp[100003][35];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = x * x;
	if (b % 2 == 1) x *= a;
	return x;
}

void init() {
	for (int j = 1; j <= 32; j++)
		for (int i = 1; i <= n; i++) if (dp[i][j - 1] != 0) dp[i][j] = dp[dp[i][j - 1]][j - 1];
}

ll query(ll u, ll v) {
	for (int j = 32; j >= 0; j--) {
		if (v >= mu(2, j)) {
			v -= mu(2, j);
			u = dp[u][j];
		}
	}
	if (u < 0) u = 0;
	return u + 1;
}

void sol() {
	cin >> n >> q >> m;
	ll s = 0;
	ll l = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
		while (s > m) s -= a[l++];
		dp[i][0] = l - 1;
	}
	init();
	while (q --) {
		int u, v;
		cin >> u >> v;
		cout << query(u, v) << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
