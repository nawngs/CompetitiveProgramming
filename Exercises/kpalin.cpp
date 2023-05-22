#include <bits/stdc++.h>

#define name "kpalin"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int dp[151][151][3][101];

ll pw[151];

int n, k, M;

string s;

void add(int &x, int y) {
	x = x + y;
	if (x >= M) x -= M;
	if (x < 0) x += M;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> M >> s;
	s = ' ' + s;
	pw[0] = 1;
	for (int i = 1; i < n; i++)
		pw[i] = (pw[i - 1] * 10) % k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) dp[i][j][0][0] = 1;
	int res = 0;
	for (int sze = 1; sze <= n; sze++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int v = 0; v < k; v++) dp[i][j][(sze % 3)][v] = 0;
		for (int len = sze; len <= n; len++) {
			for (int i = 1; i + len - 1 <= n; i++) {
				int j = i + len - 1;
				if (i == j) add(dp[i][j][(sze % 3)][(s[i] - '0') % k], 1);
				else {
					ll val = ((s[i] - '0') * 1ll * pw[sze - 1] + 1ll * (s[j] - '0')) % k;
					for (int v = 0; v < k; v++) {
						add(dp[i][j][sze % 3][v], dp[i][j - 1][sze % 3][v]);
						add(dp[i][j][sze % 3][v], dp[i + 1][j][sze % 3][v]);
						add(dp[i][j][sze % 3][v], -dp[i + 1][j - 1][sze % 3][v]);
						if (sze > 1 && s[i] == s[j]) add(dp[i][j][sze % 3][((1ll * v * 10) % k + val) % k], dp[i + 1][j - 1][(sze + 1) % 3][v]);
					}
				}
			}
		}
		add(res, dp[1][n][sze % 3][0]);
	}
	cout << res;
}