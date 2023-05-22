#pragma GCC optimize ("O2")
#pragma GCC optimize ("O3")

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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, it[800003], it2[800003], a[200003];

void build_tree(int node, int l, int r) {
	if (l == r) {
		it2[node] = l;
		return ;
	}
	int mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	it2[node] = it2[node * 2] + it2[node * 2 + 1]; 
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void update2(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it2[node] = val;
		return ;
	}
	int mid = (l + r) / 2;
	update2(node * 2, l, mid, pos, val);
	update2(node * 2 + 1, mid + 1, r, pos, val);
	it2[node] = it2[node * 2] + it2[node * 2 + 1];
}

int query2(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it2[node];
	int mid = (l + r) / 2;
	return query2(node * 2, l, mid, u, v) + query2(node * 2 + 1, mid + 1, r, u, v);
}

int calc(int pos) {
	return pos - query(1, 1, n, 1, pos);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build_tree(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		int low = x, high = n, mid, ans = -1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (calc(mid) - x <= 0) {
				ans = mid;
				low = mid + 1;
			}
			else high = mid - 1;
		}
		low = x;
		high = n;
		int ans2 = -1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (calc(mid) - x >= 0) {
				ans2 = mid;
				high = mid - 1;
			} 
			else low = mid + 1;
		}
		int tam = query2(1, 1, n, ans2, ans);
		cout << a[tam] << " ";
		update(1, 1, n, tam, 1);
		update2(1, 1, n, tam, 0);
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
