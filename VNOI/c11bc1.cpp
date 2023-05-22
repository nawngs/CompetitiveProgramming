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
const ll MOD = 790972;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, f[100003][53], g[100003][53];

pll city[100003];


void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> city[i].fi >> city[i].se;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i][0] = 1;
		for (int j = 1; j <= k; j++) {
			f[i][j] = f[i - 1][j - 1] * city[i].fi + f[i - 1][j];
			f[i][j] %= MOD;
		}
	}
	ll ans = f[n][k];
	sort(city + 1, city + 1 + n, [](pll &x, pll &y) {
		return x.se < y.se;
	});
	g[0][0] = 1;
	city[n + 1] = {1, -1};
	for (int i = 1; i <= n + 1; i++) {
			g[i][0] = 1;
			if (city[i].se == city[i - 1].se) {
			for (int j = 1; j <= k; j++) {
				g[i][j] = g[i - 1][j - 1] * city[i].fi + g[i - 1][j];
				g[i][j] %= MOD;
			}
		}
		else {
			ans = (ans - g[i - 1][k] + MOD) % MOD;
			g[i][1] = city[i].fi;
		}
		
	}
	cout << (ans + MOD) % MOD;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
