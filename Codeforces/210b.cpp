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

ll n, k, a[2003], dp[2003];

bool check(ll x) {
	for (int i = 1; i <= n; i++) dp[i] = i - 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++) 
			if (abs(a[i] - a[j]) <= 1ll * (i - j) * x) dp[i] = min(dp[i], dp[j] + i - j - 1);
	for (int i = 1; i <= n; i++) if (dp[i] + n - i <= k) return 1;
	return 0;		
}

int main() {
	fast;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll l = 0, r = 2e9, mid, ans;
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
