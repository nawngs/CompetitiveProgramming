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

int n, a[100005], st1[100005][21], st2[100005][21], s[100005];

bool  dp[100005];

int get_min(int l, int r) {
	int k = log2(r - l + 1);
	return min(st1[l][k], st1[r - (1 << k) + 1][k]);
}

int get_max(int l, int r) {
	int k = log2(r - l + 1);
	return max(st2[l][k], st2[r - (1 << k) + 1][k]);
}

bool check(int x) {
	if (abs(a[2] - a[1]) > x) return false;
	memset(dp, false, sizeof(dp));
	memset(s, 0, sizeof(s));
	s[2] = 1;
	s[3] = -1;
	for (int i = 2; i <= n; i++) {
		s[i] += s[i - 1];
		dp[i] = (s[i] > 0);
		if (!dp[i]) continue;
		int l = i - 1, r = n, mid, ans = i - 1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (abs(get_max(i - 1, mid) - a[i - 1] <= x) && abs(a[i - 1] - get_min(i - 1, mid)) <= x) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		} 
		if (ans == n) return true;
		ans++;
		s[i + 1] ++;
		s[ans + 1] --;
	}
	return false;
}

int main() {
	//fast;
	//fre();
	cin >> n;
	n += 2;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st1[i][0] = a[i];
		st2[i][0] = a[i];
	}
	for (int j = 1; (1 << j) <= n; j++) 
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st1[i][j] = min(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
			st2[i][j] = max(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
		}
	int l = 0, r = INF, mid, ans;
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
