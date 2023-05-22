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
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[200003], dem = 0, cnt[200003], val[200003];

pii f[200003];

void roi_rac() {
	dem = 0;
	vector < pii > p;
	for (int i = 1; i <= n; i++) p.push_back({a[i], i});
	sort(p.begin(), p.end());
	for (int i = 0; i < p.size(); i++) {
		dem += (i == 0 || p[i].fi != p[i - 1].fi);
		val[dem] = a[p[i].se];
		a[p[i].se] = dem;
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = {0, 0};
		cnt[i] = 0;
	}
	roi_rac();
	int ans = 1, pos1 = 1, pos2 = 1, res = val[a[1]];
	for (int i = 1; i <= n; i++) {
		cnt[a[i]] ++;
		int cur = 2 * cnt[a[i]] - i;
		//cout << a[i] << " " << cur << " " << f[a[i]].fi << " " << f[a[i]].se << '\n';
		if (ans < cur - f[a[i]].fi) {
			ans = cur - f[a[i]].fi;
			pos1 = f[a[i]].se + 1;
			pos2 = i;
			res = val[a[i]];
		}
		if (f[a[i]].fi > cur - 1) f[a[i]] = {cur - 1, i - 1};
	}
	cout << res << " " << pos1 << " " << pos2 << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
