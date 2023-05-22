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

const string NAME = "zapis";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e5;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll dp[203][203][2], n, a[203];

map < char, int > f;

string s;

int main() {
	fast;
	//fre();
	cin >> n >> s;
	s = ' ' + s;
	f['('] = 0; f['['] = 1; f['{'] = 2; 
	f[')'] = 5; f[']'] = 4; f['}'] = 3; 
	f['?'] = -1;
	for (int i = 1; i <= n; i++) 
		a[i] = f[s[i]];
	for (int len = 2; len <= n; len+=2) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			if (len == 2) {
				dp[i][j][0] = dp[i][j][1] = 0;
				if (a[i] <= 2 && (a[j] >= 3 || a[j] == -1)) {
					if (a[i] == a[j] && a[i] == -1) dp[i][j][0] = 3;
					else if (a[i] == -1 || a[j] == -1 || a[i] + a[j] == 5) dp[i][j][0] = 1;
					continue;
				}
			}
			if (a[i] <= 2 && (a[j] >= 3 || a[j] == -1)) {
				if (a[i] == a[j] && a[i] == -1) dp[i][j][0] = (3 * (dp[i + 1][j - 1][0] + dp[i + 1][j - 1][1])) % MOD;
				else if (a[i] == -1 || a[j] == -1 || a[i] + a[j] == 5) dp[i][j][0] = (dp[i + 1][j - 1][0] + dp[i + 1][j - 1][1]) % MOD;
			}
			for (int k = i + 1; k < j; k+=2) 
				dp[i][j][1] = (dp[i][j][1] + (dp[i][k][0] * (dp[k + 1][j][0] + dp[k + 1][j][1]))) % MOD;
		}
	}
	cout << (dp[1][n][0] + dp[1][n][1]) % MOD;
}
