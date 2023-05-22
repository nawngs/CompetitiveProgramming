#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define plll pair < ll, pair < ll, ll > >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, k, l, a[100005], dp[100005][33];

vector < pll > adj[100005];

ll cnt_bits(ll x) {
	ll cnt = 0;
	while (x) {
		cnt += x & 1;
		x >>= 1;
	}
	return cnt;
}

void dijkstra() {
	priority_queue < plll, vector < plll > , greater < plll > > heap;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 33; j++) dp[i][j] = INF;
	dp[1][a[1]] = 0;
	heap.push({dp[1][a[1]], {1, a[1]}});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != dp[u.se.fi][u.se.se]) continue;
		for (auto v : adj[u.se.fi]) {
			ll tam = (u.se.se | a[v.fi]);
			if (dp[v.fi][tam] > u.fi + v.se) {
				dp[v.fi][tam] = u.fi + v.se;
				heap.push({dp[v.fi][tam], {v.fi, tam}});
			}
		}
	}
	ll ans = INF;
	for (int i = 0; i < 33; i++) if (cnt_bits(i) >= l) ans = min(ans, dp[n][i]);
	cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
	fast;
	//fre();
	cin >> n >> m >> k >> l;
	for (int i = 1; i <= n; i++) {
		ll s;
		cin >> s;
		while (s --) {
			ll x;
			cin >> x;
			x --;
			a[i] += (1 << x);
		}
	}
	for (int i = 1; i <= m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	dijkstra();
}
