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

const string NAME = "solpin";
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

int n, m, a[1003][1003], s[1003][1003];

int main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= 2 * m; j++) {
			a[i][j] = a[i - n * (i > n)][j - m * (j > m)];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) 
		cout << s[i][1] << '\n';
	int row = 0, col = 0;
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 0) {
			int x, y; cin >> x >> y;
			row = (row + x) % m;
			col = (col + y) % n;
		}
		else {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			x1 += col;
			x2 += col;
			y1 += row;
			y2 += row;
			cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << '\n';
		}
	}
}
