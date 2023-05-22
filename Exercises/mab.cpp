#include <bits/stdc++.h>

#define name "mab"
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

int n, m, q, a[1003][1003], f[1003][1003], g[1003][1003], s[1003][1003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	vector < pii > temp;
	for (int i = 1; i <= n; i++) {
		temp.clear();
		for (int j = 1; j <= m; j++) temp.pb({a[i][j], j});
		sort(temp.begin(), temp.end());
		for (int j = 0; j < sz(temp); j++) {
			if (j == 0 || temp[j].fi != temp[j - 1].fi) f[i][temp[j].se] = j;
			else f[i][temp[j].se] = f[i][temp[j - 1].se];
		} 
	}
	for (int j = 1; j <= m; j++) {
		temp.clear();
		for (int i = 1; i <= n; i++) temp.pb({a[i][j], i});
		sort(temp.begin(), temp.end(), greater < pii > ());
		for (int i = 0; i < sz(temp); i++) {
			if (i == 0 || temp[i].fi != temp[i - 1].fi) g[temp[i].se][j] = i;
			else g[temp[i].se][j] = g[temp[i - 1].se][j];
		}
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			s[f[i][j]][g[i][j]] ++;
		}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			if (i > 0) s[i][j] += s[i - 1][j];
			if (j > 0) s[i][j] += s[i][j - 1];
			if (i > 0 && j > 0) s[i][j] -= s[i - 1][j - 1];
		}
	while (q--) {
		int i, j; cin >> i >> j; cout << s[i][j] << '\n';
	}
}