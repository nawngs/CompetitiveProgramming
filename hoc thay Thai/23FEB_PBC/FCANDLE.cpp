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
const int NMAX = 5000;
const ll MOD = 1e9;
const ll BASE = 2309;

ll dp[5003], n, q, Ckn[5003][5003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	for (int i = 0; i <= NMAX; i++)
		for (int j = i; j <= NMAX; j++) {
			if (i == 0 || i == j) Ckn[i][j] = 1;
			else Ckn[i][j] = (Ckn[i][j - 1] + Ckn[i - 1][j - 1]) % MOD;
		}

	dp[0] = 1; dp[1] = 1; dp[2] = 1;
	for (int i = 3; i <= NMAX; i++) {
		if (i % 2 == 1) 
			for (int j = 1; j < i; j+=2) 
				dp[i] = (dp[i] + 2 * Ckn[j - 1][i - 2] % MOD * dp[j] % MOD * dp[i - j - 1]) % MOD;
		else 
			for (int j = 1; j < i; j++) 
				dp[i] = (dp[i] + Ckn[j - 1][i - 2] % MOD * dp[j] % MOD * dp[i - j - 1]) % MOD;
	}
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		vector < int > dg;
		int val = dp[x];
		while (val) {
			dg.pb(val % 10);
			val /= 10;
		}
		while (sz(dg) < 9) dg.pb(0);
		reverse(dg.begin(), dg.end());
		for (auto c : dg) cout << c;
		cout << '\n';
	}
}