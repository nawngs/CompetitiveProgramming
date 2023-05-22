#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m;

map < int, int > edge[300003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		edge[u][v] = edge[v][u] = 1;
	}
	deque < int > dq[2];
	int role = 0;
	dq[0].pb(1);
	for (int i = 2; i <= n; i++) {
		if (role == 0) {
			if (edge[dq[0].back()][i]) {
				dq[0].pb(i);
				while (!dq[1].empty() && edge[dq[0].back()][dq[1].front()]) {
					dq[0].pb(dq[1].front());
					dq[1].pop_front();
				} 
			}
			else {
				if (sz(dq[0]) > 1) {
					dq[1].push_front(dq[0].back()); dq[0].pop_back(); 
					if (edge[dq[0].back()][i]) dq[0].pb(i);
					else dq[1].push_front(i);
				}
				else {
					role = 1;
					dq[1].pb(i);
					while (sz(dq[1]) > 2) {
						dq[0].pb(dq[1].front());
						dq[1].pop_front();
					}
					if (sz(dq[1]) > 2 && !edge[dq[1].front()][dq[1].back()]) {
						dq[0].pb(dq[1].front());
						dq[1].pop_front();
					}
				}
			}
		}
		else {
			if (edge[dq[1].front()][i]) {
				dq[1].push_front(i);
				while (!dq[0].empty() && edge[dq[0].back()][dq[1].front()]) {
					dq[1].push_front(dq[0].back());
					dq[0].pop_back();
				}
				if (dq[0].empty()) {
					dq[0] = dq[1];
					dq[1].clear();
					role = 0;
				}

			}
			else {
				dq[0].pb(dq[1].front()); dq[1].pop_front();
				if (sz(dq[1]) && !edge[dq[1].front()][i]) dq[0].pb(i);
				else dq[1].push_front(i);
			}
		}
	}
	while (sz(dq[0])) {
		cout << dq[0].front() << " ";
		dq[0].pop_front();
	}
	while (sz(dq[1])) {
		cout << dq[1].front() << " ";
		dq[1].pop_front();
	}
}