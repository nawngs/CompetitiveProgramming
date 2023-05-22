#pragma GCC optimize ("O3")
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

const string NAME = "Median";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, r, c, a[1002][1002], f[1000002], it[6000002], dem, ans = 1e6;

vector < pair < int, pii > > p; 

void roi_rac() {
	p.clear();
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) p.push_back({a[i][j], {i, j}});
	sort(p.begin(), p.end());
	dem = 1;
	a[p[0].se.fi][p[0].se.se] = 1;
	for (auto i = 1; i < p.size(); i++) {
		dem += (p[i].fi != p[i - 1].fi);
		f[dem] = a[p[i].se.fi][p[i].se.se];
		a[p[i].se.fi][p[i].se.se] = dem;
	}
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[node] += val;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

int calc() {
	int left = 1, right = ans, mid, res = 1e9;
	while (left <= right) {
		mid = (left + right) / 2;
		int tam = query(1, 1, dem, 1, mid);
		if (tam >= (r * c + 1) / 2) {
			res = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	return res;
}

void sol() {
	cin >> n >> m >> r >> c;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	roi_rac();
	for (int i = 1; i <= r; i++) 
		for (int j = 1; j <= c; j++) update(1, 1, dem, a[i][j], 1);
	ans = calc();
	for (int i = 1; i <= n - r + 1; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m - c + 1; j++) {
				if (i == 1 && j == 1) continue;
				if (j == 1) {
					for (int k = 1; k <= c; k++) {
						update(1, 1, dem, a[i - 1][k], -1); 
						update(1, 1, dem, a[i + r - 1][k], 1);
					}
				}
				if (j != 1) {
					for (int k = i; k <= i + r - 1; k++) {
						update(1, 1, dem, a[k][j - 1], -1);
						update(1, 1, dem, a[k][j + c - 1], 1);
					}
				}
				ans = min(ans, calc()); 
			}
		}
		else {
			for (int j = m - c + 1; j >= 1; j--) {
				if (j == m - c + 1) {
					for (int k = m - c + 1; k <= m; k++) {
						update(1, 1, dem, a[i - 1][k], -1);
						update(1, 1, dem, a[i + r - 1][k], 1);
					}
				}
				if (j != m - c + 1) {
					for (int k = i; k <= i + r - 1; k++) {
						update(1, 1, dem, a[k][j + c], -1);
						update(1, 1, dem, a[k][j], 1);
					}
				}	
				ans = min(ans, calc());
			}

		}
	}
	cout << f[ans];
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
