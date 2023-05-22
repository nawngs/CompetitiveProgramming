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

const string NAME = "guards";
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

struct guard {
	int l, r, index;
} a[100003];

int n, k, x, y;

vector < int > res;

void sol() {
	cin >> n >> k >> x >> y;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].l >> a[i].r;
		a[i].index = i;
	}
	sort(a + 1, a + n + 1, [](guard &x, guard &y) {
		return (x.l < y.l) || (x.l == y.l && x.r < y.r);
	});
	priority_queue < ll, vector < ll > , greater < ll > > using_guard;
	priority_queue < pll, vector < pll > > unused_guard;
	int j = 1;
	while (j <= n && a[j].l <= x) {
		unused_guard.push({a[j].r, a[j].index});
		j ++;
	}
	while (unused_guard.size() && using_guard.size() < k) {
		if (unused_guard.top().fi >= x) {
			using_guard.push(unused_guard.top().fi);
			res.push_back(unused_guard.top().se);
		}
		unused_guard.pop();
	}
	if (using_guard.size() < k) {
		cout << -1 << '\n';
		return ;
	}
	while (1) {
		if (using_guard.top() >= y) break;
		auto u = using_guard.top();
		using_guard.pop();
		while (j <= n && a[j].l <= u) {
			unused_guard.push({a[j].r, a[j].index});
			j ++;
		}
		if (unused_guard.size() && unused_guard.top().fi >= u) {
			using_guard.push(unused_guard.top().fi);
			res.push_back(unused_guard.top().se);
			unused_guard.pop();
		}
		else {
			cout << -1 << '\n';
			return ;
		}
	}
	cout << res.size() << '\n';
	for (auto ans : res) cout << ans << " ";
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
/*
test
5 2 1 9
1 5
4 9
1 3
1 7
5 9
*/
