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

const string NAME = "XungYeu";
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

struct Edge {
	ll u, v, c;
	Edge(ll _u, ll _v, ll _c) : u(_u), v(_v), c(_c) {};
};

vector < Edge > edges;

ll n, m, f[100003], g[100003], cntf[100003], cntg[100003], dist[100003], cnt[100003];

vector < pll > adj[100003];

void dijkstra(ll start) {
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		cnt[i] = 0;
	}
	dist[start] = 0;
	cnt[start] = 1;
	heap.push({0, start});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != dist[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (dist[v.fi] > dist[u.se] + v.se) {
				dist[v.fi] = dist[u.se] + v.se;
				cnt[v.fi] = cnt[u.se];
				heap.push({dist[v.fi], v.fi});
			}
			else if (dist[v.fi] == dist[u.se] + v.se) cnt[v.fi] += cnt[u.se];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (start == 1) {
			f[i] = dist[i];
			cntf[i] = cnt[i];
		}
		else {
			g[i] = dist[i];
			cntg[i] = cnt[i];
		}
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
		edges.push_back({u, v, c});
	}
	dijkstra(1);
	dijkstra(n);
	ll res = 0;
	for (int i = 0; i < m; i++) {
		auto x = edges[i];
		if ((f[x.u] + g[x.v] + x.c == f[n] && cntf[x.u] * cntg[x.v] == cntf[n])
		  ||(g[x.u] + f[x.v] + x.c == f[n] && cntg[x.u] * cntf[x.v] == cntf[n])) res ++;
	}
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}


/*
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

const string NAME = "XungYeu";
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

struct Edge {
	ll u, v, c;
	Edge(ll _u, ll _v, ll _c) : u(_u), v(_v), c(_c) {};
};

vector < Edge > edges;

ll n, m;

pll dist1[100003], distn[100003];


vector < pll > adj[100003];

void dijkstra(ll start, pll dist[]) {
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	for (int i = 1; i <= n; i++) dist[i].fi = INF;
	dist[start].fi = 0;
	dist[start].se = 1;
	heap.push({0, start});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != dist[u.se].fi) continue;
		for (auto v : adj[u.se]) {
			if (dist[v.fi].fi > dist[u.se].fi + v.se) {
				dist[v.fi].fi = dist[u.se].fi + v.se;
				dist[v.fi].se = dist[u.se].se;
				heap.push({dist[v.fi].fi, v.fi});
			}
			else if (dist[v.fi].fi == dist[u.se].fi + v.se) dist[v.fi].se += dist[u.se].se;
		}
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
		edges.push_back({u, v, c});
	}
	dijkstra(1, dist1);
	dijkstra(n, distn);
	ll res = 0;
	for (int i = 0; i < m; i++) {
		auto x = edges[i];
		if ((dist1[x.u].fi + distn[x.v].fi + x.c == dist1[n].fi && dist1[x.u].se * distn[x.v].se == dist1[n].se)
		  ||(dist1[x.v].fi + distn[x.u].fi + x.c == dist1[n].fi && dist1[x.v].se * distn[x.u].se == dist1[n].se)) res ++;
	}
	cout << res;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
*/