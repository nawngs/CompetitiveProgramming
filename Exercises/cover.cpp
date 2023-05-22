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

const string NAME = "cover";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data {
	int l, r, index;
} arr[100003];

int x, a, b, n;

vector < int > res;

pii it[1200003];

void roi_rac() {
	vector < pair < int, pii > > temp;
	temp.push_back({a, {0, 1}});
	temp.push_back({b, {0, 2}});
	for (int i = 1; i <= n; i++) {
		temp.push_back({arr[i].l, {i, 1}});
		temp.push_back({arr[i].r, {i, 2}});
	}
	sort(temp.begin(), temp.end());
	int dem = 1;
	for (int i = 0; i < temp.size(); i++) {
		if (i != 0) dem += (temp[i].fi != temp[i - 1].fi);
		if (temp[i].se.fi == 0) {
			if (temp[i].se.se == 1) a = dem;
			else b = dem;
		}
		else {
			if (temp[i].se.se == 1) arr[temp[i].se.fi].l = dem;
			else arr[temp[i].se.fi].r = dem;
		}
	}
}

void update(int node, int l, int r, int pos, int val, int index) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		if (it[node].fi < val) it[node] = {val, index};
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, val, index);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val, index);
	it[node] = (it[2 * node].fi > it[2 * node + 1].fi ? it[2 * node] : it[2 * node + 1]);
}

pii query(int node, int l, int r, int u, int v) {
	if (r < u || v < l) return {-INF, -1};
	if (u <= l && r <= v) return it[node];
	pii lnode = query(node * 2, l, (l + r) / 2, u, v);
	pii rnode = query(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
	if (lnode.fi > rnode.fi) return lnode;
	else return rnode;
}

void sol() {
	cin >> x >> a >> b;
	n = 0;
	for (int i = 1; i <= x; i++) {
		int l, r;
		cin >> l >> r;
		if (r >= a && l <= b) {
			arr[++ n].l = l;
			arr[n].r = r;
			arr[n].index = i;
 		}
	}
	roi_rac();
	for (int i = 1; i <= 12 * n; i++) it[i] = {-INF, -1};
	for (int i = 1; i <= n; i++) update(1, 1, 2 * n, arr[i].l, arr[i].r, arr[i].index);
	int pos = a;
	while (1) {
		pii tam = query(1, 1, 2 * n, 1, pos);
		if (tam.fi > pos || (tam.fi == pos && !res.size())) {
			pos = tam.fi;
			res.push_back(tam.se);
		}
		else break;
		if (pos >= b) break;
	}
	if (pos < b) cout << -1;
	else {
		cout << res.size() << '\n';
		for (auto x : res) cout << x << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
