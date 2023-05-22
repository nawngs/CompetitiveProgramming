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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 100000;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, q, ans = 0, h[100003], cnt[100003];

vector < int > adj[100003];

bitset < 200001 > dp;

void dfs1(int u, int e) {
	h[u] = h[e] + 1;
	int dem = 0;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs1(v, u);
		dem ++;
	}
	if (h[u] % 2 == 1) ans += max(1 - dem, dem - 1);
}

void dfs2(int u, int e) {
	h[u] = h[e] + 1;
	int dem = 0;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs2(v, u);
		dem ++;
	}
	if (h[u] % 2 == 1) {
		cnt[abs(dem - 1)] ++;
	}
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		cnt[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (q == 1) {
		ans = 0;
		dfs1(1, 0);
		cout << ans << '\n';
		return ;
	}
	else {
		dp = 0;
		dp[base] = 1;
		dfs2(1, 0);
		for (int i = 1; i <= n / 2; i++) {
			if (cnt[i] < 2) continue;
			if (cnt[i] % 2 == 0) {
				int tam = cnt[i] - 2;
				cnt[i] = 2;
				cnt[i * 2] += tam / 2;
			}
			else {
				int tam = cnt[i] - 1;
				cnt[i] = 1;
				cnt[i * 2] += tam / 2;
			}
			//cout << i << " " << cnt[i] << '\n';
		}
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= cnt[i]; j++) {
					dp = (dp << i) | (dp >> i);
			}
		for (int i = 0; i <= n; i++) if (dp[base + i]) {
			cout << i << '\n';
			return ;
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) solve();
}
