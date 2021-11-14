#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, k, h[400005], cnt[400005];

vector < int > adj[400005]; 

void dfs(int u, int e) {
	if (h[u] == 0) return ;
	vector < int > maxh;
	maxh.clear();
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		//cout << u << " " << h[v] << '\n';
		//h[u] = max(h[u], h[v] + 1);
		maxh.push_back(h[v]);
	}
	sort(maxh.begin(), maxh.end());
	if (maxh.size() >= (e == 0 ? 2 : 1)) h[u] = maxh[maxh.size() - (e == 0 ? 2 : 1)] + 1;
}

void sol() {
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		h[i] = -1;
		cnt[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int start = 0;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			h[i] = 0;	
		}
		else start = i;
	}
	dfs(start, 0);
	//for (int i = 1; i <= n; i++) cout << h[i] << '\n';
	int i = 0, ans = n;
	while (k && ans) {
		ans -= cnt[i];
		i++;
		k --;
	}
	cout << ans << '\n';
}

int main() {
	fastflow;
	int t;
	cin >> t;
	while (t --) sol();
}
