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
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[100003], it[800003], lazy[800003], Left[100003], Right[100003], st1[100003][20], st[2][100003][20];

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
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int walk_left(int node, int l, int r) {
	if (l == r) 
		return l;
	int mid = (l + r) / 2;
	update(node * 2, l, mid);
	update(node * 2 + 1, mid + 1, r);
	if (it[node * 2] <= it[node * 2 + 1]) return walk_left(node * 2, l, mid);
	else return walk_left(node * 2 + 1, mid + 1, r);
}

int walk_right(int node, int l, int r) {
	if (l == r) 
		return r;
	int mid = (l + r) / 2;
	update(node * 2, l, mid);
	update(node * 2 + 1, mid + 1, r);
	if (it[node * 2] < it[node * 2 + 1]) return walk_right(node * 2, l, mid);
	else return walk_right(node * 2 + 1, mid + 1, r);
}

int get(int l, int r, int t) {
	int k = log2(r - l + 1);
	if (t == 0)
		return min(st[0][l][k], st[0][r - (1 << k) + 1][k]);
	else 
		return max(st[1][l][k], st[1][r - (1 << k) + 1][k]);
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= 8 * n; i++) 
		it[i] = INF;
	stack < int > st_max, st_min;
	for (int i = 1; i <= n; i++) {
		update(1, 1, n, i, i, -INF);
		update(1, 1, n, 1, i - 1, -1);
		while (st_max.size() && a[st_max.top()] < a[i]) {
			int r = st_max.top();
			st_max.pop();
			int l = 1;
			if (st_max.size()) l = st_max.top() + 1;
			update(1, 1, n, l, r, -a[r] + a[i]);
		}
		st_max.push(i);
		while (st_min.size() && a[st_min.top()] > a[i]) {
			int r = st_min.top();
			st_min.pop();
			int l = 1;
			if (st_min.size()) l = st_min.top() + 1;
			update(1, 1, n, l, r, +a[r] - a[i]);
		}
		st_min.push(i);
		Left[i] = walk_left(1, 1, n);
		st[0][i][0] = Left[i];
	}
	while (st_max.size()) 
		st_max.pop();
	while (st_min.size()) 
		st_min.pop();
	for (int i = 1; i <= 8 * n; i++) 
		it[i] = INF;
	memset(lazy, 0, sizeof(lazy));
	for (int i = n; i >= 1; i--) {
		update(1, 1, n, i, i, -INF);
		update(1, 1, n, i + 1, n, -1);
		while (st_max.size() && a[st_max.top()] < a[i]) {
			int l = st_max.top();
			st_max.pop();
			int r = n;
			if (st_max.size()) r = st_max.top() - 1;
			update(1, 1, n, l, r, -a[l] + a[i]);
		}
		st_max.push(i);
		while (st_min.size() && a[st_min.top()] > a[i]) {
			int l = st_min.top();
			st_min.pop();
			int r = n;
			if (st_min.size()) r = st_min.top() - 1;
			update(1, 1, n, l, r, -a[i] + a[l]);
		}
		st_min.push(i);
		Right[i] = walk_right(1, 1, n);
		st[1][i][0] = Right[i];
	}
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st[0][i][j] = min(st[0][i][j - 1], st[0][i + (1 << (j - 1))][j - 1]);
			st[1][i][j] = max(st[1][i][j - 1], st[1][i + (1 << (j - 1))][j - 1]);
		}
	int ntest; cin >> ntest;
	while (ntest--) {
		int x, y; cin >> x >> y;
		int l = 1, r = x, mid, p;
		while (l <= r) {
			mid = (l + r) / 2;
			if (get(mid, x, 1) >= y) {
				p = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		l = y, r = n;
		int q;
		while (l <= r) {
			mid = (l + r) / 2;
			if (get(y, mid, 0) <= x) {
				q = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << p << " " << q << '\n';
	}
}