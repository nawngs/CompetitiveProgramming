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

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	//	freopen(fout.c_str(), "w", stdout);
}

ll n, p[200003], m, pw[200003], par[200003], res = 0, scc;

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

void calc(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) 
		return ;
	res += ((m * (m - 1) / 2)) % MOD * pw[scc - 2];
	res %= MOD;
	scc --;
	par[v] = u;
}

main() {
	fast;
	fre();
	cin >> n >> m;
	scc = n;
	pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		pw[i] = (pw[i - 1] * m) % MOD;
		par[i] = i;
	}
	for (int i = 1; i <= n; i++) 
		calc(i, p[i]);
	
	cout << res << '\n';
}
