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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int k, q, n, a[50003], x[50003], it[300003], lazy[300003];

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node] = x[l];
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

void update(int node, int l, int r, int u, int v, int val) {
	if(lazy[node] != -1){
		it[node] = lazy[node] * (r - l + 1);
		if(l < r){
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = -1;
	}
	if(r < u || v < l) return ;
	if(u <= l && r <= v){
		it[node] = val * (r - l + 1);
		if(l < r){
			lazy[node * 2] = val;
			lazy[node * 2 + 1] = val;
		}
		return ;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

void sol() {
	cin >> k >> q;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		n += a[i];
	}
	int l = 0;
	for (int i = 1; i <= k; i++) {
		a[i] --;
		while (a[i] > 0) {
			a[i] --;
			l ++;
			x[l] = 1;
		}
		x[++l] = 0;
	}
	build_tree(1, 1, n - 1);
	memset(lazy, 255, sizeof(lazy));
	while (q --) {
		char c;
		cin >> c;
		if (c == 'C') cout << n - it[1] << '\n';
		if (c == 'J') {
			int l, r;
			cin >> l >> r;
			update(1, 1, n - 1, l, r - 1, 1);
		}
		if (c == 'D') {
			int l, r;
			cin >> l >> r;
			update(1, 1, n - 1, l, r - 1, 0);
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
