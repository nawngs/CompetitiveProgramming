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

string s;

int dp[2003][2003];

// 0 thang
// 1 hoa
// 2 thua

void sol() {
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	for (int len = 2; len <= n; len+=2) {
		for (int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			dp[i][j] = 1;
			if (len == 2) {if (s[i] != s[j]) dp[i][j] = 0;}
			else {
				int maxa = -1;
				if (s[i] == s[j]) maxa = max(maxa, dp[i + 1][j - 1]);
				if (s[i] == s[i + 1]) maxa = max(maxa, dp[i + 2][j]);
				if (maxa == -1) maxa = 0;
				dp[i][j] = maxa;
				maxa = -1;
				if (s[i] == s[j]) maxa = max(maxa, dp[i + 1][j - 1]);
				if (s[j] == s[j - 1]) maxa = max(maxa, dp[i][j - 2]);
				if (maxa == -1) maxa = 0;
				dp[i][j] = min(dp[i][j], maxa);
			}
		}
	}
	cout << (dp[1][n] == 1 ? "Draw" : (dp[1][n] == 0 ? "Alice" : "Bob")) << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
