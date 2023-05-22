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
const int SQR = 225;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[50003], cnt[50003], in[50003], out[50003], timer = 0, id[50003], f[50003][SQR], g[50003][SQR], par[50003][19];

int q, log2_n, h[50003];

vector < int > big, adj[50003], temp;

void dfs(int u) {
	in[u] = ++ timer;
	id[timer] = u;
	h[u] = h[par[u][0]] + 1;
	auto i = lower_bound(big.begin(), big.end(), a[u]);
	if (i != big.end()) {
		int index = i - big.begin();
		if(big[index] == a[u]) f[timer][index] = g[u][index] = 1;
	}
	for (int i = 0; i < big.size(); i++) {
		f[timer][i] += f[timer - 1][i];
		g[u][i] += g[par[u][0]][i];
	}
	for (auto v : adj[u]) {
		if (v == par[u][0]) continue;
		par[v][0] = u;
		dfs(v);
	}
	out[u] = timer;
}

void init() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= log2_n; j++) par[i][j] = 0;

	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j--) 
			if (h[par[v][j]] >= h[u]) v = par[v][j];
	}
	if (u == v) return u;
	for (int j = log2_n; j >= 0; j--) {
		if (par[u][j] != 0 && par[v][j] != par[u][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

int main() {
	fast;
	cin >> n >> q;
	log2_n = log2(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]] ++;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) 
		if (cnt[i] >= SQR) big.push_back(i);
	dfs(1);
	init();
	while(q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int u;
			cin >> u;
			if (out[u] - in[u] + 1 <= 2 * SQR) {
				temp.clear();
				for (int i = in[u]; i <= out[u]; i++) temp.push_back(a[id[i]]);
				sort(temp.begin(), temp.end());
				int dem = 1, sze = 0, val;
				for (int i = 1; i < temp.size(); i++) {
					if (temp[i] == temp[i - 1]) dem ++;
					else {
						if (sze < dem) {
							sze = dem;
							val = temp[i - 1];
						}
						dem = 1;
					}
				}
				if (sze < dem) {
					sze = dem;
					val = temp.back();
				}
				if (sze * 2 > (out[u] - in[u] + 1)) cout << val << '\n';
				else cout << -1 << '\n';
			}
			else {
				int ans = -1;
				for (int i = 0; i < big.size(); i++) {
					if ((f[out[u]][i] - f[in[u] - 1][i]) * 2 > (out[u] - in[u] + 1)) {
						ans = big[i];
						break;
					}
				}
				cout << ans << '\n';
			}
		}
		if (t == 2) {
			int u;
			cin >> u;
			if (n - (out[u] - in[u] + 1) <= 2 * SQR) {
				temp.clear();
				for (int i = 1; i < in[u]; i++) temp.push_back(a[id[i]]);
				for (int i = out[u] + 1; i <= n; i++) temp.push_back(a[id[i]]);
				sort(temp.begin(), temp.end());
				int dem = 1, sze = 0, val;
				for (int i = 1; i < temp.size(); i++) {
					if (temp[i] == temp[i - 1]) dem ++;
					else {
						if (sze < dem) {
							sze = dem;
							val = temp[i - 1];
						}
						dem = 1;
					}
				}
				if (sze < dem) {
					sze = dem;
					val = temp.back();
				}
				if (sze * 2 > n - (out[u] - in[u] + 1)) cout << val << '\n';
				else cout << -1 << '\n';
			}
			else {
				int ans = -1;
				for (int i = 0; i < big.size(); i++) {
					if ((cnt[big[i]] - (f[out[u]][i] - f[in[u] - 1][i])) * 2 > n - (out[u] - in[u] + 1)) {
						ans = big[i];
						break;
					}
				}
				cout << ans << '\n';
			}
		}
		if (t == 3) {
			int u, v;
			cin >> u >> v;
			int e = LCA(u, v);
			int len = h[u] + h[v] - 2 * h[e] + 1;
			if (len <= 2 * SQR) {
				temp.clear();
				while (u != par[e][0]) {
					temp.push_back(a[u]);
					u = par[u][0];
				}
				while (v != e) {
					temp.push_back(a[v]);
					v = par[v][0];
				}
				sort(temp.begin(), temp.end());
				int dem = 1, sze = 0, val;
				for (int i = 1; i < temp.size(); i++) {
					if (temp[i] == temp[i - 1]) dem ++;
					else {
						if (sze < dem) {
							sze = dem;
							val = temp[i - 1];
						}
						dem = 1;
					}
				}
				if (sze < dem) {
					sze = dem;
					val = temp.back();
				}
				if (sze * 2 > len) cout << val << '\n';
				else cout << -1 << '\n';
			}
			else {
				int ans = -1;
				for (int i = 0; i < big.size(); i++) {
					if ((g[u][i] - g[e][i] + g[v][i] - g[par[e][0]][i]) * 2 > len) {
						ans = big[i];
						break;
					}
				}
				cout << ans << '\n';
			}
		}
	}
}
