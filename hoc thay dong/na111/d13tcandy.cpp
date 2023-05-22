#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, cnt[NMAX + 3], dem[NMAX + 3];

vector < int > adj[NMAX + 3];

void dfs(int u, int e) {
	cnt[u] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u); cnt[u] += cnt[v];
	}
	dem[cnt[u]] ++;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 2; i <= n; i++)
		for (int j = 2 * i; j <= n; j+=i) dem[i] += dem[j];
	vector < int > res;
	res.push_back(n);
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			if (dem[i] >= n / i) res.push_back(n / i);
			if (n / i != i && dem[n / i] >= i) res.push_back(i);
		}
	}
	sort(res.begin(), res.end());
	for (auto x : res) cout << x - 1 << " ";
}