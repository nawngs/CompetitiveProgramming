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

int n, k, a[100003], it[400003], it2[400003];

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node] = l;
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	if (a[it[node * 2]] >= a[it[node * 2 + 1]]) it[node] = it[node * 2];
	else it[node] = it[node * 2 + 1];
}

void update1(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) return ;
	update1(node * 2, l, (l + r) / 2, pos);
	update1(node * 2 + 1, (l + r) / 2 + 1, r, pos);
	if (a[it[node * 2]] >= a[it[node * 2 + 1]]) it[node] = it[node * 2];
	else it[node] = it[node * 2 + 1];
}

int query1(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return -1;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	int lnode = query1(node * 2, l, mid, u, v);
	int rnode = query1(node * 2 + 1, mid + 1, r, u, v);
	if (lnode == -1) return rnode;
	if (rnode == -1) return lnode;
	if (a[lnode] >= a[rnode]) return lnode;
	else return rnode;
}

void update2(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	it2[node] ++;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update2(node * 2, l, mid, pos);
	update2(node * 2 + 1, mid + 1, r, pos);
}

int query2(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it2[node];
	int mid = (l + r) / 2;
	return query2(node * 2, l, mid, u, v) + query2(node * 2 + 1, mid + 1, r, u, v);
}

int main() {
	fast;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int u = 1, v = min(n, k + 1);
	build_tree(1, 1, n);
	vector < int > res;
	for (int i = 1; i <= n; i++) {
		cout << i << " " << k << '\n';
		int l = 1, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			int pos = query1(1, 1, n, 1, mid);
			if (pos + i - 1 - query2(1, 1, n, 1, pos) <= i + k) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		int pos = query1(1, 1, n, 1, ans);
		res.push_back(a[pos]);
		a[pos] = -1;
		k -= pos + i - 1 - query2(1, 1, n, 1, pos) - i;
		update1(1, 1, n, pos);
		update2(1, 1, n, pos);
	}
	for (auto x : res) cout << x << " ";
	for (int i = 1; i <= n; i++) if (a[i] != -1) cout << a[i] << " ";
}
