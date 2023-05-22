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

int n, k, query[1000003], dp[1000003], par[1000003], temp = 0;

bool use[1000003], in_st[1000003];

vector < pii > adj[1000003];

stack < int > st;

void dfs(int u) {
	if (u != 0) {
		dp[u] = dp[par[u]] + 1;
		if (use[u]) dp[u] = min(dp[u], st.top() + temp + 1);
		int tam = dp[u] - temp;
		if (tam < st.top()) {
			st.push(tam);
			in_st[u] = 1;
		}
		temp += use[u];
	}
	else {
		st.push(0);
		in_st[0] = 1;
	}
	for (auto v : adj[u]) 
		dfs(v.fi);
	if (in_st[u]) st.pop();
	in_st[u] = false;
	
}

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u;
		char c;
		cin >> u >> c;
		par[i] = u;
		c -= 'a';
		adj[u].push_back({i, c});
	}
	for (int i = 0; i <= n; i++) sort(adj[i].begin(), adj[i].end(), [&](pii &x, pii &y) {
		return x.se < y.se;
	});
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> query[i];
		use[query[i]] = 1;
	}
	dfs(0);
	for (int i = 1; i <= k; i++) cout << dp[query[i]] << ' ';
}
