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

const string NAME = "SHOTBALLRECT";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, a[403][403], row[403], col[403], f[403][5];

int main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	ll res = 0;
	for (int i = 1; i <= n; i++) // chon 4 hang
		for (int j = 1; j <= 4; j++)
			f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + row[i]);
	res = max(res, f[n][4]);

	for (int i = 1; i <= m; i++) // chon 4 cot
		for (int j = 1; j <= 4; j++)
			f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + col[i]);
	res = max(res, f[m][4]);

	for (int i = 1; i <= n; i++) { //chon 1 hang 
		for (int j = 1; j <= m; j++)
			for (int p = 1; p <= 3; p++)
				f[j][p] = max(f[j - 1][p], f[j - 1][p - 1] + col[j] - a[i][j]);
		res = max(res, row[i] + f[m][3]);
	}

	for (int i = 1; i <= m; i++) { // chon 1 cot
		for (int j = 1; j <= n; j++)
			for (int p = 1; p <= 3; p++)
				f[j][p] = max(f[j - 1][p], f[j - 1][p - 1] + row[j] - a[j][i]);
		res = max(res, col[i] + f[n][3]);
	}

	for (int i = 1; i <= n; i++) // chon 2 hang
		for (int j = i + 1; j <= n; j++) {
			for (int c = 1; c <= m; c++)
				for (int p = 1; p <= 2; p++)
					f[c][p] = max(f[c - 1][p], f[c - 1][p - 1] + col[c] - a[i][c] - a[j][c]);
			res = max(res, row[i] + row[j] + f[m][2]);
		}
	cout << res << '\n';
}
