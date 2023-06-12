#include <bits/stdc++.h>

#define int long long
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r
#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

const int NMAX = 5E5;
const int INF = 1E12 + 7;

int n, res = 2 * INF;

pii a[NMAX + 3], pre[NMAX + 3], suff[NMAX + 3];

struct IT {
	int it[4 * NMAX + 3];
	void build(int node, int l, int r) {
		it[node] = INF;
		if (l == r) return ;
		build(lnode); build(rnode);
	}
	void update(int node, int l, int r, int pos, int val) {
		if (pos < l || pos > r) return ;
		it[node] = min(it[node], val);
		if (l == r) return ;
		update(lnode, pos, val); update(rnode, pos, val);
	}

	int query(int node, int l, int r, int u, int v) {
		if (v < l || r < u) return INF;
		if (u <= l && r <= v) return it[node];
		return min(query(lnode, u, v), query(rnode, u, v));
	}
} Tree1;

void solve(int val) {
	pre[0] = {0, INF};
	pre[1] = {a[1].se, a[1].se};
	for (int i = 2; i <= n; i++) {
		pre[i].fi = max(pre[i - 1].fi, a[i].se);
		pre[i].se = min(pre[i - 1].se, a[i].se);
		//cout << i << " " << pre[i].fi << " " << pre[i].se << '\n';
	}
	suff[n + 1] = {0, INF};
	for (int i = n; i >= 1; i--) {
		suff[i].fi = max(suff[i + 1].fi, a[i].se);
		suff[i].se = min(suff[i + 1].se, a[i].se);
		//cout << i << " " << suff[i].fi << " " << suff[i].se << '\n';
	}
	Tree1.build(1, 0, n); 
	Tree1.update(1, 0, n, 0, -val * a[1].fi); 
	for (int i = 1; i < n; i++) {
		int l = 1, r = i - 1, ansl = -1, ansr = -1, mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if (pre[mid].se <= suff[i + 1].se) {
				ansl = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		l = 0, r = i - 1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (pre[mid].fi <= suff[i + 1].fi) {
				ansr = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (ansl != -1 && ansr != -1 && ansl <= ansr) {
			res = min(res, val * a[i].fi + suff[i + 1].fi + Tree1.query(1, 0, n, ansl, ansr));
		}
		if (ansl == -1) ansl = ansr + 1;
		ansl --;
		if (min(ansl, ansr) + 1 >= 0) {
			// /if (i == 2) cout << val * a[i].fi << " " << suff[i + 1].fi <<  " " << -suff[i + 1].se <<  " " <<  - val * a[min(ansl, ansr) + 1].fi << '\n';
			res = min(res, val * a[i].fi + suff[i + 1].fi - suff[i + 1].se - val * a[min(ansl, ansr) + 1].fi);
		}
		Tree1.update(1, 0, n, i, -val * a[i + 1].fi - pre[i].se);
	}
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1);
	solve(1);
	reverse(a + 1, a + n + 1);
	solve(-1);
	cout << res;
}