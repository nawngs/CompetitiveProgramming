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

const string NAME = "PairStr";
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

ll dp[2003][2003], n, k, tich[2003];

string s[2003];

vector < ll > a;

void create() {
	tich[0] = 1;
	for (int i = 1; i <= 2000; i++) tich[i] = (tich[i - 1] * i) % MOD;
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll calc_c(ll k, ll n) {
	ll tam = (tich[k] * tich[n - k]) % MOD;
	return (tich[n] * mu(tam, MOD - 2)) % MOD;
}



void sol() {
	cin >> n >> k;
	create();
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
	}
	sort(s + 1, s + n + 1);
	int dem = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i] == s[i - 1]) dem ++;
		else {
			a.push_back(dem);
			dem = 1;
		}
	}
	a.push_back(dem);
	dp[0][0] = 1;
	for (ll i = 1; i <= a[0]; i++) if (i * (i - 1) / 2 <= k) dp[0][i * (i - 1) / 2] += calc_c(i, a[0]);
	for (int i = 1; i < a.size(); i++) {
		for (ll j = 0; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			for (ll t = 1; t <= a[i]; t++) {
				if (t * (t - 1) / 2 > j) break;
				dp[i][j] = (dp[i][j] + (calc_c(t, a[i]) * dp[i - 1][j - (t * (t - 1) / 2)]) % MOD) % MOD;
			}
		}
	}
	cout << dp[a.size() - 1][k];
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
