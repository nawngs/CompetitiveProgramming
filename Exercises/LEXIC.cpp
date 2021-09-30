#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

ll n, k, cnt[65], sum[65];

string s;

void sol1() {
	ll ans = 0;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++) if (s[i] == '1') ans += sum[i];
	cout << ans + 1 << '\n';
}

void sol2() {
	int pre = n;
	int f[65];
	memset(f, 0, sizeof(f));
	while (k > 1) {
		//cout << k << '\n';
		int l = 1, r = pre, mid, ans = -1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (sum[mid] >= k) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		//cout << ans << '\n';
		f[ans] = 1;
		pre = ans;
		k -= sum[ans - 1];
	}
	for (int i = n; i > 0; i --) cout << f[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("lexic.inp", "r", stdin);
	freopen("lexic.out", "w", stdout);
	cin >> n >> s >> k;
	cnt[0] = 1;
	sum[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i >= 2) cnt[i] = sum[i - 2];
		else cnt[i] = 1;
		sum[i] = sum[i - 1] + cnt[i];
		///cout << i << " " << sum[i] << '\n';
	}
	sol1();
	sol2();
}
