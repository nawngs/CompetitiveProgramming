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
const int N = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, SIZE, it[12 * N + 3], lazy[12 * N + 3];

pii a[N + 3];

vector < int > compress, ql[2 * N + 3], qr[2 * N + 3];

void build(int node, int l, int r) {
	it[node] = lazy[node] = 0;
	if (l == r) return ;
	build(lnode); build(rnode);
}

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v, int val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return max(query(lnode, u, v), query(rnode, u, v));
}

set < int > A, C;

void sol() {
	cin >> n;
	compress.clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		compress.pb(a[i].fi); compress.pb(a[i].se);
	}
	sort(a + 1, a + n + 1, [&](pii &x, pii &y) {
		return x.se < y.se;
	});
	sort(compress.begin(), compress.end());
	compress.erase(unique(compress.begin(), compress.end()), compress.end());
	SIZE = SZE(compress);
	for (int i = 1; i <= SIZE; i++) ql[i].clear(), qr[i].clear();
	build(1, 1, SIZE);
	for (int i = 1; i <= n; i++) {
		a[i].fi = lower_bound(compress.begin(), compress.end(), a[i].fi) - compress.begin() + 1;
		a[i].se = lower_bound(compress.begin(), compress.end(), a[i].se) - compress.begin() + 1;
		update(1, 1, SIZE, a[i].fi, a[i].se, 1);
		ql[a[i].fi].pb(i); qr[a[i].se + 1].pb(i);
	}
	C.insert(1); C.insert(2);
	A.clear(); C.clear();
	int res = 0, temp = 0;
	for (int x = 1; x <= SIZE; x++) {
		for (auto i : ql[x]) C.insert(i);
		for (auto i : qr[x]) {
			auto it = A.find(i);
			if (it != A.end()) A.erase(it);
			else C.erase(i);
		}
		while (!C.empty() && SZE(A) < temp) {
			int i = *C.begin();
			update(1, 1, SIZE, a[i].fi, a[i].se, -1);
			A.insert(i); C.erase(i);
		}
		while (!A.empty() && !C.empty() && *A.rbegin() > *C.begin()) {
			int val1 = *A.rbegin(), val2 = *C.begin();
			A.erase(val1); C.erase(val2); A.insert(val2); C.insert(val1);
			update(1, 1, SIZE, a[val1].fi, a[val1].se, 1);
			update(1, 1, SIZE, a[val2].fi, a[val2].se, -1);
		}
		while (SZE(A) == temp && !C.empty()) {
			int i = *C.begin();
			update(1, 1, SIZE, a[i].fi, a[i].se, -1);
			// cout << x << " " << temp + 1 << " "<< query(1, 1, SIZE, x, SIZE) << '\n';
			if (query(1, 1, SIZE, x, SIZE) > temp) {
				temp ++;
				A.insert(i);
				C.erase(i);
			}
			else {
				update(1, 1, SIZE, a[i].fi, a[i].se, 1);
				break;
			}
		}
		res = max(res, temp);
	}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}