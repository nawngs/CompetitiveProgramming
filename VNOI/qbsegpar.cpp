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
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, s[15003], dem = 1, val[15003], it1[90003], it2[90003];

pii dp[15003];

void roi_rac() {
	vector < pii > p;
	for (int i = 1; i <= n; i++) p.push_back({s[i], i});
	sort(p.begin(), p.end());
	for (int i = 0; i < p.size(); i++) {
		dem += (i > 0 && p[i].fi != p[i - 1].fi);
		val[dem] = s[p[i].se];
		s[p[i].se] = dem;
	}
}

int bs(int gt) {
	int l = 1, r = dem, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (val[mid] >= gt) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void update1(int node, int l, int r, int pos, int gt) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it1[node] = min(it1[node], gt);
		return ;
	}
	update1(node * 2, l, (l + r) / 2, pos, gt);
	update1(node * 2 + 1, (l + r) / 2 + 1, r, pos, gt);
	it1[node] = min(it1[node * 2], it1[node * 2 + 1]);
}

void update2(int node, int l, int r, int pos, int gt) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it2[node] = max(it2[node], gt);
		return ;
	}
	update2(node * 2, l, (l + r) / 2, pos, gt);
	update2(node * 2 + 1, (l + r) / 2 + 1, r, pos, gt);
	it2[node] = max(it2[node * 2], it2[node * 2 + 1]);
}

int query1(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it1[node];
	int mid = (l + r) / 2;
	return min(query1(node * 2, l, mid, u, v), query1(node * 2 + 1, mid + 1, r, u, v));
}

int query2(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return -INF;
	if (u <= l && r <= v) return it2[node];
	int mid = (l + r) / 2;
	return max(query2(node * 2, l, mid, u, v), query2(node * 2 + 1, mid + 1, r, u, v));
}

bool check(int x) {
	dp[1] = {0, 0};
	for (int i = 2; i <= n; i++) dp[i] = {INF, -INF};
	for (int i = 1; i <= 6 * dem; i++) {
		it1[i] =  INF;
		it2[i] = -INF;
	}
	update1(1, 1, dem, s[1], dp[1].fi);
	update2(1, 1, dem, s[1], dp[1].se);
	for (int i = 2; i <= n; i++) {
		int tam = bs(val[s[i]] - x);
		if (tam == -1) continue;
		dp[i].fi = min(dp[i].fi, query1(1, 1, dem, tam, dem) + 1);
		dp[i].se = max(dp[i].se, query2(1, 1, dem, tam, dem) + 1);
		update1(1, 1, dem, s[i], dp[i].fi);
		update2(1, 1, dem, s[i], dp[i].se);
		//cout << dp[i].se << '\n';
	}
	return (dp[n].fi <= k && k <= dp[n].se);
}

void sol() {
	cin >> n >> k;
	n ++;
	s[1] = 0;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	roi_rac();
	//check(3);
	int l = -INF, r = INF, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		//cout << mid << '\n';
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}

/*
5 3
-1 -2 10 -2 -5
*/