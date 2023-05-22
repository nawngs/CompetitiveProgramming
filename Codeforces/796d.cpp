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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k, d;

pii edges[300003];

vector < int > adj[300003];

bool vs[300003], passed[300003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> d;
	vector < int > a; a.resize(k);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end());
	for (int i = 1; i < n; i++) {
		cin >> edges[i].fi >> edges[i].se;
		adj[edges[i].fi].push_back(i); adj[edges[i].se].push_back(i);
	}
	queue < int > q;
	for (auto x : a) {
		q.push(x);
		vs[x] = 1;
	}
	vector < int > res;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto id : adj[u]) {
			if (passed[id]) continue;
			passed[id] = 1;
			int v = edges[id].fi + edges[id].se - u;
			if (vs[v]) res.push_back(id);
			else {
				vs[v] = 1;
				q.push(v);	
			}
		}
	}
	cout << res.size() << '\n';
	for (auto x : res) cout << x << " ";
}