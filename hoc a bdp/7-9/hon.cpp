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

const string NAME = "hon";
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
	//freopen(fout.c_str(), "w", stdout);
}

ll n, a[253][253], dp[253][253][253][2], sze[253], kk, f[253][253][2];

pll maxa[253];

void maximize(ll &x, ll y) {
	x = max(x, y);
}

void solve1() {
	for (int i = 1; i < 2 * n; i++)
		for (int j = 0; j <= 2 * n; j++)
			for (int p = 0; p < 2; p++) f[i][j][p] = -LINF;
	for (int j = 1; j <= sze[1]; j++) {
		f[1][j][0] = a[1][j];
		f[1][j][1] = maxa[1].fi;
	}
	for (int i = 2; i < 2 * n; i++) {
		for (int j = 1; j <= sze[i]; j++) {
			vector < int > tempj;
			if (sze[i] > sze[i - 1]) {
				if (j < sze[i]) tempj.push_back(j);
				if (j - 1 > 0) tempj.push_back(j - 1);
			}
			else {
				tempj.push_back(j);
				tempj.push_back(j + 1);
			}
			for (auto x : tempj) {
				maximize(f[i][j][0], f[i - 1][x][0] + a[i][j]);
				maximize(f[i][j][1], f[i - 1][x][0] + maxa[i].fi);
				maximize(f[i][j][1], f[i - 1][x][1] + a[i][j]);
			}
			//cout << i << " " << j << " " << f[i][j][0] << " " << f[i][j][1] << '\n';
		}
	}
	ll res = -LINF;
	for (int j = 1; j <= sze[2 * n - 1]; j++) res = max(res, max(f[2 * n - 1][j][1], f[2 * n - 1][j][0]));
	cout << res;
}

void solve2() {
	for (int i = 1; i < 2 * n; i++)
		for (int j = 0; j <= 2 * n; j++)
			for (int k = 0; k <= 2 * n; k++)
				for (int p = 0; p < 2; p++) dp[i][j][k][p] = -LINF;
	for (int j = 1; j <= sze[1]; j++) 
		for (int k = j + 1; k <= sze[1]; k++) {
			dp[1][j][k][0] = a[1][j] + a[1][k];
			dp[1][j][k][1] = dp[1][j][k][0] - min(a[1][j], a[1][k]);
			if (max(a[1][j], a[1][k]) == maxa[1].fi) dp[1][j][k][1] += maxa[1].se;
			else dp[1][j][k][1] += maxa[1].fi;
			//cout << 1 << " " << j << " " << k << " " << dp[1][j][k][0] << " " << dp[1][j][k][1] << '\n'; 
		}
	for (int i = 2; i < 2 * n; i++) {
		for (int j = 1; j <= sze[i]; j++) {
			for (int k = j + 1; k <= sze[i]; k++) {
				vector < int > tempj, tempk;
				if (sze[i] > sze[i - 1]) {
					tempj.push_back(j);
					tempk.push_back(k - 1);
					if (k < sze[i]) tempk.push_back(k);
					if (j - 1 > 0) tempj.push_back(j - 1);
				}
				else {
					tempj.push_back(j);
					tempk.push_back(k);
					tempj.push_back(j + 1);
					tempk.push_back(k + 1);
				}
				for (auto xx : tempj) {
					for (auto yy : tempk) {
						if (xx == yy) continue;
						int x = min(xx, yy);
						int y = max(xx, yy);
						//if (i == 2 && j == 1 && k == 6) cout << x << " " << y << '\n';
						maximize(dp[i][j][k][0], dp[i - 1][x][y][0] + a[i][j] + a[i][k]);
						//if (i == 2 && j == 1 && k == 6) cout << dp[i][j][k][0] << '\n';
						maximize(dp[i][j][k][1], dp[i - 1][x][y][1] + a[i][j] + a[i][k]);
						maximize(dp[i][j][k][1], dp[i][j][k][0]);
						if (max(a[i][j], a[i][k]) == maxa[i].fi) 
							maximize(dp[i][j][k][1], dp[i - 1][x][y][0] + max(a[i][j], a[i][k]) + maxa[i].se);
						else maximize(dp[i][j][k][1], dp[i - 1][x][y][0] + max(a[i][j], a[i][k]) + maxa[i].fi);
					}
				}
				//cout << i << " " << j << " " << k << " " << dp[i][j][k][0] << " " << dp[i][j][k][1] << '\n'; 
			}
		}
	}
	ll res = -LINF;
	for (int i = 1; i < sze[2 * n - 1]; i++)
		for (int j = i + 1; j <= sze[2 * n - 1]; j++) {
			//cout << i << " " << j << " " << dp[2 * n - 1][i][j][1] << '\n';
			res = max(res, max(dp[2 * n - 1][i][j][0], dp[2 * n - 1][i][j][1]));
		}
	cout << res;
}

int main() {
	fast;
	//fre();
	cin >> n >> kk;
	for (int i = 1; i < 2 * n; i++) {
		maxa[i] = {-LINF, -LINF};
		if (i <= n) { 
			sze[i] = n + i - 1;
			for (int j = 1; j <= sze[i]; j++) {
				cin >> a[i][j];
				maxa[i].se = max(maxa[i].se, a[i][j]);
				if (maxa[i].se > maxa[i].fi) swap(maxa[i].se, maxa[i].fi);
			}
		}
		else {
			sze[i] = sze[2 * n - i];
			for (int j = 1; j <= sze[i]; j++) {
				cin >> a[i][j];
				maxa[i].se = max(maxa[i].se, a[i][j]);
				if (maxa[i].se > maxa[i].fi) swap(maxa[i].se, maxa[i].fi);
			}
		}
	}
	if (kk == 1) solve1();
	else solve2();
	
}
