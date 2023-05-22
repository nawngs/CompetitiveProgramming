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

int n, cnt_child[200003], par[200003];

int chain_id[200005], nchain = 0;

vector < int > adj[200003], val[200003];

void dfs(int u = 1) {
	cnt_child[u] = 1;
	for (auto v : adj[u]) {
		if (v == par[u]) continue;
		par[v] = u;
		dfs(v);
		cnt_child[u] += cnt_child[v];
	}
}

void hld(int u = 1) {
	chain_id[u] = nchain;
	val[nchain].push_back(u);
	int max_v = -1;
	for (auto v : adj[u]) {
		if (v == par[u]) continue;
		if (max_v == -1 || cnt_child[v] > cnt_child[max_v]) max_v = v;
	}
	if (max_v != -1) hld(max_v);
	for (auto v : adj[u]) {
		if (v == par[u] || v == max_v) continue;
		nchain ++;
		hld(v);
	}
}

int ask_d(int u) {
	cout << "d" << " " << u << endl;
	int x;
	cin >> x;
	return x;
}	

int ask_s(int u) {
	cout << "s" << " " << u << endl;
	int x;
	cin >> x;
	return x;
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	hld();
	int dis = ask_d(1);
	int cur = 1;
	while (1) {
		int id = chain_id[cur];
		if (val[id].size() <= dis) {
			int new_u = val[id].back();
			int tam = ask_d(new_u);
			//cout << (val[id].size() - 1 + dis - tam) / 2 << '\n';
			int dis_s = (val[id].size() - 1 + dis - tam) / 2;
			int s = val[id][dis_s];
			cur = ask_s(s);
			dis = dis - dis_s - 1;
		}
		else {
			int new_u = val[id][dis];
			int tam = ask_d(new_u);
			if (tam == 0) {
				cout << "!" << " " << new_u << endl;
				return 0;
			}
			int s = val[id][dis - (tam / 2)];
			cur = ask_s(s);
			dis = (tam / 2) - 1;
		}
	}
	else [
]
}
