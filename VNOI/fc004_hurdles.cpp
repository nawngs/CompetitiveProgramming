#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair < ll, ll > 
#define ll long long

using namespace std;

const ll INF = 1E9;

ll n, m, f[305][305], q;
vector <pii> adj[305];

void dijkstra(int start){
	priority_queue < pii, vector < pii > , greater < pii > > heap;
	for(ll i = 1; i <= n; i++) f[start][i] = INF;
	f[start][start] = 0;	
	heap.push({f[start][start], start});
	while(heap.size()){
		pii u = heap.top();
		heap.pop();
		if(u.fi != f[start][u.se]) continue;
		for(auto v : adj[u.se]){
			if(f[start][v.fi] > max(v.se, f[start][u.se])){
				f[start][v.fi] = max(v.se, f[start][u.se]);
				heap.push({f[start][v.fi], v.fi});
			}
		}

	}
}

int main(){
	cin >> n >> m >> q;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	for(int i = 1; i <= n; i++) dijkstra(i);
	while(q --){
		int u, v;
		cin >> u >> v;
		f[u][v] == INF ? cout << -1 << '\n' : cout << f[u][v] << '\n';
	}
}