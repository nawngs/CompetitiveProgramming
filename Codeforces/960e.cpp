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

ll n, a[200003], cnt_child[200003], res = 0;

bool used[200003];

vector < ll > adj[200003];

pll sub, odd_rev, even_rev;

int dfs(int u, int e = 0) {
	cnt_child[u] = 1;
	for (auto v : adj[u]) {
		if (v == e || used[v]) continue;
		cnt_child[u] += dfs(v, u);
	}
	return cnt_child[u];
}

int get_centroid(int u, int sze, int e = 0) {
	for (auto v : adj[u]) {
		if (used[v] || v == e) continue;
		if (cnt_child[v] * 2 > sze) return get_centroid(v, sze, u);
	}
	return u;
}

ll get_mod(ll x) {
	x = ((x % MOD) + MOD) % MOD;
	return x;
}

void dfs3(int u, int e, int len, ll val, ll rev, bool update) {
	ll new_val = get_mod(val + a[u] * (len % 2 == 1 ? 1 : -1));
	ll new_rev = get_mod(rev * -1 + a[u]);
	 if (update) {
		res = get_mod(res + new_val);
		res = get_mod(res + even_rev.fi + get_mod(new_val * even_rev.se));
		res = get_mod(res + odd_rev.fi - get_mod(new_val * odd_rev.se));
		res = get_mod(res + (len % 2 == 0 ? -1 : 1) * sub.fi + get_mod(new_rev * sub.se));
	}
	else {
		sub.fi = get_mod(sub.fi + new_val);
		sub.se = get_mod(sub.se + 1);	
		if (len % 2 == 0) {
			odd_rev.fi = get_mod(odd_rev.fi + new_rev);
			odd_rev.se = get_mod(odd_rev.se + 1);
		}
		else {
			even_rev.fi = get_mod(even_rev.fi + new_rev);
			even_rev.se = get_mod(even_rev.se + 1);
		}
	}
	for (auto v : adj[u]) {
		if (v == e || used[v]) continue;
		dfs3(v, u, len + 1, new_val, new_rev, update);
	}
}

void centroid(int u = 1) {
	int C = get_centroid(u, dfs(u));
	used[C] = 1;
	res = get_mod(res + a[C]);
	sub = {a[C], 1};
	odd_rev = {0, 0};
	even_rev = {0, 0};
	for (auto v : adj[C]) {
		if (!used[v]) {
			dfs3(v, C, 2, a[C], 0, 1);
			dfs3(v, C, 2, a[C], 0, 0);
		}
	}
	for (auto v : adj[C]) 
		if (!used[v]) centroid(v);
}

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid();
	cout << res;
}
