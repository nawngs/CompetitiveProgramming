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

const string NAME = "CDSUBSEG";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[1000005], it[6000005];

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	it[node] = __gcd(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return __gcd(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = abs(a[i]);
	}
	build(1, 1, n);
	int l = 1, r = 0, ans = 0;
	while (r < n) {
		r ++;
		if (r == n && r - l + 1 <= ans) break;
		int tam = query(1, 1, n, l, r);
		if (tam != 1) ans = max(ans, r - l + 1);
		else {
			l ++;
			if (r >= l) r --;
		}
	}
	cout << ans << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
