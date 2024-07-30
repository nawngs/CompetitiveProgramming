//[FINISHED]
#include <bits/stdc++.h>

#define int ll
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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int SIZE = 320;

int n, a[NMAX + 3], bigid[NMAX + 3], dp[SIZE + 3][SIZE + 3], cnt[SIZE + 3], q;

vector < int > bigaf, val;

vector < int > pos[NMAX + 3];

int calcR(int x) {
	return pos[bigaf[x]].size() - cnt[x];
}

void maximize(int &x, int y) {
	if (x < y) x = y;
}

void solve() {
	int x, y; cin >> x >> y;
	x = lower_bound(val.begin(), val.end(), x) - val.begin() + 1;
	y = lower_bound(val.begin(), val.end(), y) - val.begin() + 1;
	if (SZE(pos[x]) <= SIZE) {
		int res = 0;
		for (int i = 0; i < SZE(pos[x]); i++) {
			int j = upper_bound(pos[y].begin(), pos[y].end(), pos[x][i]) - pos[y].begin();
			res = max(res, (i + 1) * (SZE(pos[y]) - j));
		}
		cout << res << '\n';
		return ;
	}
	if (SZE(pos[y]) <= SIZE) {
		int res = 0;
		for (int i = 0; i < SZE(pos[y]); i++) {
			int j = lower_bound(pos[x].begin(), pos[x].end(), pos[y][i]) - pos[x].begin();
			res = max(res, j * (SZE(pos[y]) - i));
		}
		cout << res << '\n';
		return ;
	}
	cout << dp[bigid[x]][bigid[y]] << '\n';
	return ;
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		val.pb(a[i]);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin() + 1;
		pos[a[i]].pb(i);
	}
	memset(bigid, 255, sizeof bigid);
	int id = 0;
	for (int i = 1; i <= n; i++) if (SZE(pos[i]) > SIZE) {
			bigid[i] = id++;
			bigaf.pb(i);
		}
	for (int i = 1; i <= n; i++) if (bigid[a[i]] != -1) {
		cnt[bigid[a[i]]] ++;
		for (int j = 0; j < SZE(bigaf); j++) {
			maximize(dp[bigid[a[i]]][j], cnt[bigid[a[i]]] * calcR(j));
			//maximize(dp[j][bigid[a[i]]], cnt[j] * calcR(bigid[a[i]]));
		}
	}
	while (q--) solve();
}