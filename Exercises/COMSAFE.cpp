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

const string NAME = "comsafe";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, cnt[100005], d[100005];

vector < int > adj[100005];

void bfs() {
	queue < int > q;
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[1] = 0;
	q.push(1);
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				cnt[v] = cnt[u];
				q.push(v); 
			}
			else if (d[v] == d[u] + 1) cnt[v] += cnt[u];
		}
	}
}

int main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	cnt[1] = 1;
	bfs();
	bool th = false;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] >= 2) {
			cout << i << " " ;
			th = true;
		}
	}
	if (!th) cout << "UNSAFE" << '\n';
}