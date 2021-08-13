//link: https://cantho20.kattis.com/problems/intelligenceexchange
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair < ll, ll > 

using namespace std;

const ll INF = 1E18;

ll n, m, hc, sc, hj, sj, start_c[500005], start_j[500005], last_c[500005], last_j[500005], check[500005];

vector < pll > adj[500005];

struct Data{
	int u, v, t;
} a[500005];

void dijkstra(ll start, ll last, ll d[]){
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	//ll d[500005];
	for(int i = 1; i <= n; i++) d[i] = INF;
	d[start] = 0;
	heap.push({d[start], start});
	while(heap.size()){
		pll u = heap.top();
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
	while(cin >> n >> m){
		ll ans = 0;
		if(n == 0 && m == 0) return 0;
		cin >> hc >> sc >> hj >> sj;
		for(int i = 1; i <= n; i++){
			check[i] = false;
			start_c[i] = 0;
			start_j[i] = 0;
			last_c[i] = 0;
			last_j[i] = 0;
			adj[i].clear();
		}
		for(int i = 1; i <= m; i++){
			cin >> a[i].u >> a[i].v >> a[i].t;
			adj[a[i].u].push_back({a[i].v, a[i].t});
			adj[a[i].v].push_back({a[i].u, a[i].t});
		}
		dijkstra(hc, sc, start_c);
		dijkstra(sc, hc, last_c);
		dijkstra(hj, sj, start_j);
		dijkstra(sj, hj, last_j);
		bool th = true;
		//###################################################################
		for(int i = 1; i <= m; i++){
			if(start_c[a[i].u] + a[i].t + last_c[a[i].v] == start_c[sc]
			&& start_j[a[i].u] + a[i].t + last_j[a[i].v] == start_j[sj]){
				th = false;
				cout << -1 << '\n';
				break;
			}
			if(start_c[a[i].v] + a[i].t + last_c[a[i].u] == start_c[sc]
			&& start_j[a[i].v] + a[i].t + last_j[a[i].u] == start_j[sj]){
				th = false;
				cout << -1 << '\n';
				break;
			}
		}
		if(!th) continue;
		//#############################################################
		for(int i = 1; i <= n; i++){
			if(start_c[i] + last_c[i] == start_c[sc] 
			&& start_j[i] + last_j[i] == start_j[sj]
			&& start_c[i] == start_j[i]){
				ans ++;
				check[i] = true;
			}
		}
		//##############################################################
		for(int i = 1; i <= m; i++){
			if(start_c[a[i].u] + a[i].t + last_c[a[i].v] == start_c[sc]
			&& start_j[a[i].v] + a[i].t + last_j[a[i].u] == start_j[sj]){
				ans = ans + (check[a[i].u] == false) + (check[a[i].v] == false);
				check[a[i].u] = check[a[i].v] = true; 
			}
			if(start_c[a[i].v] + a[i].t + last_c[a[i].u] == start_c[sc]
			&& start_j[a[i].u] + a[i].t + last_j[a[i].v] == start_j[sj]){
				ans = ans + (check[a[i].u] == false) + (check[a[i].v] == false);
				check[a[i].u] = check[a[i].v] = true; 
			}
		}
		//#################################################################
		if(sc == sj){
			ans ++;
			check[sc] = true;
		}
		if(start_c[sc] < start_j[sj]){
			for(auto vv : adj[sc]){
				ll v = vv.fi;
				//cout << start_j[v] + last_j[v] << " " << start_j[sj] << '\n';
				if(start_j[v] + last_j[v] == start_j[sj] //bruh
				&& start_c[sc] <= start_j[v]){
					ans = ans + (check[sc] == false) + (check[v] == false);
				 	check[sc] = check[v] = true;
				}
			}
		}
		else{
			for(auto vv : adj[sj]){
				ll v = vv.fi;
				if(start_c[v] + last_c[v] == start_c[sc]
				&& start_j[sj] <= start_c[v]){
					ans = ans  + (check[sj] == false) + (check[v] == false);
				 check[sj] = check[v] = true;
				}
			}
		}
		cout << ans << '\n';
	}
}