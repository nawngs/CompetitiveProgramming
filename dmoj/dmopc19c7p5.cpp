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
const int NMAX = 5e5;
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
	void updatePoint(int u, int v) {
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

int n, V[NMAX + 3], p[NMAX + 3], res[NMAX + 3];

struct Data {
	int p, id, val;
	Data() {
		p = id = val = 0;
	}
	Data(int _p, int _id, int _val) : p(_p), id(_id), val(_val) {};
} a[NMAX + 3];

void case1(int l, int r) {
	if (l >= r) return ;
	int mid = (l + r) / 2;
	case1(l, mid); case1(mid + 1, r);
	int ln = l, rn = mid + 1, total = 0;
	vector < int > roll;
	vector < Data > temp;
	while (ln <= mid && rn <= r) {
		if (a[ln].id < a[rn].id) {
			tree.updatePoint(a[ln].val, 1); roll.pb(a[ln].val);
			temp.pb(a[ln ++]);
			total ++;
		}
		else {
			res[a[rn].p] += total - tree.get(a[rn].val);
			temp.pb(a[rn ++]);
		}
	}
	while (ln <= mid) temp.pb(a[ln ++]);
	while (rn <= r) {
		res[a[rn].p] += total - tree.get(a[rn].val);
		temp.pb(a[rn ++]);
	}
	for (int i = l; i <= r; i++) a[i] = temp[i - l];
	for (auto x : roll) tree.updatePoint(x, -1);
	vector < int >().swap(roll);
	vector < Data >().swap(temp);
}

void case2(int l, int r) {
	if (l >= r) return ;
	int mid = (l + r) / 2;
	case2(l, mid); case2(mid + 1, r);
	int ln = l, rn = mid + 1;
	vector < int > roll;
	vector < Data > temp;
	while (ln <= mid && rn <= r) {
		if (a[ln].id > a[rn].id) {
			tree.updatePoint(a[ln].val, 1); roll.pb(a[ln].val);
			temp.pb(a[ln ++]);
		}
		else {
			res[a[rn].p] += tree.get(a[rn].val - 1);
			temp.pb(a[rn ++]);
		}
	}
	while (ln <= mid) temp.pb(a[ln ++]);
	while (rn <= r) {
		res[a[rn].p] += tree.get(a[rn].val - 1);
		temp.pb(a[rn ++]);
	}
	for (int i = l; i <= r; i++) a[i] = temp[i - l];
	for (auto x : roll) tree.updatePoint(x, -1);
	vector < int >().swap(roll);
	vector < Data >().swap(temp);
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> V[i];
	for (int i = 1; i <= n; i++) cin >> p[i];
	
	for (int i = 1; i <= n; i++) a[i] = {i, p[i], V[p[i]]};
	tree.init(n); case1(1, n); 
	
	for (int i = 1; i <= n; i++) a[i] = {i, p[i], V[p[i]]};
	tree.init(n); case2(1, n);
	
	for (int i = 1; i <= n; i++) {res[i] += res[i - 1]; cout << res[i] << '\n';}
} 