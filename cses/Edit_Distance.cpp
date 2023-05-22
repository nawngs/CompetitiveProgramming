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

int dp[5003][5003];

string s, t;

void sol() {
	cin >> s >> t;
	if (s.size() > t.size()) swap(s, t);
	int n = s.size();
	int m = t.size();
	s = ' ' + s;
	t = ' ' + t;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) dp[i][j] = min(i, j) + abs(i - j);
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= m; j++) { 
			dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s[i] != t[j]))));
		}
	}

	cout << dp[n][m];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
