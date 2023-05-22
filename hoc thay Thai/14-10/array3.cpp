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

int n, a[100003], it[400003];

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = l;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos);
	update(node * 2 + 1, mid + 1, r, pos);
	it[node] = min(it[node * 2 + 1], it[node * 2]);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main() {
	//fast;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (a[2] != a[1]) {
		cout << a[1] << '\n';
		return 0;
	}
	for (int i = 1; i <= 4 * a[1]; i++) it[i] = INF;
	int res = 0;
	update(1, 0, 0, 0);
	for (int i = 2; i <= n; i++) {
		a[i] %= a[1];
		res = max(res, max(a[i], a[i] + a[1] - query(1, 0, a[1], a[i] + 1, a[1])));
		update(1, 0, a[1], a[i]);
	}
	cout << res;
}
