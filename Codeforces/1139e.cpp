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

int n, m, Q[5003], visited[5003], assigned[5003], temp = 0, d;

pii a[5003];

vector < int > adj[5003];

bool IsQuery[5003];

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
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].fi;
	for (int i = 1; i <= n; i++)
		cin >> a[i].se;
	cin >> d;
	for (int i = 1; i <= d; i++) {
		cin >> Q[i];
		IsQuery[Q[i]] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!IsQuery[i]) adj[a[i].fi].push_back(a[i].se);
	}
	memset(assigned, 255, sizeof(assigned));
	int cur = 0;
	vector < int > res;
	while (cur <= n) {
		temp ++;
		if (!try_kuhn(cur)) break;
		cur ++;
	}
	res.pb(cur);
	for (int i = d; i > 1; i--) {
		//cout << a[Q[i]].fi << " " << a[Q[i]].se << '\n';
		adj[a[Q[i]].fi].push_back(a[Q[i]].se);
		while (cur <= n) {
			temp ++;
			if (!try_kuhn(cur)) break;
			cur ++;
		}
		res.pb(cur);
	}
	reverse(res.begin(), res.end());
	for (auto x : res) cout << x << '\n';
}