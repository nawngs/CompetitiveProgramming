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

const string NAME = "CutBoard";
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

int n, m, a[53][53], dp[53][53][53][53], s[53][53];

int calc(int u, int v, int x, int y) {
	return s[x][y] - s[u - 1][y] - s[x][v - 1] + s[u - 1][v - 1];
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		} 
	}
	for (int len_i = 1; len_i <= n; len_i++) {
		for (int len_j = 1; len_j <= m; len_j++) {
			if (len_i == 1 && len_j == 1) continue;
			for (int i = 1; i <= n - len_i + 1; i++) {
				for (int j = 1; j <= m - len_j + 1; j++) {
					int u = i + len_i - 1;
					int v = j + len_j - 1;
					int val = calc(i, j, u, v);
					dp[i][j][u][v] = MOD;
					for (int k = i; k < u; k++) dp[i][j][u][v] = min(dp[i][j][u][v], dp[i][j][k][v] + dp[k + 1][j][u][v] + val);
					for (int k = j; k < v; k++) dp[i][j][u][v] = min(dp[i][j][u][v], dp[i][j][u][k] + dp[i][k + 1][u][v] + val);
				}
			}
		}
	}
	cout << dp[1][1][n][m];
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
