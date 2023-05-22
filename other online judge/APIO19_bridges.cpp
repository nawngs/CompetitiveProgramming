#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int BLOCK_SIZE = 320;

int n, m, u[100003], v[100003], d[100003], q, t[100003], xx[100003], yy[100003], par[100003], comp_sz[100003], res[100003];

bool changed[100003];

vector < int > upd[100003];

struct dsu_save {
    int v, szev, u, szeu;

    dsu_save() {}

    dsu_save(int _v, int _szev, int _u, int _szeu)
        : v(_v), szev(_szev), u(_u), szeu(_szeu) {}
};

stack < dsu_save > roll;

int find(int u) {
	return par[u] == u ? u : find(par[u]);
}

void join(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return ;
	if (comp_sz[v] > comp_sz[u]) swap(u, v);
	roll.push({v, comp_sz[v], u, comp_sz[u]});
	comp_sz[u] += comp_sz[v];
	par[v] = u;
	return ;
}

void rollback(int sze) {
	while (sz(roll) > sze) {
		auto u = roll.top(); roll.pop();
		comp_sz[u.v] = u.szev;
		comp_sz[u.u] = u.szeu;
		par[u.v] = u.v;
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) 
		cin >> u[i] >> v[i] >> d[i];
	int q; cin >> q;
	for (int i = 1; i <= q; i++) 
		cin >> t[i] >> xx[i] >> yy[i];
	for (int ily = 1; ily <= q; ily += BLOCK_SIZE) {
		int l = ily, r = min(q, ily + BLOCK_SIZE - 1);
		for (int i = 1; i <= n; i++) 
			changed[i] = false, comp_sz[i] = 1, par[i] = i;
		vector < int > query, update, remain;
		for (int i = l; i <= r; i++) {
			if (t[i] == 1) {
				changed[xx[i]] = 1;
				update.push_back(i);
			}
			else query.push_back(i);
		}
		for (int i = 1; i <= m; i++) if (!changed[i]) remain.push_back(i);
		for (int i = l; i <= r; i++) {
			if (t[i] == 1) d[xx[i]] = yy[i];
			else {
				upd[i - l].clear();
				for (auto x : update) if (d[xx[x]] >= yy[i]) upd[i - l].push_back(xx[x]);
			}
		}
		sort(query.begin(), query.end(), [&](int &x, int &y) {
			return yy[x] > yy[y];
		});
		sort(remain.begin(), remain.end(), [&](int &x, int &y) {
			return d[x] > d[y];
		});
		int it = 0;
		for (auto x : query) {
			while (it < sz(remain) && d[remain[it]] >= yy[x]) {
				join(u[remain[it]], v[remain[it]]);
				it ++;
			}
			int temp = sz(roll);
			for (auto y : upd[x - l]) join(u[y], v[y]);
			res[x] = comp_sz[find(xx[x])];
			rollback(temp); 
		}
	}
	for (int i = 1; i <= q; i++)
		if (t[i] == 2) cout << res[i] << '\n';
}