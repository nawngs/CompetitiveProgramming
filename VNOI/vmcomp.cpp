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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1E9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, sum, s[100003], it[600003];

bool th[100003];

vector < pll > adj[100003];

int minimize(int x, int y) {
	if (x == -1) return y;
	if (y == -1) return x;
	return (s[x] < s[y] ? x : y);
}

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = l;
		return ;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	it[node] = minimize(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		s[l] += val;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = minimize(it[node * 2], it[node * 2 + 1]);
}

void sol() {
	cin >> n >> m >> sum;
	memset(th, true, sizeof(th));
	for (int i = 1; i <= m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
		s[u] += c;
		s[v] += c;
	}
	build(1, 1, n);
	int ans = n;
	while (1) {
		if (ans == 0) break ;
		 if (s[it[1]] >= sum) break;
		 ans --;
		 th[it[1]] = false;
		 int pos = it[1];
		//cout << pos << '\n';
		 for (auto x : adj[pos]) if (th[x.fi]) update(1, 1, n, x.fi, -x.se);
		 update(1, 1, n, pos, INF);	
	}
	if (ans == 0) {
		cout << -1 << '\n';
		return ;
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) if (th[i]) cout << i << " ";
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
