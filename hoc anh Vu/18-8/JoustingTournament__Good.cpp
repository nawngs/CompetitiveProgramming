#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	//freopen(fout.c_str(), "w", stdout);
}

int n, c, R, a[100003], it[800003], st[100003][20], res[100003];

bool lazy[800003];

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = 1;
		return ;
	}
	build(node * 2, l, (l + r) / 2);
	build(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

void update_node(int node, int l, int r) {
	if (lazy[node]) {
		it[node] = 0;
		if (l != r) lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
		lazy[node] = 0;
	}
}

int query(int node, int l, int r, int u, int v) {
	update_node(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void update(int node, int l, int r, int u, int v) {
	update_node(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = 1;
		update_node(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v);
	update(node * 2 + 1, mid + 1, r, u, v);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

int get(int l, int r) {
	int k = log2(r - l + 1);
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
	fast;
	//fre();
	cin >> n >> c >> R;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		st[i][0] = a[i];
	}
	st[n][0] = 0;
	for (int j = 1; (1 << j) <= n; j++) 
		for (int i = 1; (i + (1 << j) - 1) <= n; i++) 
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	build(1, 1, n);
	for (int i = 1; i <= c; i++) {
		int s, e;
		cin >> s >> e;
		e ++;
		int l = 1, r = n, mid, x, y;
		while (l <= r) {
			mid = (l + r) / 2;
			if (query(1, 1, n, 1, mid) >= s) {
				x = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (s == 0) x = 0;
		x ++;
		l = 1, r = n;
		while (l <= r) {
			mid = (l + r) / 2;
			if (query(1, 1, n, 1, mid) >= e) {
				y = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (get(x, y - 1) < R) {
			res[x] ++;
			res[y] --;
		}
		update(1, 1, n, x, y - 1);
	}
	int ans = res[1], pos = 1;
	for (int i = 2; i <= n; i++) {
		res[i] += res[i - 1];
		//cout << i << " " << res[i] << '\n';
		if (ans < res[i]) {
			ans = res[i];
			pos = i;
		}
	}
	cout << pos - 1;
}
