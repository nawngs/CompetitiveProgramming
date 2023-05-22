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

int n, m;

pii change[600003];

vector < int > b;

bool check(int x, vector < int > a) {
	for (int i = 1; i <= x; i++) swap(a[change[i].fi], a[change[i].se]);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		while (i != a[i]) {
			swap(a[i], a[a[i]]);
			cnt ++;
		}
	}
	return cnt <= x;
}

int main() {
	fast;
	//fre();
	cin >> n;
	b.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> b[i];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> change[i].fi >> change[i].se;
	int l = 1, r = m, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid, b)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}
