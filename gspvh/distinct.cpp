//[FINISHED]
#include <bits/stdc++.h>

#define name "distinct"
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
const int NMAX = 5e2;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, pre[NMAX * NMAX + 3];

vector < int > a[NMAX + 3], dp[NMAX + 3], values;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	
	bool chg = 0;
	if (n > m) chg = 1;	
	
	if (chg) for (int i = 1; i <= m; i++) a[i].resize(n + 1), dp[i].resize(n + 1);
	else for (int i = 1; i <= n; i++) a[i].resize(m + 1), dp[i].resize(m + 1);
		
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) 
		cin >>(chg ? a[j][i] : a[i][j]);
		
	if (chg) swap(n, m);
	
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		values.pb(a[i][j]);
	
	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());
	
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		a[i][j] = lower_bound(values.begin(), values.end(), a[i][j]) - values.begin();
		
	int res = 0;
	for (int up = n; up >= 1; up--) {
		for (int j = 1; j <= m; j++) {
			dp[up][j] = max(dp[up][j - 1], pre[a[up][j]]);
			res = max(res, j - dp[up][j]);
			pre[a[up][j]] = j;
		}
		for (int j = 1; j <= m; j++) pre[a[up][j]] = 0;
		for (int down = up + 1; down <= n; down++) {
			for (int r = 1; r <= m; r++) {
				int x = a[up][r], y = a[down][r];
				dp[down][r] = (x == y ? r : max({dp[down][r - 1], dp[down - 1][r], dp[down][r], pre[x], pre[y]}));
				res = max(res, (down - up + 1) * (r - dp[down][r]));
				pre[x] = pre[y] = r;
			}
			for (int r = 1; r <= m; r++) pre[a[up][r]] = pre[a[down][r]] = 0;
		}
	}
	cout << res;
}