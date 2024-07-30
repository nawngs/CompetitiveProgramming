#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, nid[N + 3], a[5 * N + 3], par[5 * N + 3];

set < pii > id;

int dsu[5 * N + 3];

int find(int u) {
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}

bool join(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	par[v] = u; dsu[u] += dsu[v]; dsu[v] = 0;
	return true;
}

int add(int pos, int val) {
	auto it = id.lower_bound({val, 0});
	if (it == id.end() || it->fi > val) {id.insert({val, pos}); return pos;}
	else return it->se;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		par[i] = i; dsu[i] = 1;
		nid[i] = i;
		join(i, add(i, a[i]));
	}
	int q; cin >> q;
	while (q--) {
		int ope; cin >> ope;
		if (ope == 1) {
			int i, x; cin >> i >> x;
			a[++ n] = x; par[n] = n; dsu[n] = 1;
			nid[i] = n; 
			join(n, add(n, x));
		}
		if (ope == 2) {
			int i; cin >> i;
			cout << a[find(nid[i])] << '\n';
		}
		if (ope == 3) {
			int l, r; cin >> l >> r;
			int x = l - 1;
			a[++ n] = x; par[n] = n; dsu[n] = 1;
			int posl = add(n, x);
			join(n, posl);
			x = r + 1;
			a[++ n] = x; par[n] = n; dsu[n] = 1;
			int posr = add(n, x);
			join(n, posr);
			auto i = id.lower_bound({l, 0});
			while (i != id.end()) {
				if (i->fi > r) break ;
				if (i->fi <= (l + r) / 2) join(posl, i->se);
				else join(posr, i->se);
				i = id.erase(i);	
			}
		}
	}
	
}