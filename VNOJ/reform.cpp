//link: https://oj.vnoi.info/problem/reform
#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
	
long long n, m, num[100005], low[100005], scc = 0, timeDFS = 0, cnt[3], cnt_bridge[3], child[100005];



vector < int > adj[100005];

vector < int > bridges;


void dfs(int u, int e) {
	num[u] = low[u] = ++ timeDFS;
	cnt[scc] ++;
	child[u] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (!num[v]) {
			dfs(v, u);
			child[u] += child[v];
			low[u] = min(low[u], low[v]);
			if(low[v] == num[v]) {
				cnt_bridge[scc] ++;
				bridges.push_back(v);
				//child[u] -= child[v];
			}
		}
		else{
			low[u] = min(low[u], num[v]);
		}
	}
	//cout << u << " " << child[u] << '\n';
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if(!num[i]){
			if (scc < 2) {
				scc ++;
				dfs(i, 0);
			}
			else {
				cout << 0;
				return 0;
			}
		}
	}
	//	cout << scc << '\n';
	if (scc == 1) {
		
		long long sum_edge = n * (n - 1) / 2;
		//cout << sum_edge << '\n';
		long long int unsigned ans = (sum_edge - m) * (m - cnt_bridge[1]);
		//cout << ans << '\n';
		for(auto v : bridges) {
			//cout << v << '\n';
			ans += child[v] * (n - child[v]) - 1;
		}
		cout << ans;
		return 0;
		//cout << 
	}
	if(scc == 2) {
		long long int unsigned ans = cnt[1] * cnt[2] * (m - cnt_bridge[1] - cnt_bridge[2]);
		cout << ans;
		return 0;
	}
}

