#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "cauluong";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;	
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Edge {
	int v, w, id;
	Edge(int _v, int _w, int _id) : v(_v), w(_w), id(_id) {};
};

int n, m, res[5003], d[1503], b[1503], dp1[1503], dp2[1503];

vector < Edge > adj[1503];

vector < pii > f[1503];

void dijkstra(int st) {
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
		f[i].clear();
	}
	d[st] = 0;
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	heap.push({d[st], st});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto e : adj[u.se]) 
			if (d[e.v] > u.fi + e.w) {
				d[e.v] = u.fi + e.w;
				heap.push({d[e.v], e.v});
			}
	}
	for (int i = 1; i <= n; i++) {
		b[i] = i;
		dp2[i] = 1;
		dp1[i] = 0;
	}
	sort(b + 1, b + n + 1, [&](int &x, int &y) {
		return d[x] < d[y];
	});
	dp1[b[1]] = 1;
	for (int i = 1; i <= n; i++) 
		for (auto x : adj[b[i]]) 
			if (d[x.v] == d[b[i]] + x.w) {
				dp1[x.v] = (dp1[x.v] + dp1[b[i]]) % MOD;
				f[x.v].push_back({b[i], x.id});
			}
	for (int i = n; i >= 1; i--) 
		for (auto x : f[b[i]]) 
			dp2[x.fi] = (dp2[x.fi] + dp2[b[i]]) % MOD;
	for (int i = n; i >= 1; i--)
		for (auto x : f[b[i]])
			res[x.se] = (res[x.se] + dp1[x.fi] * dp2[b[i]]) % MOD;
}

 main() {
	fast;
	//fre();
	int O; cin >> O;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].push_back({v, c, i});
	}
	 for (int i = 1; i <= n; i++) 
	  	dijkstra(i);
	for (int i = 1; i <= m; i++)
		cout << res[i] << '\n';
}
