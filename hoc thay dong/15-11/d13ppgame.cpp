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

int n, m, d, dp[363][363][363][2];

vector < pii > pos[363];

string s[363];

void add(int &x, const int &y) {
	x = x + y;
	if (x > d) x -= d;
}

int main() {
	fast;
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int dis = i + j - 1;
			if (dis <= (n + m) / 2) pos[dis].push_back({i, j}); 
		}
	}
	dp[1][1][n][0] = (s[1][1] == s[n][m]);
	dp[1][1][n][1] = 1 - dp[1][1][n][0];
	for (int len = 2; len <= (n + m) / 2; len++) {
		for (auto p : pos[len]) {
			int i = p.fi, j = p.se;
			for (int x = n; x >= i; x--) {
				int y = m - (i + j - 2 - (n - x));
				if (y < j || y > m) continue;
				for (int diri = -1; diri <= 0; diri++)
					for (int dirx = 0; dirx <= 1; dirx++) {
						int newi = i + diri, newj = j + (-1 - diri);
						int newx = x + dirx, newy = y + (1 - dirx);
						if (newi < 1 || newx < 1 || newj < 1 || newy < 1
						||  newi > n || newx > n || newj > m || newy > m) continue;
						if (s[i][j] == s[x][y]) {
							add(dp[i][j][x][1], dp[newi][newj][newx][1]);
							add(dp[i][j][x][0], dp[newi][newj][newx][0]);
						}
						else 
							add(dp[i][j][x][1], dp[newi][newj][newx][0]);
					}
			}
		}
	}
	if (n + m % 2 == 0) {
		int res = 0;
		for (int i = 1; i <= n / 2; i++) {
			int j = (n + m) / 2 + 1 - i;
			if (j < 0 || j > m) continue;
			add(res, dp[i][j][i][0]);
			add(res, dp[i][j][i][1]);
		}
		cout << res;	
	}
	else {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			int j = (n + m) / 2 + 1 - i;
			if (j < 0 || j > m) continue;
			add(res, dp[i][j][i][0]);
			add(res, dp[i][j][i + 1][0]);
			add(res, dp[i][j][i][1]);
			add(res, dp[i][j][i + 1][1]);
		}
		cout << res;
	}
}
