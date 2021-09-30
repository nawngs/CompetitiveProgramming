#include <bits/stdc++.h>
#define pii pair < int, int > 
#define fi first
#define se second
using namespace std;

int n, a[200005], it[1200005], dem = 0, f[2000005];

pii p[200005];

int bs1(int x) { //tim >=
	int l = 1, r = dem, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		//cout << mid << '\n';
		if (f[mid] > x) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	it[node] ++;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos);
	update(node * 2 + 1, mid + 1, r, pos);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u || l > r) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("PairAB.Inp", "r", stdin);
	freopen("PairAB.Out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[i] -= x;
		p[i].fi = a[i];
		p[i].se = i;
	}
	sort(p + 1, p + n + 1);
	p[0].fi = 1e9 + 7;
	for (int i = 1; i <= n; i++) {
		dem += (p[i].fi != p[i - 1].fi);
		a[p[i].se] = dem;
		f[dem] = p[i].fi;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int tam = bs1(-f[a[i]]);
		//cout << i << " " << -f[a[i]] << " " << tam << '\n';
		if (tam != -1) {
			//cout << i << " " << query(1, 1, n, tam, n) << '\n';
			ans += query(1, 1, n, tam, n);
		}
		update(1, 1, n, a[i]);
	}
	cout << ans;
}