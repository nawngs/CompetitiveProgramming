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

const string NAME = "pipi";
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

int n, m, a[1000003], pre[1000003], res[1000003], it[6000003];

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[node];
	return min(query(node * 2, l, (l + r) / 2, u, v), query(node * 2 + 1, (l + r) / 2 + 1, r, u, v));
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		res[i] = 0;
	}
	for (int i = 1; i <= n; i++) pre[i] = 0;
	for (int i = 1; i <= 6 * m; i++) it[i] = INF;
	for (int i = 1; i <= m; i++) {
		if (a[i] == 0) update(1, 1, m, i, i);
		else {
			int tam = query(1, 1, m, pre[a[i]] + 1, i);
			if (tam == INF) {
				cout << "NO" << '\n';
				return ;
			}
			update(1, 1, m, tam, INF);
			res[tam] = a[i];
			pre[a[i]] = i;
		}
	}
	cout << "YES" << '\n';
	for (int i = 1; i <= m; i++) if (a[i] == 0) cout << res[i] << " ";
	cout << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
