#include <bits/stdc++.h>

#define name "elecar"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < pii, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 2e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, pos[NMAX + 3];

piii a[NMAX + 3];

int calc(int i, int j) {
	return a[j].fi.fi - a[i].fi.fi + a[j].fi.se - a[i].fi.se;
}

namespace sub12 {
	const int N = 1000;
	int d[N + 3][N + 3];
	vector < pii > adj[N + 3];
	void dijkstra(int st) {
		priority_queue < pii, vector < pii >, greater < pii > > heap;
		for (int i = 1; i <= n; i++) d[st][i] = INF;
		d[st][st] = 0; heap.push({0, st});
		while (heap.size()) {
			auto u = heap.top(); heap.pop();
			if (u.fi != d[st][u.se]) continue;
			for (auto v : adj[u.se]) {
				if (d[st][v.fi] > max(u.fi, v.se)) {
					d[st][v.fi] = max(u.fi, v.se);
					heap.push({d[st][v.fi], v.fi});
				}
			}
		}
	}
	void solve() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) adj[i].pb({j, calc(i, j)});
		}
		for (int i = 1; i <= n; i++) dijkstra(i);
		while (q--) {
			int i, j; cin >> i >> j; i = pos[i]; j = pos[j];
			if (i > j) swap(i, j);
			cout << d[i][j] << '\n';
		}
	}
}

namespace sub3 {
	const int LG = 19;
	int st[NMAX + 3][LG + 3];
	int get(int l, int r) {
		if (l > r) return 0;
		int k = __lg(r - l + 1);
		return max(st[l][k], st[r - (1 << k) + 1][k]);
	}
	bool check(int x, int i, int j) {
		int l = i + 1, r = n, mid, ans1 = i;
		while (l <= r) {
			mid = (l + r) / 2;
			if (a[mid].fi.fi == 1) r = mid - 1;
			else {
				if (get(i + 1, mid) <= x) {
					ans1 = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
		}
		l = 1, r = j;
		int ans2 = j;
		while (l <= r) {
			mid = (l + r) / 2;
			if (a[mid].fi.fi == 0) l = mid + 1;
			else {
				if (get(mid + 1, j) <= x) {
					ans2 = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}
		}
		if (a[ans1].fi.se >= a[ans2].fi.se) return true;
		return a[ans2].fi.se - a[ans1].fi.se < x;
	}
	void solve() {
		for (int i = 2; i <= n; i++) st[i][0] = a[i].fi.se - a[i - 1].fi.se;
		for (int j = 1; j <= LG; j++)
			for (int i = 2; i + (1 << j) - 1 <= n; i++) {
				st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
			}
		while (q--) {
			int i, j; cin >> i >> j; i = pos[i], j = pos[j];
			if (i > j) swap(i, j);
			if (a[i].fi.fi == a[j].fi.fi) cout << get(i + 1, j) << '\n';
			else {
				int l = 0, r = INF, mid, ans;
				while (l <= r) {
					mid = (l + r) / 2;
					if (check(mid, i, j)) {
						ans = mid;
						r = mid - 1;
					}
					else l = mid + 1;
				}
				cout << ans << '\n';
			}
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
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi.fi >> a[i].fi.se;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pos[a[i].se] = i;
	if (n <= 1000 && q <= 1000) sub12::solve();
	else 
	sub3::solve();
	
}