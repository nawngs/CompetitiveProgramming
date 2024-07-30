#include <bits/stdc++.h>

#define name "compstr"
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
const int NMAX = 5e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int lcs[NMAX + 3][NMAX + 3], f[NMAX + 3][NMAX + 3], g[NMAX + 3][NMAX + 3], n, dp[NMAX + 3];

string s; 

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> s; n = s.size(); s = ' ' + s;
	for (int i = n; i >= 1; i--)
	for (int j = n; j >= 1; j--) {
		lcs[i][j] = (s[i] == s[j] ? lcs[i + 1][j + 1] + 1 : 0);
		g[i][j] = INF;
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= n - i + 1; j++) {
			f[i][j] = (lcs[i][i + j] >= j ? f[i + j][j] : i + j - 1);
			for (int k = i + j - 1; k <= f[i][j]; k+=j) g[i][k] = min(g[i][k], j);
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
		for (int j = i; j >= 1; j--) {
			int num = (i - j + 1) / g[j][i];
			int dem = 1, cur = 10;
			while (cur <= num) dem ++, cur *= 10;
			dp[i] = min(dp[i], dp[j - 1] + g[j][i] + dem);
		}
	}
	cout << dp[n];
}