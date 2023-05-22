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

const string NAME = "pair";
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

int n, d, a[2003], ans = 0;

vector < pii > a2;

map < int, int > dp1, dp2;

void calc0() {
	for (int i = 0; i < a2.size(); i++) {
		dp1[a2[i].fi + a2[i].fi] += a2[i].se / 2;
		for (int j = i + 1; j < a2.size(); j++) {
			dp1[a2[j].fi + a2[i].fi] += min(a2[i].se, a2[j].se);
		}
	}
	for (auto x : dp1) ans = max(ans, x.se);
}

void calc1() {
	for (int i = 0; i < a2.size(); i++) {
		if (i < a2.size() - 1 && a2[i + 1].fi == a2[i].fi + 1) {
			int num = min(a2[i + 1].se, a2[i].se);
			dp2[a2[i].fi + a2[i].fi] += num + (a2[i].se - num) / 2;
			if (a2[i].fi + a2[i].fi == 6) cout << a2[i].fi << " " << a2[i].fi << " " << num + (a2[i].se - num) / 2 << '\n';

		}
		else {
			dp2[a2[i].fi + a2[i].fi] += a2[i].se / 2;
			if (a2[i].fi + a2[i].fi == 6) cout << a2[i].fi << " " << a2[i].fi << " " << (a2[i].se) / 2 << '\n';

		}
		for (int j = i + 1; j < a2.size(); j++) {
			if (a2[j - 1].fi != a2[j].fi - 1) {
				dp2[a2[i].fi + a2[j].fi - 1] += min(a2[i].se, a2[j].se);
				if (a2[i].fi + a2[j].fi - 1 == 6) cout << a2[i].fi << " " << a2[j].fi << " " << min(a2[i].se, a2[j].se) << '\n';

			}
			if (j < a2.size() - 1 && a2[j + 1].fi == a2[j].fi + 1) {
				dp2[a2[i].fi + a2[j].fi] += min(a2[i].se, a2[j].se + a2[j + 1].se);
				if (a2[i].fi + a2[j].fi == 6) cout << a2[i].fi << " " << a2[j].fi << " " << min(a2[i].se, a2[j].se + a2[j + 1].se) << '\n';
			}
			else {
				dp2[a2[j].fi + a2[i].fi] += min(a2[i].se, a2[j].se);
				if (a2[i].fi + a2[j].fi == 6) cout << a2[i].fi << " " << a2[j].fi << " " << min(a2[i].se, a2[j].se) << '\n';
			}
		}
	}
	for (auto x : dp2) cout << x.fi << " " << x.se << '\n';
	for (auto x : dp2) ans = max(ans, x.se);
}

int main() {
	fast;
	//fre();
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int dem = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) dem ++;
		else {
			a2.push_back({a[i - 1], dem});
			dem = 1;
		}
	}
	a2.push_back({a[n], dem});
	calc0();
	if (d == 1) calc1();
	cout << ans;
}
