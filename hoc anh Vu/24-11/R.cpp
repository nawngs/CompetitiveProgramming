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

int n, q, par[200003], rnk[200003];

set < int > ms;

int find(int u) {
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}

int join(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return u;
	if (rnk[u] < rnk[v]) swap(u, v);
	par[v] = u;
	rnk[u] += rnk[v];
	return u;
}

int main() {
	fast;
	//fre();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		rnk[i] = 1;
		ms.insert(i);
	}
	while (q--) {
		int t, x, y; cin >> t >> x >> y;		
		auto u = ms.lower_bound(x);
		auto v = ms.upper_bound(y);
		v--;
		if (t == 1) join(*u, *v);
		if (t == 2) {
			if (*u > *v) continue;
			int cur = find(*u);
			vector < int > temp;
			while (*u != *v) {
				++u;
				temp.push_back(*u);
				cur = join(cur, *u);
			}
			for (int i = 0; i < (int) temp.size() - 1; i++) ms.erase(temp[i]);
		}
		if (t == 3) 
			cout << (find(*u) == find(*v) ? "YES" : "NO") << '\n';
	}
}
