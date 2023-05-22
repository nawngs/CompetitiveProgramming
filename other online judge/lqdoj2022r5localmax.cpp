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

const string NAME = "LOCALMAX";
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

ll n, m, k, res = 0, f[20][20];

void back_track(int x, int y) {
	if (x == n + 1) {
		int dem = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				bool th = 1;
				for (int jj = 1; jj <= m; jj++) {
					if (jj == j) continue;
					if (f[i][j] <= f[i][jj]) {
						th = false;
						break;
					}
				}
				if (!th) continue;
				for (int ii = 1; ii <= n; ii++) {
					if (ii == i) continue;
					if (f[i][j] <= f[ii][j]) {
						th = false;
						break;
					}
				}
				dem += th;
			}
		}
		res = (res + dem + 1) % MOD;
		return ;
	}
	for (int i = 1; i <= k; i++) {
		f[x][y] = i;
		if (y == m) back_track(x + 1, 1);
		else back_track(x, y + 1);
	}
}

void sol() {
	cin >> n >> m >> k;
	res = 0;
	back_track(1, 1);
	cout << res << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
