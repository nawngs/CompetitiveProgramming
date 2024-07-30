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
const int NMAX = 2e5;
const ll MOD = 111539786;
const ll BASE = 2309;

ll n, m, k, s, dp[103][13][2503];

bool invalid[103][13];

void add(ll &x, ll y) {
	x = (x + y) % MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k >> s;
	for (int i = 1; i <= s; i++) {
		int x, y; cin >> x >> y;
		invalid[x][y] = 1;
	}
	k = k + s; k = (n + 1) * (m + 1) - 1 + k;
	
	for (int j = 0; j <= m; j++) dp[0][j][j] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int p = 1; p <= k; p++) add(dp[i][0][p], dp[i - 1][m][p - 1]);
		for (int j = 1; j <= m; j++) 
		for (int p = 0; p <= k; p++) {
			int temp = 0;
			if (invalid[i][j]) temp = 2;
			else temp = ((j == m || invalid[i][j + 1]) + (i == n || invalid[i + 1][j]));
			if (temp == 0 && p >= 1) add(dp[i][j][p], 2 * dp[i][j - 1][p - 1] % MOD);
			if (temp == 1 && p >= 1) add(dp[i][j][p], dp[i][j - 1][p - 1]);
			if (p >= 2) add(dp[i][j][p], dp[i][j - 1][p - 2]);
			// cout << i << " " << j << " " << p << " " << dp[i][j][p] << '\n';
		}
	}
	
	cout << dp[n][m][k];
		
}
