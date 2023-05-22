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

const string NAME = "MaxMedian";
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

int n, a[200005], k, cnt[200005], min_cnt[200005];

bool check(int x) {
	cnt[0] = 0;
	for (int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + (a[i] >= x ? 1 : -1);
	min_cnt[0] = 0;
	for (int i = 1; i <= n; i++) min_cnt[i] = min(min_cnt[i - 1], cnt[i]);
	for (int i = k; i <= n; i++) if (cnt[i] - min_cnt[i - k] > 0) return true;
	return false;
}

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = 1e6, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
} 

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
