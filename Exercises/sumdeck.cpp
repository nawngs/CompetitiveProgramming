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

const string NAME = "sumdeck";
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

ll n, a[200005], k, sum;

void sol() {
	cin >> n >> k;
	sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum <= k) {
		cout << 0 << '\n';
		return ;
	}
	sort(a + 1, a + n + 1);
	ll ans = sum - k;
	for (int i = 1; i < n; i++) {
		sum -= a[n - i + 1] - a[1];
		if (sum <= k) {
			ans = min(ans, 1ll * i);
			break;
		}
		else {
			ll temp = sum - k;
			temp = temp / (i + 1) + (temp % (i + 1) != 0);
			ans = min(ans, temp + i);
		}
	}
	cout << ans << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
