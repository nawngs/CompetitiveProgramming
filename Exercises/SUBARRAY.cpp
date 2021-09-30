#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int n, k, a[400005], cnt[400005], ans = 0;

pair < int, int > p[400005];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i].fi = a[i];
		p[i].se = i;
	}
	sort(p + 1, p + n + 1);
	int dem = 0;
	p[0].fi = -1e9;
	for (int i = 1; i <= n; i++) {
		if (p[i].fi != p[i - 1].fi) dem ++;
		a[p[i].se] = dem;
	}
	int r = 0;
	int tam  = 0;
	for (int i = 1; i <= n; i++) {
		while (tam < k && r <= n) {
			r ++;
			cnt[a[r]] ++;
			if (cnt[a[r]] == 2) tam += 2;
			else if (cnt[a[r]] > 2) tam ++;
		}
		if (tam < k) break;
		ans += n - r + 1;
		//cout << i << " " << r << '\n';
		cnt[a[i]] --;
		if (cnt[a[i]] == 1) tam -= 2;
		else if (cnt[a[i]] >= 2) tam --;
	}
	cout << ans;
}