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
const ll LINF = 1E15;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, K, c[103], p[103], dp[103][103][103], pos[103];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> K;
	for (int i = 1; i <= K; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	for (int t = 0; t <= K; t++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) dp[t][i][j] = LINF;
	reverse(c + 1, c + K + 1);
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++) {
			bool ok = 1;
			for (int j = l + 1; j <= r; j++) if (pos[j] < pos[j - 1]) ok = false;
			if (!ok) continue;
			dp[0][l][r] = 0;	
		}
	for (int t = 1; t <= K; t++) 
	for (int l = 1; l <= n; l++)
	for (int r = l; r <= n; r++) {
		dp[t][l][r] = dp[t - 1][l][r];
		for (int j = l; j < r; j++)
			dp[t][l][r] = min(dp[t][l][r], dp[t - 1][l][j] + dp[t - 1][j + 1][r] + (r - j) * c[t]);
	}
	cout << (dp[K][1][n] >= LINF ? -1 : dp[K][1][n]);
}