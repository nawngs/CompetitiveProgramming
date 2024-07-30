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
const int NMAX = 1e6;
const int LG = 20;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll dp[NMAX + 3][LG + 3], f[NMAX + 3];

void sieve() {
	for (int i = 1; i <= NMAX; i++) f[i] = i;
	for (int i = 2; i * i <= NMAX; i++) if (f[i] == i)
		for (int j = i * i; j <= NMAX; j+=i) f[j] = i;
}

void sol() {
	int r, n; cin >> r >> n;
	ll res = 1;
	while (n != 1) {
		int div = f[n], cnt = 0;
		while (n % div == 0) cnt ++, n /= div;
		res = (res * dp[r][cnt]) % MOD;
	}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	sieve();
	for (int i = 1; i <= LG; i++) dp[0][i] = 2;
	for (int i = 0; i <= NMAX; i++) dp[i][0] = 1;
	for (int i = 1; i <= NMAX; i++)
		for (int j = 1; j <= LG; j++) 
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
	int t; cin >> t; while (t --) sol();
}