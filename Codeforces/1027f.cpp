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

int n, temp = 0, visited[2 * NMAX + 3], assigned[NMAX + 3];

vector < int > compress, adj[2 * NMAX + 3];

pii a[NMAX + 3];

bool try_kuhn(int u) {
	if (visited[u] == temp) return false;
	visited[u] = temp;
	for (auto v : adj[u]) {
		if (assigned[v] == -1 || try_kuhn(assigned[v])) {
			assigned[v] = u;
			return true;
		}	
	}
	return false;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		compress.push_back(a[i].fi); compress.push_back(a[i].se);
	}
	sort(compress.begin(), compress.end());
	compress.erase(unique(compress.begin(), compress.end()), compress.end());
	for (int i = 1; i <= n; i++) {
		a[i].fi = lower_bound(compress.begin(), compress.end(), a[i].fi) - compress.begin();
		a[i].se = lower_bound(compress.begin(), compress.end(), a[i].se) - compress.begin();
		adj[a[i].fi].push_back(i); adj[a[i].se].push_back(i);
	}
	int res = 0;
	memset(assigned, 255, sizeof(assigned));
	for (int i = 0; i < sz(compress); i++) {
		temp ++;
		res += try_kuhn(i);
		if (res == n) {
			cout << compress[i] << '\n';
			return 0;
		}
	}
	cout << -1;
}