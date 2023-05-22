#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < pii, int >
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

int n, d[12], cnt[12], ans = 0;

bool used[12];

piii a[12];

void back_track(int pos = 1) {
	if (pos == n) {
		memset(cnt, 0, sizeof(cnt));
		int s = 0;
		for (int i = 1; i < n; i++) {
			if (used[i] == 1) {
				cnt[a[i].fi.fi] ++;
				cnt[a[i].fi.se] ++;
				s += a[i].se;
			}
		}
		for (int i = 1; i <= n; i++) if (cnt[i] > d[i]) return ;
		ans = max(ans, s);
		return ;
	}
	for (int i = 0; i < 2; i++) {
		used[pos] = i;
		back_track(pos + 1);
		used[pos] = 0;
	}
}

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> d[i];
	for (int i = 1; i < n; i++) cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
	back_track();
	cout << ans;
}
