#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, a[500005], cnt[500005];

pii p[500005];

void roi_rac() {
	FOR(i, 1, n) {
		p[i].fi = a[i];
		p[i].se = i;
	}
	sort(p + 1, p + n + 1);
	int dem = 0;
	p[0].fi = -1e9 + 7;
	FOR(i, 1, n) {
		dem += (p[i].fi != p[i - 1].fi);
		a[p[i].se] = dem;
	}
}

int main() {
	fastflow;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	roi_rac();
	stack < int > st;
	ll ans = 0;
	FOR(i, 1, n) {
		ll dem = 0;
		while (st.size() && st.top() < a[i]) {
			dem ++;
			cnt[st.top()] --;
			st.pop();
		}
		dem += cnt[a[i]];
		if (st.size() != cnt[a[i]]) dem ++;
		ans += dem;
		st.push(a[i]);
		cnt[a[i]] ++;
	}
	cout << ans;
}