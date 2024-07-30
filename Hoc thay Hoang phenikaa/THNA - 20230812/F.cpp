//[UNFINISHED]
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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, a[100003];

struct Node {
	int vxor[31], vand[31], demx[31], dema[31];
} it[8 * NMAX];

Node merge(const Node &x, const Node &y) {
	Node res;
	for (int i = 0; i <= 30; i++) {
		res.vxor[i] = x.vxor[i] | y.vxor[i];
		res.vand[i] = x.vand[i] & y.vand[i];
		res.demx[i] = x.demx[i] + y.demx[i];
		res.dema[i] = x.dema[i] + y.dema[i];
	}
	return res;
}

void build(int node, int l, int r) {
	if (l == r) {
		for (int i = 0; i <= 30; i++) it[node].vand[i] = (1 << 30) - 1;
		int num = __builtin_popcount(a[l]);
		it[node].vxor[num] = it[node].vand[num] = a[l];
		it[node].demx[num] = it[node].dema[num] = 1;
		return ;
	}
	build(lnode); build(rnode);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
	//cout << l << " " << r << " " << it[node].vand[1] << '\n';
}

Node query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) {
		Node res;
		for (int i = 0; i <= 30; i++) res.vxor[i] = res.vand[i] = -1;
		return res;
	}
	if (u <= l && r <= v) return it[node];
	Node lval = query(lnode, u, v), rval = query(rnode, u, v);
	if (lval.vxor[0] == -1) return rval;
	if (rval.vxor[0] == -1) return lval;
	return merge(lval, rval);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	while (q--) {
		int l, r; cin >> l >> r;
		Node kq1 = query(1, 1, n, l, r);
		Node kq2 = kq1;
		for (int i = 1; i <= 30; i++) {
			kq1.vxor[i] |= kq1.vxor[i - 1];
			kq1.demx[i] += kq1.demx[i - 1];
		}
		for (int i = 29; i >= 0; i--) if (kq1.dema[i + 1]) {
			kq1.vand[i] &= kq1.vand[i + 1];
			kq1.dema[i] += kq1.dema[i + 1];
		}
		bool ok = false;
		for (int i = 0; i < 30; i++) if (kq1.demx[i] && kq1.dema[i + 1] && kq1.vxor[i] == kq1.vand[i + 1]) {
			ok = true;
			break;
		}
		for (int i = 0; i <= 30; i++) if (kq2.demx[i] > 1 && kq2.vxor[i] == kq2.vand[i]) {
			int prex = (i == 0 ? 0 : kq1.vxor[i - 1]);
			int suffa = (i == 30 ? (1 << 30) - 1 : kq1.vand[i + 1]);
			if ((prex | kq2.vxor[i]) == (suffa & kq2.vxor[i])) {
				ok = true;
				break;
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}