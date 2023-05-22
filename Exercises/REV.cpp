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

const string NAME = "rev";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int maxx, maxy, k;

ll it[800003], lazy[800003];

vector < int > adj[100003];

map < pii, vector < int > > f;

int rev(int x) {
	int res = 0;
	while (x > 0) {
		res = res * 10 + (x % 10);
		x /= 10;
	}
	return res;
}

void update_node(int node, ll l, ll r) {
	if (lazy[node] != 0) {
		it[node] += 1ll * (r - l + 1) * 1ll * lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v) {
	update_node(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = 1;
		update_node(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v);
	update(node * 2 + 1, mid + 1, r, u, v);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

ll query(int node, int l, int r, int u, int v) {
	update_node(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

int main() {
	fast;
	//fre();
	cin >> maxx >> maxy >> k;
	for (int i = 1; i <= maxx; i++) {
		int revi = rev(i);
		pii tam;
		tam.fi = i / __gcd(i, revi);
		tam.se = revi / __gcd(i, revi);
		f[tam].push_back(i);
	}
	for (int i = 1; i <= maxy; i++) {
		int revi = rev(i);
		pii tam;
		tam.fi = revi / __gcd(i, revi);
		tam.se = i / __gcd(i, revi);
		for (auto x : f[tam]) adj[x].push_back(i);
	}
	ll pos1 = INF, pos2 = INF, r = maxy;
	for (int i = 1; i <= maxx; i++) {
		for (auto x : adj[i]) update(1, 0, maxy, x, r);
		while (query(1, 0, maxy, r, r) >= k) r--;
		r = max(r, 0ll);
		r ++;
		r = min(r, 1ll * maxy);
		if (query(1, 0, maxy, r, r) >= k) {
			if (pos1 * pos2 > 1ll * i * 1ll * r) {
				pos1 = i;
				pos2 = r;
			}
		}
	}
	if (pos1 == pos2 && pos1 == INF) cout << -1 << '\n';
	else cout << pos1 << " " << pos2 << '\n';
}
