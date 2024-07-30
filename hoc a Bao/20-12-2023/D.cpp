#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 3e4;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, cnt[8 * N + 3], it[8 * N + 3];

vector < pii > add[N + 3], era[N + 3];

void update(int node, int l, int r, int u, int v, int val) {
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		cnt[node] += val;
		if (cnt[node] != 0) it[node] = r - l + 1;
		else it[node] = it[node * 2] + it[node * 2 + 1];
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	if (cnt[node] == 0) it[node] = it[node * 2] + it[node * 2 + 1];
	// cerr << u << " " << v << '\n';
	// cerr << l << " " << r << " " << it[node] << " " << cnt[node] << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		add[x1].pb({y1, y2});
		era[x2].pb({y1, y2});	
	}
	int res = 0;
	for (int i = 0; i <= N; i++) {
		for (auto x : add[i]) 
		update(1, 0, N, x.fi, x.se - 1, 1);
		for (auto x : era[i]) 
			update(1, 0, N, x.fi, x.se - 1, -1);
		res += it[1];
	}
	cout << res;
}