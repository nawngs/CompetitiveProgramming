#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair < ll, ll>

using namespace std;

ll n, m, a[200005], d[200005];

vector < pll > adj[200005];

void dijkstra(){
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	for(int i = 1; i <= n; i++) heap.push({d[i], i});
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
	freopen("TICKET.inp", "r", stdin);
	freopen("TICKET.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		w *= 2;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		d[i] = a[i];
	}
	dijkstra();
	for(int i = 1; i <= n; i++) cout << d[i] << '\n';
}