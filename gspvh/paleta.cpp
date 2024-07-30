#include <bits/stdc++.h>

#define name "paleta"
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
const int N = 1e6;
const ll MOD = 998244353;
const ll BASE = 2309;

int n, par[N + 3], sze[N + 3], k, maxx[N + 3], num[N + 3], low[N + 3], timer = 0, temp = 0;

ll pw[N + 3];

bool deleted[N + 3];

stack < int > st;

vector < int > adj[N + 3];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

bool join(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	if (sze[u] < sze[v]) swap(u, v);
	sze[u] += sze[v]; par[v] = u;
	return true;
}

void dfs(int u) {
	num[u] = low[u] = ++ timer;
	st.push(u);
	for (auto v : adj[u]) if (!deleted[v]) {
		if (!num[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
	if (low[u] == num[u]) {
		int cnt = 1;
		while (st.size() && st.top() != u) {
			cnt ++;
			deleted[st.top()] = 1; st.pop();
		}
		if (!st.size()) {
			cout << "dmm" << '\n';
			exit(0);
		}
		deleted[u] = 1; st.pop();
		temp = max(temp, cnt);
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> n >> k;
	pw[0] = 1;
	for (int i = 1; i <= n; i++) par[i] = i, sze[i] = 1, pw[i] = (pw[i - 1] * (k - 1)) % MOD;
	for (int i = 1; i <= n; i++) {
		int u; cin >> u;
		if(u != i) join(u, i);
		if (u != i) adj[i].pb(u);
	}
	for (int i = 1; i <= n; i++) if (!num[i]) {
		int u = find(i);
		temp = 0; dfs(i);
		maxx[u] = max(maxx[u], temp);
	}
	ll res = 1;
	for (int i = 1; i <= n; i++) if (i == find(i)) {
		assert(maxx[i] <= sze[i]);
		res = (res * pw[sze[i] - 1 - (maxx[i] > 2)]) % MOD;
		res = (res * k) % MOD;
		if (maxx[i] > 2) res = (res * (k - 2)) % MOD;
	}
	cout << res;
}