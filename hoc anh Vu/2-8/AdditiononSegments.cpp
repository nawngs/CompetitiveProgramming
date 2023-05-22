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

struct Query {
	int l, r, x;
} a[10003];

int dp[10003], n, m;

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i].l >> a[i].r >> a[i].x;
	sort(a + 1, a + m + 1, [&](Query &x, Query &y) {
		return x.r < y.r;
	});
	for (int i = 1; i <= m; i++) {
		dp[0] = a[i].r;
		for (int j = n; j >= a[i].x; j--) if (dp[j - a[i].x] >= a[i].l) dp[j] = max(dp[j], dp[j - a[i].x]); 
	}
	vector < int > res;
	for (int i = 1; i <= n; i++) if (dp[i]) res.push_back(i);
	cout << res.size() << '\n';
	for (auto x : res) cout << x << " ";
}
