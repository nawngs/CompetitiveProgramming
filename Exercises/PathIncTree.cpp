#include <bits/stdc++.h>
#define pii pair <int, int>
#define fi first
#define se second

using namespace std;

int n, f[100005], g[100005], res = 1;

vector < pii > adj[100005];

struct Data{
	int val;
	int f;
	int g;
};

bool cmp (Data x, Data y){
	return x.val < y.val;
}

void dfs(int u, int e, int pre){
	f[u] = g[u]  = 0;
	vector < Data > max_f_g;
	for(auto v : adj[u]){
		if(v.fi == e) continue;
		dfs(v.fi, u, v.se);
		Data temp;
		temp.val = v.se;
		if(pre == -1){
			f[u] = max(f[u], f[v.fi] + 1);
			g[u] = max(g[u], g[v.fi] + 1);
			temp.f = f[v.fi] + 1;
			temp.g = g[v.fi] + 1;
		}
		else{
			if(v.se < pre){
				f[u] = max(f[u], f[v.fi] + 1);
				temp.f = f[v.fi] + 1;
				temp.g = 0;
			}
			else{
				g[u] = max(g[u], g[v.fi] + 1);
				temp.f = 0;
				temp.g = g[v.fi] + 1;
			}
		}
		max_f_g.push_back(temp);
	}
	sort(max_f_g.begin(), max_f_g.end(), cmp);
	if(max_f_g.size() >= 2){
		int maxf = max_f_g[0].f;
		res = max(res, max_f_g[0].g);
		for(int i = 1; i < max_f_g.size(); i++){
			res = max(res, maxf + max_f_g[i].g);
			maxf = max(maxf, max_f_g[i].f);
		}
	}
	if(max_f_g.size() == 1) res = max(res, max(max_f_g[0].f, max_f_g[0].g));
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("PathIncTree.inp", "r", stdin);
	//freopen("PathIncTree.out", "w", stdout);
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dfs(1, 0, -1);
	cout << res << '\n';
}
