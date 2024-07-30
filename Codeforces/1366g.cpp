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

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 1e4;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

string s, t;

int n, m, dp[N + 3][N + 3], res = 0, conn[N + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> s >> t; m = t.size(); t = ' ' + t;
	string news = "";
	stack < int > st;
	memset(conn, 255, sizeof(conn));
	for (auto x : s) {
		if (x == '.') {
			if (st.size()) {
				news += x;
				conn[st.top()] = news.size();
				st.pop();
			}
			else res ++;
		}
		else {
			news += x;
			st.push(news.size());
		}
	}
	// cout << news << '\n';
	s = news; n = s.size(); s = ' ' + s;
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= m; j++) {
		// cout << i << " " << j << " " << dp[i][j] << '\n';
		if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
		if (s[i] == t[j] && i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
		if (conn[i + 1] != -1) dp[conn[i + 1]][j] = min(dp[conn[i + 1]][j], dp[i][j]);
	}
	cout << res + dp[n][m];
}