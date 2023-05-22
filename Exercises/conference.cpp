	#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "conference";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, k, res1[1000005], res2[1000005], check[1000005];

pii near[1000005];

pii day[1000005];

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) check[i] = INF;
	for (int i = 1; i <= m; i++) {
		cin >> day[i].fi >> day[i].se;
		if (day[i].fi > day[i].se) swap(day[i].fi, day[i].se);
	}
	for (int i = m; i >= 1; i--) {
		int u = day[i].fi;
		int v = day[i].se;
		if (u <= k && v > k) {
			if (res1[u] == 0) {
				res1[u] = i;
				res2[u] = v;
				check[v] = min(check[v], i);
				check[u] = min(check[u], i);
			}
			near[u].fi = v;
			near[u].se = i;
		}
		if (u <= k && v <= k) {
			if (res1[u] != 0 && res1[v] != 0) {
				if (near[u].se < near[v].se) near[v] = near[u];
				else near[u] = near[v];
				continue;
			}
			if (res1[u] == 0 && res1[v] == 0) continue;
			if (res1[v] != 0) swap(u, v);
			res1[v] = i;
			res2[v] = near[u].fi;
			near[v] = near[u];
			check[v] = min(check[v], i);
			check[u] = min(check[u], i);
		}
	}
	for (int i = 1; i <= m; i++) {
		int u = day[i].fi;
		int v = day[i].se;
		if (check[u] <= i) check[v] = min(check[v], i);
		if (check[v] <= i) check[u] = min(check[u], i);	
	}
	for (int i = 1; i <= k; i++) cout << (res1[i] == 0 ? -1 : res1[i]) << " ";
	cout << '\n';
	int dem = 0;
	for (int i = k + 1; i <= n; i++) if (check[i] != INF) dem ++;
	cout << dem << " ";
	for (int i = k + 1; i <= n; i++) if (check[i] != INF) cout << i << ' ';
	cout << '\n';
	for (int i = 1; i <= k; i++) cout << (res2[i] == 0 ? -1 : res2[i]) << " ";
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
	