#include <bits/stdc++.h>

#define name "raovat"
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
const int NMAX = 250000;
const int Q = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, ql[Q + 3], qr[Q + 3], qw[Q + 3], low[Q + 3], high[Q + 3], res[Q + 3], q;

pii a[NMAX + 3];

vector < int > mid;

struct Node {
	int sub, suf, pre, sze;
	Node() {
		sub = suf = pre = sze = 0;
	}
} it[4 * NMAX + 3];

Node merge(const Node &x, const Node &y) {
	Node res;
	res.sub = max(x.sub, y.sub); res.sub = max(res.sub, x.suf + y.pre);
	res.pre = x.pre;
	if (x.pre == x.sze) res.pre += y.pre;
	res.suf = y.suf;
	if (y.suf == y.sze) res.suf += x.suf;
	res.sze = x.sze + y.sze;
	return res;
}

void build(int node, int l, int r) {
	it[node].sub = it[node].suf = it[node].pre = 0;
	it[node].sze = r - l + 1;
	if (l == r) return ;
	build(lnode); build(rnode);
}

void update(int node, int l, int r, int u) {
	if (l == r) {
		it[node].sub = it[node].suf = it[node].pre = 1;
		return ;
	}
	int mid = (l + r) / 2;
	if (u <= mid) update(lnode, u);
	else update(rnode, u);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

Node query(int node, int l, int r, int u, int v, const int &res) {
	if (u <= l && r <= v) return it[node];
	if (it[node].sub == r - l + 1) {
		Node res;
		res.sub = res.sze = res.suf = res.pre = min(r, v) - max(u, l) + 1;
		return res;
	};
	int mid = (l + r) / 2;
	if (v <= mid) return query(lnode, u, v, res);
	if (mid < u) return query(rnode, u, v, res);
	Node lval = query(lnode, u, v, res);
	if (lval.sub > res) return lval;
	return merge(lval, query(rnode, u, v, res));
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
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1, greater < pii >());
	for (int i = 1; i <= q; i++) {
		cin >> ql[i] >> qr[i] >> qw[i];
		low[i] = 1; high[i] = n;
	}
	while (1) {
		bool ok = 0;
		
		for (int i = 1; i <= q; i++) {
			if (low[i] > high[i]) continue;
			mid.pb(i);
		}
		sort(mid.begin(), mid.end(), [&](int &x, int &y) {
			return low[x] + high[x] > low[y] + high[y];
		});
		build(1, 1, n);
		for (int i = 1; i <= n; i++) {
			update(1, 1, n, a[i].se);
			while (SZE(mid)) {
				int id = mid.back();
				if ((low[id] + high[id]) / 2 != i) break;
				ok = 1;
				int temp = query(1, 1, n, ql[id], qr[id], qw[id]).sub;
				//cout << a[i].fi << " " << id <<  " " << temp << '\n';
				if (temp >= qw[id]) {
					res[id] = a[i].fi;
					high[id] = i - 1;
				}
				else low[id] = i + 1; 
				mid.pop_back();
			}
		}
		if (!ok) break;
 	}
 	for (int i = 1; i <= q; i++) cout << 1ll * res[i] * 1ll * qw[i] << " ";
}