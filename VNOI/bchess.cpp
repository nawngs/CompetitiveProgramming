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

int n, row[2003][2003], col[2003][2003], dp[2003][2003];

string s[2003];

pii res[3];

void getmax(pii &x, int y) {
	if (y == 0) return ;
	if (x.fi < y) x = {y, 1};
	else if (x.fi == y) x.se ++;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	for (int i = 1; i <= n; i++) {
		row[i][1] = 1;
		for (int j = 2; j <= n; j++) row[i][j] = 1 + (s[i][j] != s[i][j - 1]) * row[i][j - 1];
	}
	for (int j = 1; j <= n; j++) {
		col[1][j] = 1;
		for (int i = 2; i <= n; i++) col[i][j] = 1 + (s[i][j] != s[i - 1][j]) * col[i - 1][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i][j] != s[i - 1][j - 1]) dp[i][j] = 1;
			else dp[i][j] = min(dp[i - 1][j - 1] + 1, min(col[i][j], row[i][j]));
			//cout << i << " " << j << " " << dp[i][j] << '\n';
			getmax(res[0], dp[i][j] - (dp[i][j] % 2));
			if (s[i][j] == '1') getmax(res[1], dp[i][j] - (dp[i][j] % 2 == 0));
			else getmax(res[2], dp[i][j] - (dp[i][j] % 2 == 0));
		}
	}
	for (auto x : res) cout << x.fi << " " << x.se << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
