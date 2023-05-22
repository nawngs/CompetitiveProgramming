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

const string NAME = "joiningletters";
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

ll dp[150003][3], res;;

int main() {
	fast;
	fre();
	while (cin >> s && s != "$") {
		s = ' ' + s;
		res = 0;
		for (int i = 1; i < (int)s.size(); i++) 
			for (int j = 0; j < 3; j++) dp[i][j] = 0;
		for (int i = 1; i < (int)s.size(); i++) {
			for (int j = 0; j < 3; j++) dp[i][j] = dp[i - 1][j];
			if (s[i] == 'I')
				dp[i][0] ++;
			if (s[i] == 'C') {
				dp[i][1] += dp[i - 2][0];
				if (i > 1) res += dp[i - 2][2];
			}
			if (s[i] == 'P' && i > 1)
				dp[i][2] += dp[i - 2][1];
			//cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << res << '\n';
		}
		cout << res << '\n';
	}
}
