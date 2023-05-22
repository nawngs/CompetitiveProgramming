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
	string finp = NAME2 + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	//freopen(fout.c_str(), "w", stdout);
}

int n, a[3003], b[3003], s[6003];

ll dp[6003][3003][2];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		 cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	a[n + 1] = b[n + 1] = INF;
	int up = 1, down = 1, cnt = 0;
	while (up <= n || down <= n) {
		if (a[up] <= b[down]) {
			s[++ cnt] = 1;
			up ++;
		}
		else {
			s[++ cnt] = 2;
			down ++;
		}
	}
	// for (int i = 1; i <= cnt; i++) cout << s[i] << " ";
	// cout << '\n';
	dp[0][0][0] = 1;
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k < 2; k++) {
				if (dp[i][j][k] == 0) continue;
				if (s[i + 1] == 1) {
					dp[i + 1][j + 1][k] = (dp[i + 1][j + 1][k] + dp[i][j][k]) % MOD;
					dp[i + 1][j][1] = (dp[i + 1][j][1] + dp[i][j][k]) % MOD;
				}
				else {
					if (j > 0) dp[i + 1][j - 1][k] = (dp[i + 1][j - 1][k] + dp[i][j][k] * j) % MOD;
					if (k == 0) dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % MOD;
				}
			}
		}
	}
	cout << (dp[2 * n][0][0] + dp[2 * n][0][1]) % MOD;
}
