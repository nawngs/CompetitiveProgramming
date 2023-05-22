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
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, num[1000003], low[1000003], timeDFS = 0, num_scc[1000003], scc, sum_scc[1000003], dp[1000003];

ll sum[10003], f[10003];

vector < pii > adj[1000003], adj2[1000003];

stack < int > st;

void dfs(int u) {
	num[u] = low[u] = timeDFS ++;
	st.push(u);
	for (auto v : adj[u]) {
		if (num_scc[v.fi] != -1) continue;
		if (!num[v.fi]) {
			dfs(v.fi);
			low[u] = min(low[u], low[v.fi]);
		}
		else low[u] = min(low[u], num[v.fi]);
	}
	if (low[u] == num[u]) {
		scc ++;
		while (1) {
			num_scc[st.top()] = scc;
			if (st.top() == u) {
				st.pop();
				break ;
			}
			st.pop();
		}
	}
}

void dfs2(int u) {
	dp[u] = sum_scc[u];
	for (auto v : adj2[u]) {
		dfs2(v.fi);
		dp[u] = max(dp[u], dp[v.fi] + v.se + sum_scc[u]);
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= 10000; i++) {
		sum[i] = sum[i - 1] + i;
		f[i] = f[i - 1] + sum[i];
	}
	for (int i = 1; i <= m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
	}
	int s;
	cin >> s;
	memset(num_scc, -1, sizeof(num_scc));
	for (int i = 1; i <= n; i++) if (num[i] == 0) dfs(i);
	for (int i = 1; i <= n; i++) {
		//cout << i << " " <<num_scc[i] << '\n';
		for (auto v : adj[i]) 
			if (num_scc[i] != num_scc[v.fi]) adj2[num_scc[i]].push_back({num_scc[v.fi], v.se});
			else {
				ll l = 1, r = 10000, mid, ans = 0;
				while (l <= r) {
					 mid = (l + r) / 2;
					 //cout << v.se << " " << sum[mid] << '\n';
					 if (sum[mid] < v.se) {
					 	ans = mid;
					 	l = mid + 1;
					 }
					 else r = mid - 1;
				}
				sum_scc[num_scc[i]] += 1ll * v.se * (ans + 1) - f[ans];
			}
	}
	dfs2(num_scc[s]);
	cout << dp[num_scc[s]];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}