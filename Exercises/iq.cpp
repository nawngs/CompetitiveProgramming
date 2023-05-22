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

const string NAME = "iq";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, res[100003];

pll len[100003], d[100003];

bool check(int x) {
	for (int i = 1; i <= x; i++) {
		int j = n - x + i;
		if (len[i].fi * 2 > d[j].fi) return false; 
	}
	return true;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> len[i].fi;
		len[i].fi *= len[i].fi;
		len[i].se = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> d[i].fi;
		d[i].fi *= d[i].fi;
		d[i].se = i;
	}
	sort(len + 1, len + n + 1);
	sort(d + 1, d + n + 1);
	int l = 0, r = n, mid, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	//cout << ans << '\n';
	for (int i = 1; i <= ans; i++) res[len[i].se] = d[n - ans + i].se;
	for (int i = ans + 1; i <= n; i++) res[len[i].se] = d[i - ans].se;
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
