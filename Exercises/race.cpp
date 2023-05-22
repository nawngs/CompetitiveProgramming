#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "RACE";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n;

pii a[100003], b[100003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i].fi;
		b[i].se = i;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	int l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		if (a[i].fi > b[l].fi) {
			cout << a[i].se << " " << b[l].se << '\n';
			l ++;
		}
		else {
			cout << a[i].se << " " << b[r].se << '\n';
			r --;
		}

	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
