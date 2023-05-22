#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "Tasks";
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

ll n, m, a[100005], it[800005];

vector < ll > tam;

void update(ll node, ll l, ll r, ll pos, ll val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void solve1() {
	for (int i = 2; i <= n; i++) update(1, 1, n, i, a[i] - a[i - 1]);
	ll ans = INF;
	for (int i = 1; i <= n - m + 1; i++) ans = min(ans, query(1, 1, n, i + 1, i + m - 1));
	cout << ans;
}

bool check(ll val) {
	ll dem = 0;
	for (auto x : tam) {
		if (x < val) continue;
		if (val == 0) {
			if (x != val) return false;
		}
		else {
			dem += x / val - (x % val == 0);
			//if (val == 12) cout << x / val - (x % val == 0) << '\n';
		}
	}
	return (dem <= m - n);
}

void solve2() {
	for (int i = 2; i <= n; i++) tam.push_back(a[i] - a[i - 1]);
	ll l = 0, r = 1e9, mid, ans = -1;
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

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (m <= n) solve1();
	else solve2();
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
