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

const string NAME = "test";
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

int n, m, timer = 0, num[100003], low[100003], cnt_child[100003], root_b = 1, root_a = 0, a, b, c, res[100003], root;

int cnt_a = 0, cnt_b = 0;

bool give[100003], vs[100003];

vector < int > adj[100003];

void dfs(int u = 1, int e = 0) {
	num[u] = low[u] = ++ timer;
	cnt_child[u] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (!num[v]) {
			dfs(v, u);
			cnt_child[u] += cnt_child[v];
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
}

void dfs_find(int u = 1) {
	vs[u] = 1;
	for (auto v : adj[u]) {
		if (num[v] < num[u] || vs[v]) continue;
		dfs_find(v);
	}
	if (root_a == 0) {
		bool th = (cnt_child[u] >= a);
		if (!th) return ;
		for (auto v : adj[u]) {
			if (num[v] < num[u]) continue ;
			if (cnt_child[v] >= a) return ;
		}
		if (n - cnt_child[u] < a) {
			th = false;
			int cnt = n - cnt_child[u];
			for (auto v : adj[u]) {
				if (num[v] < num[u]) continue;
				if (low[v] < num[u]) {
					cnt += cnt_child[v];
					cnt_child[u] -= cnt_child[v];
					give[v] = 1;
				}
				if (cnt >= a) {
					th = (cnt_child[u] >= a);
					break;
				}
			}
			if (!th)  
				for (auto v : adj[u]) {
					if (give[v]) cnt_child[u] += cnt_child[v];
					give[v] = false;
				}

		}
		if (th) root_a = root = u;
	}
}

void dfs_a(int u) {
	if (cnt_a == a) return ;
	cnt_a ++;
	res[u] = 2;
	for (auto v : adj[u]) {
		if (v == root_b || res[v] != 0) continue;
		if (root_a != root && give[v]) dfs_a(v);
		else {
			if (num[v] < num[u]) continue;
			dfs_a(v);
		}
	}
}

void dfs_b(int u) {
	if (cnt_b == b) return ;
	cnt_b ++;
	res[u] = 1;
	for (auto v : adj[u]) {
		if (v == root_a || res[v] != 0) continue;
		if (root_b != root && give[v]) dfs_b(v);
		else {
			if (num[v] < num[u]) continue;
			dfs_b(v);
		}
	}
}

vector<int> find_split(int _n, int x, int y, int z, vector<int> p, vector<int> q) {
    n = _n, m = p.size();
    vector < pii > temp;
	temp.push_back({x, 1});
	temp.push_back({y, 2});
	temp.push_back({z, 3});
	sort(temp.begin(), temp.end());
	a = temp[0].fi;
	b = temp[1].fi;
	c = temp[2].fi;
    for (int i = 0; i < m; i++) {
        int u = p[i], v = q[i];
        u++, v++;       
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   	dfs();
	dfs_find();
	vector < int > ans(n, 0);
	if (root_a == 0) return ans;
	if (cnt_child[root_a] >= b) swap(root_a, root_b);
	if (root_a == root) {
		dfs_a(root_a);
		dfs_b(root_b);
	}
	else {
		dfs_b(root_b);
		dfs_a(root_a);
	}
	for (int i = 1; i <= n; i++) ans[i - 1] = temp[2 - res[i]].se;
	return ans;
}



int main() {
	fast;
	fre();
	cin >> n >> m >> a >> b >> c;
	vector<int> p, q;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		p.push_back(u);
		q.push_back(v);
	}
	auto ans = find_split(n, a, b, c, p, q);
	for (auto i : ans)
		cout << i << ' ';
}

