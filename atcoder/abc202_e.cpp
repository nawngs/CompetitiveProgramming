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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, h[200003], timeDFS, num[200003], tail[200003];

vector < int > adj[200003], d[200003];

void dfs(int u) {
	num[u] = ++timeDFS;
	d[h[u]].push_back(num[u]);
	for (auto v : adj[u]) {
		if (h[v] != -1) continue;
		h[v] = h[u] + 1;
		dfs(v);
	}
	tail[u] = timeDFS;
	//cout << u << " " << num[u] << " " << tail[u] << " " << h[u] << '\n';
}

ll bs(ll val, ll height) {
	int l = 0, r = d[height].size() - 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (d[height][mid] <= val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

void sol() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}
	memset(h, 255, sizeof(h));
	h[1] = 0;
	dfs(1);
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << bs(tail[x], y) - bs(num[x] - 1, y) << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
