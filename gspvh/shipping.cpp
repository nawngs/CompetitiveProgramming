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

const string NAME = "shipping";
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

struct Shop {
	int pos, c, p;
} shops[5003];

int n, m, d[5003][5003], k, fn, t;

ll b;

bool inque[5003];

vector < int > adj[5003];

queue < int > que;

void spfa(int s) {
	for (int i = 1; i <= n; i++) d[s][i] = INF;
	d[s][s] = 0;
	memset(inque, false, sizeof(inque));
	que.push(s);
	inque[s] = 1;
	while (que.size()) {
		int u = que.front();
		que.pop();
		inque[u] = false;
		for (auto v : adj[u]) {
			if (d[s][v] > d[s][u] + 1) {
				d[s][v] = d[s][u] + 1;
				if (!inque[v]) {
					que.push(v);
					inque[v] = 1;
				}
			}
		}
	}
}

bool check(int x) {
	ll cost = 0;
	int dem = 0;
	for (int i = 1; i <= k; i++) {
		if (d[shops[i].pos][fn] <= x) {
			//if (x == 1) cout << t - dem << " " << shops[i].c << " " << shops[i].p << '\n';
			if (t - dem <= shops[i].c) {
				cost += 1ll * (t - dem) * shops[i].p;
				return cost <= b;
			}
			else {
				cost += 1ll * shops[i].c * shops[i].p;
				dem += shops[i].c;
			}
		}
	}
	return false;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> shops[i].pos >> shops[i].c >> shops[i].p;
		spfa(shops[i].pos);
	}
	sort(shops + 1, shops + k + 1, [](Shop &x, Shop &y) {
		return x.p < y.p;
	});
	int q;
	cin >> q;
	while (q--) {
		cin >> fn >> t >> b;
		int l = 0, r = n, mid, ans = -1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << " ";
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
