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

const string NAME = "css";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

string a, b;

int dp[1002][1002];

void sol() {
	cin >> a >> b;
	int n = a.size(), m = b.size();
	a = ' ' + a;
	b = ' ' + b;	
	for (int i = 0; i <= n; i++) dp[i][0] = i;
	for (int i = 1; i <= m; i++) dp[0][i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
		}
	}
	string s = "";
	int i = n, j = m;
	while (i >= 1 || j >= 1) {
		if (i == 0) {
			s += b[j];
			j --;
			continue;
		}
		if (j == 0) {
			s += a[i];
			i --;
			continue;
		}
		if (a[i] == b[j] && dp[i][j] == dp[i - 1][j - 1] + 1) {
			s += a[i];
			i --;
			j --;
			continue;
		}
		//cout << i << " " << j << " " << dp[i - 1][j] << " " << dp[i][j - 1] << '\n';
		if (dp[i - 1][j] <= dp[i][j - 1]) {
			s += a[i];
			i --;
		}
		else {
			s += b[j];
			j --;
		}
	}
	reverse(s.begin(), s.end());
	cout << s << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
