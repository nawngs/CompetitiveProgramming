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

int dp[NMAX + 3][12], n, k;

string s;

vector < pair < char, int > > a;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> s; s = ' ' + s;
	a.pb({'#', 0});
	int dem = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i] == s[i - 1]) dem ++;
		else {
			a.pb({s[i - 1], dem});
			dem = 1;
		}
	}
	a.pb({s[n], dem});
	dp[0][0] = 1;
	for (int i = 1; i < a.size(); i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= k; j++) {
			for (int cur = 0; cur <= min(j, a[i].se - 1); cur++) {
				int rem = j - cur;
				for (int pre = i - 1; pre >= 0; pre--) {
					//cout << pre << " " << rem << '\n';
					if (a[pre].fi == a[i].fi) continue;
					add(dp[i][j], dp[pre][rem]);
					if (rem < a[pre].se) break;
					rem -= a[pre].se;
				}
			}
			//cout << i << " " << j << " " << dp[i][j] << '\n';
		}
	}
	int res = 0, rem = k;
	for (int j = a.size() - 1; j >= 0; j--) {
		add(res, dp[j][rem]);
		rem -= a[j].se;
		if (rem < 0) break;
	}
	cout << res;
}