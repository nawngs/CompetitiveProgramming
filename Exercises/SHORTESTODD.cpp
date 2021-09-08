#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair < long long, long long >

using namespace std;

const ll INF = 1E18;

ll n, m, s, t;

vector < pll > adj[100005];

void dijkstra(){
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	ll d[100005];
	ll cnt[100005];
	for(int i = 1; i <= n; i++){
		d[i] = INF;
		cnt[i] = 0;
	}
	d[s] = 0;
	cnt[s] += s % 2;
	heap.push({d[s], s});
	while(heap.size()){
		auto u = heap.top();
		heap.pop(); 
		//cout << u.se << '\n';
		if(u.fi != d[u.se]) continue;
		for(auto v : adj[u.se]){
			if(d[v.fi] > d[u.se] + v.se){
				d[v.fi] = d[u.se] + v.se;
				cnt[v.fi] = cnt[u.se] + (v.fi % 2);
				heap.push({d[v.fi], v.fi});
			}
			else if(d[v.fi] == d[u.se] + v.se) cnt[v.fi] = max(cnt[v.fi], cnt[u.se] + (v.fi % 2));
		}
	}
	if(d[t] == INF){
		cout << -1;
		return ;
	}
	cout << d[t] << " " << cnt[t] << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("SHORTESTODD.inp", "r", stdin);
	freopen("SHORTESTODD.out", "w", stdout);
	cin >> n >> m >> s >> t;
	for(int i = 1; i <= m; i++){
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dijkstra();
}
