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
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k;

pll a[503];

bool dp[503][503];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	ll suma = 0, sumb = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		suma += a[i].fi; sumb += a[i].se;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < k; j++) {
			dp[i][j] |= dp[i - 1][j];
			for (int x = 0; x < k; x++) {
				if (x > a[i].fi) break;
				if (x + a[i].se >= k) {
					dp[i][j] |= dp[i - 1][(j - x + k) % k];
				}
			}
		}
	ll res = LINF;
	for (int j = 0; j < k; j++) if (dp[n][j]) {
		int x = (suma - j) % k;
		int y = ((suma + sumb) % k - x + k) % k;
		res = min(res, 1ll * x + y);
	}
	cout << (suma + sumb - res) / k;
}