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

const string NAME = "";
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

ll n, k, a[100005];

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	deque < pll > be, lon;
	a[n + 1] = 2 * INF + 7;
	ll l = 1, r = 1, ans = 0, pre = 0;
	while (r <= n + 1) {
		if (pre <= r) {
			while (be.size() && be.back().fi >= a[r]) be.pop_back();
			while (lon.size() && lon.back().fi <= a[r]) lon.pop_back();
			be.push_back({a[r], r});
			lon.push_back({a[r], r});
		}
		if (lon.front().fi - be.front().fi <= k) r++;
		else {
			ans += r - l;
			while (be.size() && be.front().se <= l) be.pop_front();
			while (lon.size() && lon.front().se <= l) lon.pop_front();
			l ++;
		}
		pre = r;
	}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
