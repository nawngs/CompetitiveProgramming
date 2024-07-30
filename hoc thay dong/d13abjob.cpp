#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 1000;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, a[N + 3], b[N + 3], s[N + 3], ass[2 * N + 3], timer = 0;

int vs[2 * N + 3];

vector < int > adj[N + 3];

bool dfs(int u) {
	if (vs[u] == timer) return false;
	vs[u] = timer;
	for (auto v : adj[u]) {
		if (ass[v] == -1 || dfs(ass[v])) {
			ass[v] = u;
			return true;
		}
	}
	return false;
}

bool check(int x) {
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= n; j++) if (b[i] <= a[j] && abs(s[i] - s[j]) <= x) adj[i].pb(n + j);
	memset(ass, 255, sizeof(ass));
	int res = 0;
	for (int i = 1; i <= n; i++) {
		timer ++;
		res += dfs(i);
	}
	return m + res >= n;
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
		cin >> s[i] >> a[i] >> b[i];
	int l = 0, r = INF, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}