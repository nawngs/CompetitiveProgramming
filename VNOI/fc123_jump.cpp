#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, q, a[100005], it[600005], cnt[100005];

pii p[100005]; 

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u || l > r) return n + 1;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void roi_rac() {
	FOR(i, 1, n) {
		p[i].fi = a[i];
		p[i].se = i;
	}
	sort(p + 1, p + n + 1);
	int dem = 0;
	p[0].fi = 1e9 + 7;
	FOR(i, 1, n) {
		dem += (p[i].fi != p[i - 1].fi);
		a[p[i].se] = dem;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, 6 * n) it[i] = n + 1;
	roi_rac();
	cnt[n + 1] = -1;
	ROF(i, n, 1) {
		int tam = query(1, 1, n, a[i] + 1, n);
		cnt[i] = cnt[tam] + 1;
		update(1, 1, n, a[i], i);
	}
	while (q --) {
		int x;
		cin >> x;
		cout << cnt[x] << '\n';
	}
}
