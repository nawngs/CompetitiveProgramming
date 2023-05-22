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

ll n, m, num_k, f[103][103], d[103][103], dis[103][103];

pll a[103][1003];

bool check(ll x) {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) {
			dis[i][j] = LINF;
			if (d[i][j] != LINF && i != j) dis[i][j] = min(dis[i][j], -f[i][j] + x * d[i][j]);
		}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1; i <= n; i++) if (dis[i][i] <= 0) return 1;
	
	return 0;
}

int main() {
	fast;
	cin >> n >> m >> num_k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= num_k; j++) cin >> a[i][j].fi >> a[i][j].se;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) d[i][j] = LINF;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		d[u][v] = c;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			for (int k = 1; k <= num_k; k++) 
				if (a[i][k].fi != -1 && a[j][k].se != -1) f[i][j] = max(f[i][j], a[j][k].se - a[i][k].fi);
	ll l = 1, r = 1e9, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}
