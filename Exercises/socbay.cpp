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

const string NAME = "socbay";
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

ll n, m, h, a[100003], d[100003];

vector < pll > adj[100003];

int main() {
	fast;
	//fre();
	cin >> n >> m >> h;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = LINF;
	}
	for (int i = 1; i <= m; i++) {
		ll u, v, c; cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	d[1] = 0;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	heap.push({0, 1});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[u.se]) continue;
		int pos = min(a[u.se], max(0ll, h - u.fi));
		if (u.se == n) {
			cout << u.fi + a[n] - pos << '\n';
			return 0;
		}
		for (auto v : adj[u.se]) {
			ll c = LINF;
			if (0 <= pos - v.se && pos - v.se <= a[v.fi]) c = v.se;
			else if (pos - v.se < 0 && pos + 0 - (pos - v.se) <= a[u.se]) c = v.se + 0 - (pos - v.se);
			else if (pos - v.se >= a[v.fi] && pos >= (pos - v.se) - a[v.fi]) c = v.se + (pos - v.se) - a[v.fi];
			if (d[v.fi] > u.fi + c) {
				d[v.fi] = u.fi + c;
				heap.push({d[v.fi], v.fi});
			} 
		}
	}
	cout << -1;
}
