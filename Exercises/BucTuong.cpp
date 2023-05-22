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

const string NAME = "buctuong";
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

struct Tree {
	ll x, a, b;
} a[100003];

ll n, sum_a[100003], sum_b[100003], it[800003];

vector < ll > roi_rac;

void update(int node, int l, int r, int pos, ll val) {
	if (pos < l || pos > r) 
		return ;
	it[node] = min(it[node], val);
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

ll query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return LINF;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void build(int node, int l, int r) {
	it[node] = LINF;
	if (l == r) return ;
	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
}

int main() {
	fast;
	fre();
	cin >> n;
	roi_rac.push_back(-LINF);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].b >> a[i].a;
		sum_a[i] = sum_a[i - 1] + a[i].a;
		sum_b[i] = sum_b[i - 1] + a[i].b;
		roi_rac.push_back(a[i].x - sum_a[i]);
		roi_rac.push_back(a[i].x - sum_a[i - 1]);
	}
	build(1, 1, 2 * n);
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	ll res = -LINF;
	for (int i = 1; i <= n; i++) {
		update(1, 1, 2 * n, lower_bound(roi_rac.begin(), roi_rac.end(), a[i].x - sum_a[i - 1]) - roi_rac.begin(), sum_b[i - 1]);
		ll temp = query(1, 1, 2 * n, lower_bound(roi_rac.begin(), roi_rac.end(), a[i].x - sum_a[i]) - roi_rac.begin(), 2 * n);
		res = max(res, sum_b[i] - temp);
	}
	cout << res;
}
