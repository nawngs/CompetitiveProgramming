#include <bits/stdc++.h>

#define name "formation"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
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
const int NMAX = 2e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int dx[] {-1, 0, 0, 1};
const int dy[] {0, -1, 1, 0};

int n, m, k, a[NMAX + 3][NMAX + 3], d[NMAX + 3][NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) cin >> a[i][j];
	if (k == 1) {
		priority_queue < piii, vector < piii >, greater < piii > > heap;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 1) {
				d[i][j] = 0;
				heap.push({0, {i, j}});
			}
			else d[i][j] = INF;
		}
		ll res = 0;
		while (heap.size()) {
			auto x = heap.top(); heap.pop();
			int v = x.fi, i = x.se.fi, j = x.se.se;
			if (v != d[i][j]) continue;
			res += 1ll * v;
			for (int p = 0; p < 4; p++) {
				int newi = i + dx[p], newj = j + dy[p];
				if (newi < 1 || newj < 1 || newi > n || newj > m) continue;
				if (d[newi][newj] > v + 1) {
					d[newi][newj] = v + 1;
					heap.push({v + 1, {newi, newj}});
				}
			}
		}
		cout << res << '\n';
		return 0;
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		vector < int > temp;
		for (int p = 1; p <= n; p++) for (int q = 1; q <= m; q++) if (a[p][q]) temp.pb(abs(i - p) + abs(j - q));
		sort(temp.begin(), temp.end());
		for (int i = 0; i < k; i++) res += 1ll * temp[i];
	}
	cout << res;
}