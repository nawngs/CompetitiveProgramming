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

int n, h1[103], h2[103], m, TestCase = 0;

bool matched[103][103];

vector < int > adj1[103], adj2[103], height1[103], height2[103];

void dfs(int u, int e) {
	for (auto v : adj1[u]) {
		if (v == e) continue;
		h1[v] = h1[u] + 1;
		dfs(v, u);
	}
}

void dfs2(int u, int e) {
	for (auto v : adj2[u]) {
		if (v == e) continue;
		h2[v] = h2[u] + 1;
		dfs2(v, u);
	}
}

int Assigned[203];
int Visited[203], t = 0;
vector<int> g[203];

bool visit(int u) {
    if (Visited[u] != t)
        Visited[u] = t;
    else
        return false;

    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!Assigned[v] || visit(Assigned[v])) {
            Assigned[v] = u;
            return true;
        }
    }
    return false;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) height1[i].clear(), adj1[i].clear(), h1[i] = 0;
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj1[u].push_back(v);
		adj1[v].push_back(u);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) height2[i].clear(), adj2[i].clear(), h2[i] = 0;
	for (int i = 1; i <= m - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}
	dfs(1, 0);
	dfs2(1, 0);
	int depth = 0;
	for (int i = 1; i <= n; i++) {
		height1[h1[i]].push_back(i);
		depth = max(depth, h1[i]);
	}
	for (int i = 1; i <= m; i++)
		height2[h2[i]].push_back(i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			matched[i][j] = false;
	for (int i = depth; i >= 0; i--) {
		for (auto u : height1[i])
			for (auto v : height2[i]) {
				int dem;
				dem = adj1[u].size() - (u != 1) + adj2[v].size() - (v != 1);
				for (int i = 1; i <= dem; i++) {
					g[i].clear();
					Visited[i] = 0;
					Assigned[i] = 0;
				}
				int cnt = 0;
				for (auto x : adj1[u]) {
					if (h1[x] < i) continue;
					cnt ++;
					int temp = adj1[u].size() - (u != 1);
					for (auto y : adj2[v]) {
						if (h2[y] < i) continue;
						temp ++;
						if (matched[x][y]) 
							g[cnt].push_back(temp);
					}
				}
				int Count = adj2[v].size() - (v != 1);
				t = 0;
			    for (int i = 1; i <= m; i++) {
			        t++;
			        Count -= visit(i);
    			}
    			if (!Count) matched[u][v] = 1;
			}
	}
	cout << "Case " << ++ TestCase << ": " << (matched[1][1] ? "Yes" : "No") << '\n';

}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
