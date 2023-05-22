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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, k, d[100003], trace[100003], special[100003], dis = 0;

pii min_dis = {-1, -1};

vector < pii > adj[100003], pos1, pos2;

void dijkstra(pii invalid) {
	dis = INF;
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	for (int i = 1; i <= n; i++) 
		d[i] = INF, trace[i] = -1;
	for (int i = 1; i <= k; i++) {
		if (special[i] == invalid.fi || special[i] == invalid.se) continue;
		d[special[i]] = 0;
		trace[special[i]] = special[i];
		heap.push({0, special[i]});
	}
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[v.fi] > u.fi + v.se) {
				d[v.fi] = u.fi + v.se;
				trace[v.fi] = trace[u.se];
				heap.push({d[v.fi], v.fi});
			}
			if (trace[u.se] != trace[v.fi] && trace[u.se] != -1 && trace[v.fi] != -1) {
				if (dis > d[u.se] + d[v.fi] + v.se) {
					dis = d[u.se] + d[v.fi] + v.se;
					min_dis = {trace[u.se], trace[v.fi]};
				}	
			}
		}
	}
}

void dijkstra(int start, vector < pii > &pos) {
	for (int i = 1; i <= n; i++) 
		d[i] = INF;
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	d[start] = 0;
	heap.push({0, start});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[v.fi] > u.fi + v.se) {
				d[v.fi] = u.fi + v.se;
				heap.push({d[v.fi], v.fi});
			}
		}
	}
	for (int i = 1; i <= k; i++) {
		if (special[i] == start) continue;
		pos.push_back({d[special[i]], special[i]});
	}
	sort(pos.begin(), pos.end());
	for (auto x : pos) {
		cout << x.fi << " " << x.se << '\n';
	}
}

int main() {
	fast;
	//fre();
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	for (int i = 1; i <= k; i++) 
		cin >> special[i];
	dijkstra(min_dis);
	pii temp = min_dis;
	int res = dis;
	dijkstra(min_dis);
	res += dis;
	dijkstra(temp.fi, pos1);
	dijkstra(temp.se, pos2);
	int val = INF;
	for (int i = 0; i < min((int) pos1.size(), 3); i++)
		for (int j = 0; j < min((int) pos2.size(), 3); j++) {
			if (pos1[i].se == temp.se || pos1[i].se == pos2[j].se || pos2[j].se == temp.fi) continue;
			val = min(val, pos2[j].fi + pos1[i].fi);
		}	
	cout << min(res, val);
}
