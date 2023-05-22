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

const string NAME = "AWARDCONTEST";
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

int n, q, a[100003];

pii it[400003];

pii merge(const pii &x, const pii &y) {
	vector < int > temp;
	temp.push_back(x.fi), temp.push_back(x.se);
	temp.push_back(y.fi), temp.push_back(y.se);
	sort(temp.begin(), temp.end(), greater < int > ());
	return {temp[0], temp[1]};
}

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = {a[l], -INF};
		return ;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

pii query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return {-INF, -INF};
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return merge(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main() {
	fast;
	fre();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	build(1, 1, n);
	while (q--) {
		int l, r; cin >> l >> r;
		pii res = query(1, 1, n, l, r);
		cout << res.fi << " " << res.se << '\n';
	}
}
