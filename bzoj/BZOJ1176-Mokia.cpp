#include <bits/stdc++.h>

#define name ""
#define int ll
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
const int NMAX = 2e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct BIT {
	int n, bit[NMAX + 3];
	BIT() {
		n = 0;
		memset(bit, 0, sizeof(bit));
	}
	void init(int _n) {
		n = _n;
		for (int i = 1; i <= n; i++) bit[i] = 0;
	}
	void update(int u, int v) {
		if (u == 0) return ;
	    int idx = u;
	    while (idx <= n) {
	        bit[idx] += v;
	        idx += (idx & (-idx));
	    }
	}
	
	int get(int u) {
	    int idx = u, ans = 0;
	    while (idx > 0) {
	        ans += bit[idx];
	        idx -= (idx & (-idx));
	    }
	    return ans;
	}
} tree;

int s, w;

vector < int > res;

struct Data {
	int t, x, y, id, v, sign;
	Data() {
		t = x = y = id = v = sign = 0;
	}
	Data(int _t, int _x, int _y, int _id, int _v, int _sign) : t(_t), x(_x), y(_y), id(_id), v(_v), sign(_sign) {}
};

vector < Data > a;

void solve(int l, int r) {
	if (l >= r) return ;
	int mid = (l + r) / 2;
	solve(l, mid); solve(mid + 1, r);
	int ln = l, rn = mid + 1;
	vector < pii > roll; vector < Data > temp;
	while (ln <= mid && rn <= r) {
		if (a[ln].x <= a[rn].x) {
			tree.update(a[ln].y, a[ln].v);
			roll.pb({a[ln].y, -a[ln].v});
			temp.pb(a[ln ++]);
		}
		else {
			//cout << a[rn].x << " " << a[rn].y << '\n';
			if (a[rn].x != 0 && a[rn].y != 0) res[a[rn].id] += a[rn].sign * (tree.get(a[rn].y) + s);
			temp.pb(a[rn ++]);
		}
	}
	while (ln <= mid) temp.pb(a[ln ++]);
	while (rn <= r) {
		// cout << l << " " << r << ' ' << a[rn].x << " " << a[rn].y << " " <<tree.get(a[rn].y) << '\n';
		if (a[rn].x != 0 && a[rn].y != 0) res[a[rn].id] += a[rn].sign * (tree.get(a[rn].y) + s);
		temp.pb(a[rn ++]);
	}
	for (int i = l; i <= r; i++) a[i] = temp[i - l];
	for (auto x : roll) tree.update(x.fi, x.se);
	vector < pii >().swap(roll);
	vector < Data >().swap(temp);
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> s >> w;
	int type;
	res.pb(0);
	int i = 0;
	while (cin >> type && type != 3) {
		i ++;
		if (type == 1) {
			int x, y, v; cin >> x >> y >> v;
			a.pb({i, x, y, 0, v, 0});
		}
		else {
			int x, y, u, v; cin >> x >> y >> u >> v;
			a.pb({i, u, v, SZE(res), 0, 1});
			a.pb({i, x - 1, y - 1, SZE(res), 0, 1});
			a.pb({i, x - 1, v, SZE(res), 0, -1});
			a.pb({i, u, y - 1, SZE(res), 0, -1});
			res.pb(0);
		}
	}
	tree.init(w);
	solve(0, SZE(a) - 1);
	for (int i = 1; i < SZE(res); i++) cout << res[i] << '\n';
}