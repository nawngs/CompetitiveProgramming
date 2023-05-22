#include <bits/stdc++.h>

#define name "linije"
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

int n, timer = 0, assigned[503], visited[503];

pii a[10003];

vector < int > x, y, adj[503];


bool kuhn(int x) {
	if (visited[x] == timer) return false;
	visited[x] = timer;
	for (auto v : adj[x]) {
		if (!assigned[v] || kuhn(assigned[v])) {
			assigned[v] = x;
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
		x.push_back(a[i].fi); y.push_back(a[i].se);
	}
	sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
	sort(y.begin(), y.end()); y.erase(unique(y.begin(), y.end()), y.end());
	if (sz(x) != sz(y)) {
		cout << "Tanya" << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		a[i].fi = lower_bound(x.begin(), x.end(), a[i].fi) - x.begin() + 1;
		a[i].se = lower_bound(y.begin(), y.end(), a[i].se) - y.begin() + 1;
		adj[a[i].fi].push_back(a[i].se);
	}
	int res = 0;
	for (auto v : x) {
		timer ++;
		res += kuhn(v);
	}
	if (res == sz(x)) cout << "Antonina" << '\n';
	else cout << "Tanya" << '\n';
}