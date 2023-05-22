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

const string NAME = "raspored";
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

struct Query {
	ll p, t, d;
} queries[300003];

ll n, q;

pll order[300003];

pll it[2400003];

void add(pll &x, pll const &y) {
	x.fi += y.fi;
	x.se += y.se;
	return ;
}

void update(int node, int l, int r, int pos, pll val) {
	if (pos < l || pos > r) return ;
	add(it[node], val);
	if (l == r) return ;
	update(node * 2, l, (l + r) / 2, pos, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val);
}

pll query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return make_pair(0, 0);
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	pll lnode = query(node * 2, l, mid, u, v);
	add(lnode, query(node * 2 + 1, mid + 1, r, u, v));
	return lnode;
}

int main() {
	fast;
	fre();
	int O; cin >> O;
	cin >> n >> q;	
	vector < pll > roi_rac;
	for (int i = 1; i <= n; i++) {
		cin >> order[i].fi >> order[i].se;
		roi_rac.push_back({order[i].se, i});
	}
	for (int i = 1; i <= q; i++) {
		cin >> queries[i].p >> queries[i].t >> queries[i].d;
		roi_rac.push_back({queries[i].d, i + n});
	}
	sort(roi_rac.begin(), roi_rac.end());
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		pll temp = make_pair(order[i].se, i);
		order[i].se = lower_bound(roi_rac.begin(), roi_rac.end(), temp) - roi_rac.begin() + 1;
		update(1, 1, roi_rac.size(), order[i].se, make_pair(roi_rac[order[i].se - 1].fi, 1));
	}
	for (int i = 1; i <= n; i++) res += order[i].fi - query(1, 1, roi_rac.size(), 1, order[i].se).fi;
	cout << res << ' ';
	for (int i = 1; i <= q; i++) {
		int id = queries[i].p;
		pll val = query(1, 1, roi_rac.size(), 1, order[id].se);
		res = res - order[id].fi + val.fi + roi_rac[order[id].se - 1].fi * (n - val.se);
		update(1, 1, roi_rac.size(), order[id].se, make_pair(-roi_rac[order[id].se - 1].fi, -1));
		//##############################################################################
		pll temp = make_pair(queries[i].d, i + n);
		queries[i].d = lower_bound(roi_rac.begin(), roi_rac.end(), temp) - roi_rac.begin() + 1;
		update(1, 1, roi_rac.size(), queries[i].d, {temp.fi, 1});
		val = query(1, 1, roi_rac.size(), 1, queries[i].d);
		res = res + queries[i].t - val.fi - temp.fi * (n - val.se);
		order[id] = {queries[i].t, queries[i].d};
		cout << res << " ";
	}
}
