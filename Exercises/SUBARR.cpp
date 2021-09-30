#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int n, k, a[400005], cnt[400005], it[2400005];

long long ans = 0;

pair < int, int > p[400005];

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}
	
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
		//cout << i << " " << tam << '\n';
		while (tam < k && r <= n) {
			r ++;
			cnt[a[r]] ++;
			update(1, 1, n, a[r], cnt[a[r]]);
			tam = max(tam, it[1]);
		}
		if (tam < k) break;
		//cout << r << '\n';
		ans += n - r + 1;
		//cout << i << " " << r << '\n';
		cnt[a[i]] --;
		//cout << a[i] << " " << cnt[a[i]] << '\n';
		update(1, 1, n, a[i], cnt[a[i]]);
		tam = it[1];
		//cout << tam << '\n';
	}
	cout << ans;
}