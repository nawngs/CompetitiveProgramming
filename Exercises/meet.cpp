#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n, q, pos[100005];

pair < int, int > a[100005];

int bs1(int val) {
	int l = 1, r = n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid].fi <= val) {
			ans = a[mid].fi;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int bs2(int val) {
	int l = 1, r = n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid].fi >= val) {
			ans = a[mid].fi;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void sol(int l, int r) {
	int tam = (a[l].fi + a[r].fi) / 2;
	int temp1 = bs1(tam);
	int temp2 = bs2(tam);
	int ans1, ans2;
	if (temp1 == -1) ans1 = 1e9 + 7;
	else ans1 = max(abs(temp1 - a[l].fi), abs(temp1 - a[r].fi));
	if (temp2 == -1) ans2 = 1e9 + 7;
	else ans2 = max(abs(temp2 - a[l].fi), abs(temp2 - a[r].fi));
	cout << min(ans1, ans2) << '\n';
	return ;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("meet.inp", "r", stdin);
	freopen("meet.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pos[a[i].se] = i;
	while (q --) {
		int l, r;
		cin >> l >> r;
		if (pos[l] > pos[r]) swap(l, r);
		sol(pos[l], pos[r]);
	}
}
