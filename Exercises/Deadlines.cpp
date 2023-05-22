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

const string NAME = "Deadlines";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[200003], cnt[200003], tt[200003], dem[200003];

vector < int > pos[200003];

//############################################################################## it1

pii it1[1200003];
int lazy1[1200003];

pii compare_node(pii x, pii y) {
	if (x.fi <= y.fi) return x;
	else return y;
}

void build_tree1(int node, int l, int r) {
	if (l == r) {
		it1[node] = {l - cnt[l], l};
		return ;
	}
	build_tree1(node * 2, l, (l + r) / 2);
	build_tree1(node * 2 + 1, (l + r) / 2 + 1, r);
	it1[node] = compare_node(it1[node * 2], it1[node * 2 + 1]);
}

void update1(int node, int l, int r, int u, int v, int val) {
	if (lazy1[node] != 0) {
		it1[node].fi += lazy1[node];
		if (l != r) {
			lazy1[node * 2] += lazy1[node];
			lazy1[node * 2 + 1] += lazy1[node];
		}
		lazy1[node] = 0;
	}
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		it1[node].fi += val;
		if (l != r) {
			lazy1[node * 2] += val;
			lazy1[node * 2 + 1] += val;
		}
		return ;
	}
	int mid = (l + r) / 2;
	update1(node * 2, l, mid, u, v, val);
	update1(node * 2 + 1, mid + 1, r, u, v, val);
	it1[node] = compare_node(it1[node * 2], it1[node * 2 + 1]);
	//cout << l << " " << r << " " << it1[node].fi << " " << it1[node].se << '\n';
}

void update12(int node, int l, int r, int vt) {
	if (lazy1[node] != 0) {
		it1[node].fi += lazy1[node];
		if (l != r) {
			lazy1[node * 2] += lazy1[node];
			lazy1[node * 2 + 1] += lazy1[node];
		}
		lazy1[node] = 0;
	}
	if (vt < l || vt > r) return ;
	if (l == r) {
		it1[node] = {INF, l};
		return ;
	}
	int mid = (l + r) / 2;
	update12(node * 2, l, mid, vt);
	update12(node * 2 + 1, mid + 1, r, vt);
	it1[node] = compare_node(it1[node * 2], it1[node * 2 + 1]);
	//if(vt == 8) cout << l << " " << r << " " << it1[node].fi << " " << it1[node].se << '\n';
}

//############################################################################## it2

int it2[1200003];

void build_tree2(int node, int l, int r) {
	if (l == r) {
		it2[node] = pos[l][0];
		return ;
	}
	build_tree2(node * 2, l, (l + r) / 2);
	build_tree2(node * 2 + 1, (l + r) / 2 + 1, r);
	it2[node] = min(it2[node * 2], it2[node * 2 + 1]);
	//cout << l << " " <<  r << " " << it2[node] << '\n';
}

int query2(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it2[node];
	int mid = (l + r) / 2;
	return min(query2(node * 2, l, mid, u, v), query2(node * 2 + 1, mid + 1, r, u, v));
}

void update2(int node, int l, int r, int vt) {
	if (vt < l || vt > r) return ;
	if (l == r) {
		it2[node] = pos[l][tt[l]];
		return ;
	}
	int mid = (l + r) / 2;
	update2(node * 2, l, mid, vt);
	update2(node * 2 + 1, mid + 1, r, vt);
	it2[node] = min(it2[node * 2], it2[node * 2 + 1]);
}

//############################################################################## it3

int it3[1200003];

void update3(int node, int l, int r, int vt) {
	if (vt < l || vt > r) return ;
	it3[node] ++;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update3(node * 2, l, mid, vt);
	update3(node * 2 + 1, mid + 1, r, vt);
}

int query3(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it3[node];
	int mid = (l + r) / 2;
	return query3(node * 2, l, mid, u, v) + query3(node * 2 + 1, mid + 1, r, u, v);
}

//##############################################################################

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	int tam = 0;
	for (int i = 1; i <= n; i++) {
		if (!pos[i].size()) {
			pos[i].push_back(INF);
			cnt[i] = -INF;
			continue;
		}
		tam += pos[i].size();
		cnt[i] = tam;
		dem[i] = pos[i].size();
		pos[i].push_back(INF);
		tt[i] = 0;
		if (cnt[i] > i) {
			cout << -1 << '\n';
			return ;
		}
	}
	build_tree1(1, 1, n);
	build_tree2(1, 1, n);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int tam = it1[1].se;
		int pos_res = query2(1, 1, n, 1, tam);
		tt[a[pos_res]] ++;
		tam = a[pos_res];
		dem[tam] --;
		if (dem[tam] == 0) {
			update12(1, 1, n, tam);
			update1(1, 1, n, tam + 1, n, 1);
		}
		else update1(1, 1, n, tam, n, 1);
		update2(1, 1, n, a[pos_res]);
		update3(1, 1, n, pos_res);
		pos_res += query3(1, 1, n, pos_res + 1, n);
		ans += 1ll * pos_res - i;
	}
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
