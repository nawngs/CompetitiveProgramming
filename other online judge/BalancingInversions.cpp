#include <bits/stdc++.h>

#define int ll
#define name "balance"
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

int n, a[200003], ones = 0, res = INF;

vector < int > pos_left[2], pos_right[2];

// khi swap giua 2 cai bat ki thi diff thay doi toi da la 1
// khi swap 2 cai o giua thi diff thay doi = n - so cai 1

int calc_inver(int l, int r) {
	int cnt = 0, ans = 0;
	for (int i = l; i <= r; i++) {
		if (a[i] == 1) cnt ++;
		else ans += cnt;
	}
	return ans;
}

void solve(int vall, int valr) {
	int diff = calc_inver(1, n) - calc_inver(n + 1, 2 * n);
	res = min(res, abs(diff));
	int cost = 0;
	while (!pos_left[vall].empty() && !pos_right[valr].empty()) {
		cost += n - pos_left[vall].back() + pos_right[valr].back() - n;
		if (vall == 1) 
			diff = diff - (n - pos_left[vall].back()) + (pos_right[valr].back() - n - 1);
		else diff = diff + (n - pos_left[vall].back()) - (pos_right[valr].back() - n - 1);
		pos_left[vall].pop_back(); pos_right[valr].pop_back();
		diff += (n - ones) * (vall == 0 ? 1 : -1);
		res = min(res, cost + abs(diff));
	}
}

signed main() {
	fast;
	if(fopen(name".in", "r")) {
		freopen(name".in", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
		ones += a[i];
	}
	for (int i = 1; i <= n; i++) 
		pos_left[a[i]].push_back(i);
	for (int i = 2 * n; i >= n + 1; i--) 
		pos_right[a[i]].push_back(i);
	solve(1, 0); solve(0, 1);
	cout << res;
}