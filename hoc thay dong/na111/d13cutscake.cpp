#include <bits/stdc++.h>

#define name ""
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

int n, m, a[2003][2003], s[2003][2003];

vector < pair < pii, pii > > res;

int get(int x, int y, int u, int v) {
	if (x > u || y > v) return 0;
	return s[u][v] - s[x - 1][v] - s[u][y - 1] + s[x - 1][y - 1];
}

void solve(int x) {
	if (x > n) return ;
	for (int i = x; i <= n; i++) {
		if (get(x, 1, i, m) == 0) continue;
		if (get(i + 1, 1, n, m) == 0) {
			int pre = 1;
			for (int j = 1; j <= m; j++) {
				if (get(x, pre, n, j) == 2) {
					res.push_back({{x, pre}, {n, j - 1}});
					pre = j;
				}
			}
			res.push_back({{x, pre}, {n, m}});
			return ;
		}
		else {
			int pre = 1;
			for (int j = 1; j <= m; j++) {
				if (get(x, pre, i, j) == 2) {
					res.push_back({{x, pre}, {i, j - 1}});
					pre = j;
				}
			}
			res.push_back({{x, pre}, {i, m}});
			return solve(i + 1);
		}
	} 
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	solve(1);
	cout << sz(res) << '\n';
	for (auto x : res) cout << x.fi.fi << ' ' << x.fi.se << " " << x.se.fi << " " << x.se.se << '\n';
}