#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "Airplane";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

struct Edge {
	int v, s, t;
	Edge(int _v, int _s, int _t) : v(_v), s(_s), t(_t) {};
};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, r, p, x[100005], y[100005], s[100005], t[100005];

ll dp[200005];

piii f[200005];

vector < Edge > adj[200005];

void roi_rac() {
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		f[++ cnt].fi = x[i];
		f[cnt].se.fi = 1;
		f[cnt].se.se = i;
		f[++ cnt].fi = y[i];
		f[cnt].se.fi = 2;
		f[cnt].se.se = i;
	}
	sort(f + 1, f + cnt + 1);
	f[0].fi = -1E9;
	int dem = 0;
	for (int i = 1; i <= cnt; i++) {
		dem += (f[i].fi != f[i - 1].fi);
		if (f[i].se.fi == 1) x[f[i].se.se] = dem;
		else y[f[i].se.se] = dem;
	}
}

void dijkstra() {
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	for (int i = 1; i <= 2 * n; i++) dp[i] = INF;
	dp[x[0]] = r;
	heap.push({dp[x[0]], x[0]});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != dp[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (u.fi + p >= v.s) continue;
			if (dp[v.v] > v.t) {
				dp[v.v] = v.t;
				heap.push({dp[v.v], v.v});
			}
		}
	}
	cout << dp[y[0]] << '\n';
}

void sol() {
	cin >> x[0] >> y[0] >> n >> r >> p;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> s[i] >> t[i];
	roi_rac();
	for (int i = 1; i <= n; i++) adj[x[i]].push_back({y[i], s[i], t[i]});
	dijkstra();
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
