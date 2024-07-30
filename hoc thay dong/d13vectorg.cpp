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
const int NMAX = 1e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, ans = 0, f[NMAX + 3];

vector < int > a[NMAX + 3], res[NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		a[i].resize(m + 2);
		a[i][0] = i;
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
	sort(a + 1, a + n + 1, [&](vector < int > &x, vector < int >&y) {
		for (int i = 1; i <= m; i++) {
			if (x[i] < y[i]) return true;
			if (x[i] > y[i]) return false;
		}
		return true;
	});
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int pre = 1; pre < i; pre++) {
			bool th = 1;
			for (int j = 1; j <= m; j++) if (a[pre][j] > a[i][j]) th = false;
			if (th) f[i] = max(f[i], f[pre] + 1);
		}
		res[f[i]].pb(a[i][0]);
		ans = max(ans, f[i]);
	}
	cout << ans << '\n';
	for (int i = 1; i <= ans; i++) {
		cout << res[i].size() << ' ';
		for (auto x : res[i]) cout << x << " ";
		cout << '\n';
	}
}