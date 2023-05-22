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

const string NAME = "domino";
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

int n, timer = 0, num[200003], cnt;

bool res;

pii a[200003];

vector < int > adj[200003]; 

bool used[200003];

int get(int x, int u) {
	return a[x].fi + a[x].se - u;
}

void dfs(int u) {
	num[u] = ++ timer;
	for (auto v : adj[u]) {
		if (!num[v]) dfs(v);
		else {
			if ((num[v] - num[u]) % 2 == 0) res = 0;
			continue;
		}
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		num[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		adj[a[i].fi].push_back(a[i].se);
		adj[a[i].se].push_back(a[i].fi);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i].fi == a[i].se || adj[i].size() > 2) {
			cout << "No" << '\n';
			return ;
		}
	}
	timer = 0;
	res = 1;
	for (int i = 1; i <= n; i++) {
		if (num[i] == 0) dfs(i);
	}
	cout << (res ? "Yes" : "No") << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
