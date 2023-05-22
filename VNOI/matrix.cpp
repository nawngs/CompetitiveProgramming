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

int n, m, a[205][205], dp[205][205], s[205][205], dem[205][205];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		s[i][0] = 0;
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) a[i][j] = -1;
			s[i][j] = s[i][j - 1] + a[i][j];
		}
	}
	int ans = -1e9;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			dp[i][j] = s[1][j] - s[1][i - 1];
			dem[i][j] = 1;
			if (dp[i][j] > ans) {
				ans = dp[i][j];
				cnt = 1;
			}
			else if (ans == dp[i][j]) cnt ++;
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = j; k <= m; k++) {
				int tam = max(dp[j][k] + s[i][k] - s[i][j - 1], s[i][k] - s[i][j - 1]);
				if (tam > ans) {
					ans = tam;
					cnt = 0;
				}
				if (ans == dp[j][k] + s[i][k] - s[i][j - 1]) cnt += dem[j][k];
				if (ans == s[i][k] - s[i][j - 1]) cnt ++;
				tam = max(dp[j][k] + a[i][j] + a[i][k] * (j != k), s[i][k] - s[i][j - 1]);
				if (tam != dp[j][k] + a[i][j] + a[i][k] * (j != k)) dem[j][k] = 0;
				if (tam == s[i][k] - s[i][j - 1]) dem[j][k] ++;
				dp[j][k] = tam;
			} 
		}
	}
	cout << ans << " " << cnt << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
