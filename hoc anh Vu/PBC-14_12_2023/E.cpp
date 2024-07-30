#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r
#define int ll

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 5e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

string s;

int dp[N + 3][N + 3], n;

pii cnt[N + 3][N + 3];

void sol() {
	cin >> s;
	n = s.size(); s = ' ' + s;
	dp[n + 1][n + 1] = 0;
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= n; j++) cnt[i][j] = {0, 0};
	for (int i = n; i >= 1; i--)
	for (int j = n; j >= 1; j--) dp[i][j] = (s[i] == s[j] ? dp[i + 1][j + 1] + 1 : 0);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 2; j <= n; j++) {
			int temp = min(dp[i][j], j - i - 1);
			if (temp < 2) continue;
			// cout << i << " " << j << " " << temp << '\n';
			cnt[i][temp - 1].se ++;	
		}
		for (int j = n - 1; j >= 1; j--) cnt[i][j].se += cnt[i][j + 1].se, cnt[i][j].fi = cnt[i][j + 1].fi + cnt[i][j].se;
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++) {
		// cout << i << " " << j << " " << i + dp[i][j] - 1 << " " << j + dp[i][j] - 1 << '\n';
		if (dp[i][j] >= j - i) res += cnt[j][j - i].fi;
	}
	cout << res << '\n';
}

main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}