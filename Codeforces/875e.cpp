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

int n, s1, s2, a[100003], dp[100003][2];

bool maximize(int &x, int y) {
	if (x == -1 || x < y) {
		x = y;
		return true;
	}
	return false;
}

bool minimize(int &x, int y) {
	if (x == -1 || x > y) {
		x = y;
		return true;
	}
	return false;
}

bool check(int x) {
	memset(dp, 255, sizeof(dp));
	if (abs(s2 - a[1]) <= x) {
		if (s2 - a[1] >= 0) minimize(dp[1][1], s2);
		if (s2 - a[1] <= 0) minimize(dp[1][0], s2);
	}
	if (abs(s1 - a[1]) <= x) {
		if (s1 - a[1] >= 0) minimize(dp[1][1], s1);
		if (s1 - a[1] <= 0) minimize(dp[1][0], s1);
	}
	
}

int main() {
	fast;
	//fre();
	cin >> n >> s1 >> s2;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = s2 - s1, r = 1e9, mid, ans;
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
