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

const string NAME = "scoring";
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

ll n, k, a[100003], res = 1, frac[100003], cnt[100003];

vector < int > adj[100003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	if (k > n) return 0;
	return (frac[n] * mu((frac[k] * frac[n - k]) % MOD, MOD - 2)) % MOD;
}

void dfs(int u, int e) {
	cnt[u] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		cnt[u] += cnt[v];
	}
	ll cur = cnt[u] - 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		res = (res * C(cnt[v], cur)) % MOD;
		cur -= cnt[v];
	}
}

main() {
	fast;
	//fre();
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int root = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) root = i;
	}
	frac[0] = 1;
	for (int i = 1; i <= n; i++) {
		frac[i] = (frac[i - 1] * i) % MOD;
		res = (res * (k - i + 1)) % MOD;
	}
	res = (res * mu(frac[n], MOD - 2)) % MOD;
	dfs(root, 0);
	cout << res;
}
