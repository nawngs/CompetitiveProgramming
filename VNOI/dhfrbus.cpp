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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, k, s, t, f[100005][7];
vector < pll > adj[100005];

void dijkstra(int level){
	priority_queue < pll , vector < pll > , greater < pll > > heap;
	for(int i = 1; i <= n; i++) f[i][level] = INF;
	f[s][level] = 0;
	heap.push({0, s});
	while(heap.size()){
		pll u = heap.top();
		//cout << u.fi  << " " << u.se << '\n';
		heap.pop();
		if(f[u.se][level] != u.fi) continue;
		for(auto v : adj[u.se]){
			if(level == 0){
				if(f[v.fi][level] > f[u.se][level] + v.se){
					f[v.fi][level] = f[u.se][level] + v.se;
					heap.push({f[v.fi][level], v.fi});
				}
			}
			else{
				if(f[v.fi][level] >  min(f[u.se][level] + v.se, f[u.se][level - 1])){
					f[v.fi][level] = min(f[u.se][level] + v.se, f[u.se][level - 1]);
					heap.push({f[v.fi][level], v.fi});
				}
			}
		}
	}
}

void sol() {
	cin >> n >> m >> k >> s >> t;
	for(int i = 1; i <= m; i++){
		int u , v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	for(int i = 0; i <= k; i++) dijkstra(i);
	cout << f[t][k];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
