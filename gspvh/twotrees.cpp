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

const string NAME = "twotrees";
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
int n, par1[4003], par2[4003], same[4003][4003], res[4003], cnt1[4003], cnt2[4003];

bool th[4003][4003], exist[4003];

pii edges1[4003], edges2[4003];

vector < int > adj1[4003], adj2[4003];

void dfs(int u, int e) {
	th[u][u] = 1;
	cnt1[u] = 1;
	for (auto v : adj1[u]) {
		if (v == e) continue;
		par1[v] = u;
		dfs(v, u);
		for (int i = 1; i <= n; i++)
			th[u][i] |= th[v][i];
		cnt1[u] += cnt1[v];
	}
}

void dfs2(int u, int e, int id) {
	same[id][u] = th[id][u];
	cnt2[u] = 1;
	for (auto v : adj2[u]) {
		if (v == e) continue;
		par2[v] = u;
		dfs2(v, u, id);
		same[id][u] += same[id][v];
		cnt2[u] += cnt2[v];
	}
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj1[u].push_back(v);
		adj1[v].push_back(u);
		edges1[i] = {u, v};
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj2[u].push_back(v);
		adj2[v].push_back(u);
		edges2[i] = {u, v};
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) 
		dfs2(1, 0, i);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int u1 = edges1[i].fi, v1 = edges1[i].se;
			int u2 = edges2[j].fi, v2 = edges2[j].se;
			if (par1[u1] == v1) swap(u1, v1);
			if (par2[u2] == v2) swap(u2, v2);
			int temp1 = same[v1][v2];
			int temp2 = cnt1[v1] - temp1;
			int temp3 = cnt2[v2] - temp1;
			int temp4 = (n - cnt1[v1]) - temp3;
			res[max(temp1, max(temp2, max(temp3, temp4)))] ++;
		}
	}
	for (int i = 0; i <= n; i++)
		cout << res[i] << " ";
}
