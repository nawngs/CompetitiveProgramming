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
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[103][103], s[103][103][3], dp[103][103];

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cin >> a[i][j];
			for (int k = 0; k < 3; k++) s[j][i][k] = s[j][i - 1][k];
			s[j][i][a[i][j]] ++;
		}
		if (a[i][i] == 2) {
			cout << 0 << '\n';
			return 0;
		}
	}
	dp[1][0] = 2;
	for (int i = 1; i < n; i++) 
			for (int j = 0; j < i; j++) {
				if (dp[i][j] == 0) continue;
				//cout << i << " " << j << " " << dp[i][j] << '\n';
				if ((a[i][i + 1] == 1 || a[i][i + 1] == 0) && s[i + 1][j][1] == 0 && s[i + 1][i + 1][2] - s[i + 1][j][2] == 0) 
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
				if ((a[i][i + 1] == 2 || a[i][i + 1] == 0) && s[i + 1][j][1] == 0 && s[i + 1][i][1] - s[i + 1][j][1] == 0)
					dp[i + 1][i] = (dp[i + 1][i] + dp[i][j]) % MOD;
			}
	ll res = 0;
	for (int i = 0; i < n; i++)
		res = (res + dp[n][i]) % MOD;
	cout << res;
}
