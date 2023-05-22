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

const string NAME = "xymin";
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

ll n, k, q, b[2003];

pll a[2003];

bool deleted[2003];

bool check(int pos, int val) {
	int l = pos;
	while (l >= 1 && (b[l] >= val || deleted[l])) l--;
	int r = pos;
	while (r <= n && (b[r] >= val || deleted[r])) r ++;
	return (pos - l + r - pos - 1) >= k; 
}

int main() {
	fast;
	//fre();
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		b[i] = a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	ll ans = a[q].fi - a[1].fi;
	for (int i = 2; i <= n - q + 1; i++) {
		memset(deleted, false, sizeof(deleted));
		bool th = 1;
		for (int j = i; j <= i + q - 1; j++) {
			if (!check(a[j].se, a[i].fi)) {
				th = false;
				break;
			}
			deleted[a[j].se] = 1;
		}
		if (th) ans = min(ans, a[i + q - 1].fi - a[i].fi);
	}
	cout << ans;
}
