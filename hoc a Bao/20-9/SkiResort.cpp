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

int n, k, s[200003];

pii cur[200003];

vector < pii > adj[200003], adj_new;

void dfs(int u, int e) {
	int curl = cur[u].fi, curr = cur[u].se;
	if (curr < curl) return ;
	adj_new.clear();
	for (auto x : adj[u]) {
		if (x.fi == e) continue;
		adj_new.push_back(x);
	}
	adj[u] = adj_new;
	if (adj[u].size()) {
		for (int i = 0; i < adj[u].size() - 1; i++) {
			int l = curl, r = curr, mid, ans = curl - 1;
			while (l <= r) {
				mid = (l + r) / 2;
				if (abs(s[mid] - adj[u][i].se) <= abs(s[mid] - adj[u][i + 1].se)) {
					ans = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			cur[adj[u][i].fi] = {curl, ans};
			curl = ans + 1;
			dfs(adj[u][i].fi, u);
		}
		cur[adj[u].back().fi] = {curl, curr};
		dfs(adj[u].back().fi, u);
	}
}

int main() {
	fast;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end(), [&](pii &x, pii &y) {
			return x.se < y.se;
		});
		cur[i] = {0, -1};
	}
	for (int i = 1; i <= k; i++) cin >> s[i];
	sort(s + k, s + k + 1);
	cur[1] = {1, k};
	dfs(1, 0);
	for (int i = 1; i < n; i++) 
		cout << cur[i].se - cur[i].fi + 1 << ' ';
	cout << cur[n].se - cur[n].fi + 1 << '\n';
}
