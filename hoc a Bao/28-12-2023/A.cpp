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

const int SIZE = 450;
const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[N + 3], cnt[N + 3], m, res[N + 3], ans[N + 3];

struct Query {
	int l, r, k, id;
	Query() {
		l = r = k = id = 0;
	}
} q[N + 3];

void sol() {
	cin >> n >> m;
	vector < int > c;
	for (int i = 1; i <= n; i++) {
		cnt[i] = 0;
		res[i] = 0;
		cin >> a[i];
		c.pb(a[i]);
	}
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	for (int i = 1; i <= n; i++) a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
	for (int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r >> q[i].k;
		q[i].id = i;
	}
	sort(q + 1, q + m + 1, [&](Query &x, Query &y) {
		if (x.l / SIZE != y.l / SIZE) return x.l < y.l;
		return x.r < y.r;
	});
	int all = 0;
	int r = 0, l = 1;
	for (int i = 1; i <= m; i++) {
		while (r < q[i].r) {
			r ++;
			cnt[a[r]] ++;
			if (cnt[a[r]] == 1) all ++;
			res[cnt[a[r]]] ++;
		}
		while (r > q[i].r) {
			res[cnt[a[r]] --] --;
			if (cnt[a[r]] == 0) all --;
			r --;
		}
		while (l > q[i].l) {
			l --;
			cnt[a[l]] ++;
			if (cnt[a[l]] == 1) all ++;
			res[cnt[a[l]]] ++;
		}
		while (l < q[i].l) {
			res[cnt[a[l]] --] --;
			if (cnt[a[l]] == 0) all --;
			l ++;
		}
		ans[q[i].id] = all - res[q[i].k + 1];
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}