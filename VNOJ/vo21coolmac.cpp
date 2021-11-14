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

const string NAME = "vo21coolmac";
const ll ESP = 1e-9;
const int INF = 1E9;
const int nmax = 1e5 + 5;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[nmax], it[nmax * 6 + 8];

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[node] = min(it[node], val);
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u || l > r) return INF;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main() {
	fast;
	//fre();
	cin >> m;
	for (int i = 1; i <= 6 * nmax; i++) it[i] = INF;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		update(1, 1, nmax, y, x);
	}
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[++ n] = 1e5;
	int tam = 1e5;
	int ans = 0;
	sort(a + 1, a + n + 1);
	while (1) {
		if (tam <= a[1]) {
			cout << (ans == 0 ? 1 : ans);
			return 0;
		}
		int temp = query(1, 1, nmax, tam, nmax);
		if (temp >= tam) {
			cout << -1;
			return 0;
		}
		ans ++;
		tam = temp;
	}
}
