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

ll n, m, a[1003][1003], s[1003][1003], row[1003][3], col[1003][3], f[1003][1003];

ll total(ll u, ll v, ll x, ll y) {
	return (s[x][y] - s[x - 1][v - 1] - s[u - 1][y - 1] + s[u - 1][v - 1]) % 3;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			s[i][j] = (s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j] + 90) % 3;
		}
	memset(row, 255, sizeof(row));
	memset(col, 255, sizeof(col));
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++) col[i][0] = 0;
	for (int j = 1; j <= m; j++) row[j][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (row[j][(1 - s[i][j] + 90) % 3] != -1) f[i][j] = 1;
			if (f[i][j]) row[j][s[i][j]] = i;
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (col[i][(1 - s[i][j] + 90) % 3] != -1) f[i][j] = 1;
			if (f[i][j]) col[i][s[i][j]] = i;
		}
	}
	cout << f[n][m] << '\n';
}

int main() {
	fast;
	for (int TEST = 1; TEST <= 5; TEST++) sol();
}
