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

const string NAME = "";
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

int n, m;

int cnt_u[505][505];
int cnt_d[505][505];
int cnt_l[505][505];
int cnt_r[505][505];
int dp_l_u[505][505];
int dp_r_u[505][505];
int dp_l_d[505][505];
int dp_r_d[505][505];

string s[503];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 || s[i][j] != s[i - 1][j]) cnt_u[i][j] = 1;
			else cnt_u[i][j] = cnt_u[i - 1][j] + 1;
		}
	}

	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			if (i == n || s[i][j] != s[i + 1][j]) cnt_d[i][j] = 1;
			else cnt_d[i][j] = cnt_d[i + 1][j] + 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == 1 || s[i][j] != s[i][j - 1]) cnt_l[i][j] = 1;
			else cnt_l[i][j] = cnt_l[i][j - 1] + 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (j == m || s[i][j] != s[i][j + 1]) cnt_r[i][j] = 1;
			else cnt_r[i][j] = cnt_r[i][j + 1] + 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 || j == 1) dp_l_u[i][j] = 1;
			else dp_l_u[i][j] = min((s[i][j] == s[i - 1][j - 1]) * dp_l_u[i - 1][j - 1] + 2, min(cnt_u[i][j], cnt_l[i][j]));
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (i == 1 || j == m) dp_r_u[i][j] = 1;
			else dp_r_u[i][j] = min((s[i][j] == s[i - 1][j + 1]) * dp_r_u[i - 1][j + 1] + 2, min(cnt_u[i][j], cnt_r[i][j]));
		}
	}

	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			if (i == n || j == 1) dp_l_d[i][j] = 1;
			else dp_l_d[i][j] = min((s[i][j] == s[i + 1][j - 1]) * dp_l_d[i + 1][j - 1] + 2, min(cnt_d[i][j], cnt_l[i][j]));
		}
	}

	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			if (i == n || j == m) dp_r_d[i][j] = 1;
			else dp_r_d[i][j] = min((s[i][j] == s[i + 1][j + 1]) * dp_r_d[i + 1][j + 1] + 2, min(cnt_d[i][j], cnt_r[i][j]));
		}
	}
	int ans = 0;
	int x, y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int tam = min(dp_l_d[i][j], min(dp_r_d[i][j], min(dp_l_u[i][j], dp_r_u[i][j])));
			if (tam > ans) {
				ans = tam;
				x = i;
				y = j;
			}
		}
	}
	cout << x << " " << y << " " << ans - 1 << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
