#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, k, a[403][403], d[403][403];

char dir[403][403];

pii Direction(char c) {
	if (c == 'U') return {-1, 0};
	if (c == 'R') return {0, 1};
	if (c == 'D') return {1, 0};
	if (c == 'L') return {0, -1};
}

char Next(char c) {
	if (c == 'U') return 'R';
	if (c == 'R') return 'D';
	if (c == 'D') return 'L';
	if (c == 'L') return 'U';
}

bool minimize(ll &x, ll y) {
	if (x > y) {
		x = y;
		return 1;
	}
	return false;
}

bool check(ll x) {
	if (a[1][1] < x) return false;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] = INF;
	d[1][1] = 0;
	priority_queue < piii, vector < piii >, greater < piii > > heap;
	heap.push({0, {1, 1}});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		int v = u.fi, i = u.se.fi, j = u.se.se;
		if (v != d[i][j]) continue;
		char cur = dir[i][j];
		for (int p = 0; p < 4; p++) {
			if (a[i][j] - p < x) break;
			pii temp = Direction(cur);
			int newi = i + temp.fi, newj = j + temp.se;
			if (newi > 0 && newj > 0 && newi <= n && newj <= m) {
				if (minimize(d[newi][newj], v + p)) 
					heap.push({d[newi][newj], {newi, newj}});
			} 
			cur = Next(cur);
		}
	}
	return (d[n][m] <= k);
}

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> dir[i][j];
	ll l = 0, r = INF, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
