// link: https://oj.vnoi.info/problem/dhserv
#include <bits/stdc++.h>
#define ll long long
#define pll pair < long long, long long >
#define fi first
#define se second

using namespace std;

const ll INF = 1E18;
ll n, m, k;
vector < pll > adj[505];
bool check[505];

ll dijkstra(ll start, ll end){
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	ll d[505];
	for(int i = 1; i <= n; i++) d[i] = INF;
	d[start] = 0;
	heap.push({d[start], start});
	while(heap.size() > 0){
		pll u = heap.top();
		//cout << u.se << '\n';
		heap.pop();
		if(d[u.se] != u.fi) continue;
		for(auto v : adj[u.se]){
			if(check[v.fi]){
				if(d[v.fi] > d[u.se] + v.se){
					d[v.fi] = d[u.se] + v.se;
					heap.push({d[v.fi], v.fi});
				}
			}
		}
	}
	if(d[end] == INF) return -1;
	else return d[end];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	memset(check, false, sizeof(check));
	for(int i = 1; i <= m; i++){
		ll x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({y, z});
	}
	for(int i = 1; i <= k; i++){
		ll x, u, v;
		cin >> x;
		if(x == 1){
			cin >> u;
			check[u] = true;
		}
		else{
			cin >> u >> v;
			bool ktu = false, ktv = false;
			if(check[u] == false){
				check[u] = true;
				ktu = true;
			}
			if(!check[v]){
				check[v] = true;
				ktv = true;
			}
			cout << dijkstra(u, v) << '\n';
			if(ktu == true) check[u] = false;
			if(ktv == true) check[v] = false;
		}
	}
}

