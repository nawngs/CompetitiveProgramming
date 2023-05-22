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

ll m, n, p, s[103], r[103], t[103], assigned[103][103], visited[103], temp;

bool dfs(int u, ll x) {
	if (visited[u] != temp) visited[u] = temp;
	else return false;
	for (int i = 1; i <= m; i++) {
		for (int k = 1; k <= n; k++) {
			if (r[u] + k * t[i] - 1 <= x) {
				if (!assigned[i][k] || dfs(assigned[i][k], x)) {
					assigned[i][k] = u;
					return true;
				}
			}
		}
	}
	return false;
}

bool check(ll x) {
	int cnt = 0;
	temp = 0;
	memset(assigned, 0, sizeof(assigned)); memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		temp++;
		cnt += dfs(i, x);
	}
	return (cnt == n);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> m >> n >> p;
	for (int i = 1; i <= m; i++)
		cin >> s[i];
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	sort(s + 1, s + n + 1, greater < int > ());
	sort(r + 1, r + n + 1);	
	for (int i = 1; i <= m; i++) t[i] = (p + s[i] - 1) / s[i];
	ll l = 1, r = 1e15, mid, ans;
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