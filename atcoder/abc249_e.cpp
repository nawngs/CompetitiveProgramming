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

ll n, p, dp[3003][3003], s[3003][3003];

vector < ll > tam = {1, 10, 100, 1000, 10000};


ll getlen(ll x) {
	ll res = 0;
	while (x > 0) {
		res ++;
		x /= 10;
	}
	return res;
}

ll mu(ll a, ll b, ll m) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2, m);
	x = (x * x) % m;
	if (b % 2 == 1) x = (x * a) % m;
	return x;
}

void sol() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++) dp[getlen(i) + 1][i] = 26 % p;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= 4; k++) {
				if (i - k - 1 < 0) break;
				if (i == getlen(j) + 1) continue;
				if (j < tam[k - 1]) continue;
				ll l = max(0ll, j - tam[k]), r = j - tam[k - 1];
				dp[i][j] += (s[i - k - 1][r] - s[i - k - 1][l]) * 25;
				dp[i][j] %= p;
			}
			s[i][j] = s[i][j - 1] + dp[i][j];
		}
	}
	ll res = 0;
	for (int i = 1; i < n; i++) res += dp[i][n];
	cout << res % p;
	
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
