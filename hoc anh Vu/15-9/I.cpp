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

int n, m, d[5003], len[5003];

vector < pii > adj[5003];

bool inque[5003];

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		adj[i - 1].push_back({i, 1});
		adj[i].push_back({i - 1, 0});
	}
	for (int i = 1; i <= m; i++) {
		int l, r, k, v;
		cin >> l >> r >> k >> v;
		r ++;
		if (v) adj[l].push_back({r, k - 1});
		else adj[r].push_back({l, -k});
	}
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
		len[i] = 0;
	}
	queue < int > que;
	que.push(0);
	inque[0] = 1;
	while (que.size()) {
		int u = que.front();
		que.pop();
		inque[u] = false;
		for (auto v : adj[u]) {
			if (d[v.fi] > d[u] + v.se) {
				d[v.fi] = d[u] + v.se;
				if (inque[v.fi] == false) {
					que.push(v.fi);
					inque[v.fi] = 1;
					len[v.fi] ++;
					if (len[v.fi] > n) {
						cout << -1 << '\n';
						return 0;
					}
				}
			} 
		}
	}
	for (int i = 1; i <= n; i++) cout << 1 - d[i] + d[i - 1] << ' ';
}
