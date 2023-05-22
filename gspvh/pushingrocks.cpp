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

ll n, m, s[2][2003][2003], f[2][2003][2003];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			s[0][i][j] = s[1][i][j] = (c == 'R');
		}
	for (int i = n; i >= 1; i--) 
		for (int j = m; j >= 1; j--) {
			s[0][i][j] += s[0][i + 1][j];
			s[1][i][j] += s[1][i][j + 1];
			//cout << i << " " << j << " " << s[0][i][j] << " " << s[1][i][j] << '\n';
		}
	f[0][1][1] = f[1][1][1] = 1;
	f[0][1][2] = f[1][2][1] = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//if (i == 1 && j == 1) continue;
			// di xuong
			f[0][i][j + 1] = (f[0][i][j] + f[0][i][j + 1]) % MOD;
			f[1][i + 1][j] = (f[1][i + 1][j] + f[0][i][j]) % MOD;
			f[1][n - s[0][i][j] + 1][j] = (f[1][n - s[0][i][j] + 1][j] - f[0][i][j] + MOD) % MOD;
			// di sang
			f[1][i + 1][j] = (f[1][i][j] + f[1][i + 1][j]) % MOD;
			f[0][i][j + 1] = (f[0][i][j + 1] + f[1][i][j]) % MOD;
			f[0][i][m - s[1][i][j] + 1] = (f[0][i][m - s[1][i][j] + 1] - f[1][i][j] + MOD) % MOD; 
			cout << i << " " << j << " " << f[0][i][j] << " " << f[1][i][j] << '\n';
		}
	}
	cout << (f[0][n][m] + f[1][n][m]) % MOD;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
