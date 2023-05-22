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

int n, num[103];

pii a[103];

bool compare(pii x, pii y) {
	return (x.fi < y.fi || x.se < y.se);
}

vector < pii > res;

void sol() {
	cin >> n;
	res.clear();
	for (int i = 1; i <= n; i++) cin >> a[i].fi;
	for (int i = 1; i <= n; i++) cin >> a[i].se;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			if (a[i].fi > a[j].fi && a[i].se < a[j].se) {
				cout << -1 << '\n';
				return ;
			}
	for (int i = 1; i < n; i++) {
		int pos = i;
		for (int j = i + 1; j <= n; j++) if (compare(a[j], a[pos])) pos = j;
		if (pos != i) {
			res.push_back({i, pos});
			swap(a[i], a[pos]);
		}
	}
	if (res.size() <= 1000) {
		cout << res.size() << '\n';
		for (auto x : res) cout << x.fi << " " << x.se << '\n'; 
	}
	else cout << -1 << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
