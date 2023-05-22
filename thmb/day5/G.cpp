#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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

ll n, m, t[100003], s[100003];

pair < char, ll > a[100003];

int find(ll x) {
	int l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (s[mid] >= x) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

main() {
	fast;
	//fre;	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i].se;
	for (int i = 1; i <= n; i++) cin >> a[i].fi;	
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i].se;
	t[1] = a[1].se - 1;
	for (int i = 2; i <= n; i++) {
		int k = t[i - 1];
		while (k >= a[1].se) {
			//cout << k << '\n';
		 	int pos = find(k + 1);
		 	if ((a[pos].fi != a[i].fi) || (a[pos].fi == a[i].fi && a[pos].se < a[i].se)) k = t[find(k)];
		 	else break;
		}
		int tam = find(k + 1);
		if (a[tam].fi == a[i].fi) {
			if (tam == 1) t[i] = min(a[tam].se, a[i].se);
			else if (a[tam].se >= a[i].se) t[i] = k + a[i].se;
		}
	}
	while (m--) {
		ll x;
		cin >> x;
		int i = find(x);
		if (i == 1) {
			cout << x - 1 << ' ';
			continue;
		}
		x -= s[i - 1];
		int k = t[i - 1];
		while (k >= a[1].se) {
		 	int pos = find(k + 1);
		 	if ((a[pos].fi != a[i].fi) || (a[pos].fi == a[i].fi && a[pos].se < x)) k = t[pos];
		 	else break;
		}
		int tam = find(k + 1);
		if (a[tam].fi == a[i].fi) {
			if (tam == 1) cout << min(a[tam].se, 1ll * x) << ' ';
			else if (a[tam].se >= x) cout << k + x << ' ';
			continue;
			
		}
		cout << 0 << ' ';
	}
}