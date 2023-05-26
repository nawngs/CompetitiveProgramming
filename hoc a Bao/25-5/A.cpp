//[FINISHED]
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
const int NMAX = 2e5 + 50;
const ll MOD = 998244353;
const ll BASE = 2309;

int n, a[NMAX + 50], dem[NMAX + 50], sz[NMAX + 50];

vector < int > dp[NMAX + 50];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dem[a[i]] ++;
	}
	sort(a + 1, a + n + 1);
	sz[a[1]] = 0; dp[a[1]].resize(1); dp[a[1]][0] = 1;
	for (int i = a[1]; i < NMAX; i++) {
		sz[i + 1] = (dem[i] + sz[i]) / 2; dp[i + 1].resize(sz[i + 1] + 1);
		for (int j = 0; j <= sz[i]; j++) {
			int val = j + dem[i];
			add(dp[i + 1][0], dp[i][j]);
			if (val / 2 + 1 <= sz[i + 1]) add(dp[i + 1][val / 2 + 1], -dp[i][j]);
		}
		for (int j = 1; j <= sz[i + 1]; j++)
			add(dp[i + 1][j], dp[i + 1][j - 1]);
		/*if (i >= a[n] && sz[i + 1] == 0) {
			cout << dp[i + 1][0] << '\n';
			return 0;
		}*/
	}	
	int res = 0;
	for (auto x : dp[NMAX]) 
		add(res, x);
	cout << res;
}