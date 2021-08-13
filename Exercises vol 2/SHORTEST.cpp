#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair < ll, ll>

using namespace std;

const ll INF = 1E18 + 7;

ll n, m, s, d[100005];

vector < pll > adj[100005];

void dijkstra(int start){
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	for(long long i = 1; i <= n; i++) d[i] = INF;
	d[start] = 0;
	heap.push({d[start], start});
	while(heap.size()){
		auto u = heap.top();
		heap.pop();
		if(u.fi != d[u.se]) continue;
		for(auto v : adj[u.se]){
			if(d[v.fi] > d[u.se] + v.se){
				d[v.fi] = d[u.se] + v.se;
				heap.push({d[v.fi], v.fi});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("SHORTEST.inp", "r", stdin);
	freopen("SHORTEST.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dijkstra(s);
	for(int i = 1; i <= n; i++) d[i] == INF ? cout << "NO PATH" << '\n' : cout << d[i] << '\n';
}