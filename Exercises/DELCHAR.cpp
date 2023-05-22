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

const string NAME = "delchar";
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

int dp[303][303], n;

string s;

pii xoa[303][303];

bool check[303];

char calc (char c) {
	if (c == '(') return ')';
	if (c == '{') return '}';
	if (c == '[') return ']';
	return '#';
}

void del(int l, int r) {
	//cout << l << " " << r << '\n';
	if (l > r) return ;
	if (l == r) {
		check[l] = false;
		return ;
	}
	if (r - l == 1) {
		if (s[r] != calc(s[l])) check[l] = check[r] = false;
		return ;
	}
	if (xoa[l][r].fi == xoa[l][r].se) {
		del(l, xoa[l][r].fi);
		del(xoa[l][r].fi + 1, r);
	}
	else {
		if (s[r] != calc(s[l])) check[l] = check[r] = false;
		del(xoa[l][r].fi + 1, xoa[l][r].se - 1);
	}
}

void sol() {
	cin >> s;
	n = s.size();
	s = ' ' + s;
	memset(check, true, sizeof (check));
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) dp[i][j] = j - i + 1;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n - k + 1; i++) {
			int j = i + k - 1;
		 	if (k == 1) dp[i][j] = 1;
		 	if (k == 2) {
		 		dp[i][j] = 2 * (s[j] != calc(s[i]));
		 		xoa[i][j] = {i, j};
		 	}
		 	if (k > 2) {
		 		for (int p = i; p < j; p++) {
		 			if (dp[i][j] >= dp[i][p] + dp[p + 1][j]) {
		 				dp[i][j] = dp[i][p] + dp[p + 1][j];
		 				xoa[i][j] = {p, p};
		 			}
		 		}
		 		if (dp[i][j] >= dp[i + 1][j - 1] + 2 * (s[j] != calc(s[i]))) {
		 			dp[i][j] = dp[i + 1][j - 1] + 2 * (s[j] != calc(s[i]));
		 			xoa[i][j] = {i, j};
		 		}
		 	}
		 	
		}
	}
	//cout << xoa[5][7].fi << " " << xoa[5][7].se << '\n';
	cout << dp[1][n] << '\n';
	del(1, n);
	for (int i = 1; i <= n; i++) if (check[i]) cout << s[i];
	cout << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
