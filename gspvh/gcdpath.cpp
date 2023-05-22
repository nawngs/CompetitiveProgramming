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

const string NAME = "gcdpath";
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

ll n, a[300003], cnt[1500003], cnt_res[1500003], cnt_child[300003];

bool used[300003];

vector < int > adj[300003], divv[1500003];

int dfs(int u, int e = 0) {
	for (auto v : adj[u]) {
		if (v == e || used[v]) continue;
		cnt_child[u] += dfs(v, u);
	}
	cnt_child[u] ++;
	return cnt_child[u];
}

int get_centroid(int u, int sze, int e = 0) {
	for (auto v : adj[u]) {
		if (v == e || used[v]) continue;
		if (cnt_child[v] * 2 > sze) return get_centroid(v, sze, u);
	}
	return u;
}

void dfs2(int u, int e, int val, bool update) {
	if (!update) 
		for (auto x : divv[val]) {
			cnt_res[x] += cnt[x];
		}
	else {
		for (auto x : divv[val]) {
			cnt_res[x] ++;
			cnt[x] ++;
		}
	}
	for (auto v : adj[u]) {
		if (v == e || used[v]) continue;
		dfs2(v, u, __gcd(1ll * val, a[v]), update);
	}
}

void centroid(int u = 1) {
	int C = get_centroid(u, dfs(u));
	used[C] = 1;
	memset(cnt, 0, sizeof(cnt));
	for (auto v : adj[C]) {
		if (used[v]) continue;
		dfs2(v, C, __gcd(a[v], a[C]), 0);
		dfs2(v, C, __gcd(a[v], a[C]), 1);
	}
	for (auto v : adj[C]) 
		if (!used[v]) centroid(v);
	
} 

int main() {
	fast;
	fre();
	int O; cin >> O;
	for (int i = 1; i <= 1500000; i++)
		for (int j = i; j <= 1500000; j+=i) divv[j].push_back(i);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid();
	ll res = 0;
	for (int i = 1500000; i >= 1; i--) {
		for (int j =  2 * i; j <= 1500000; j+=i) cnt_res[i] -= cnt_res[j];
		res += 1ll * i * cnt_res[i];
	}
	cout << res;
}
