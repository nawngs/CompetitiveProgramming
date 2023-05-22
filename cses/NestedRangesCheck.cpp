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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n;

bool check1[200003], check2[200003];

pair < int, pii > a[200003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se.fi;
		a[i].se.se = i;
	}
	sort(a + 1, a + n + 1, [](pair < int, pii > &x, pair < int, pii > &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se > y.se);
	});
	int max_r = -INF;
	for (int i = 1; i <= n; i++) {
		if (max_r >= a[i].se.fi) check2[a[i].se.se] = 1;
		max_r = max(max_r, a[i].se.fi);
	}
	int min_r = INF;
	for (int i = n; i >= 1; i--) {
		if (min_r <= a[i].se.fi) check1[a[i].se.se] = 1;
		min_r = min(min_r, a[i].se.fi);
	}
	for (int i = 1; i <= n; i++) cout << check1[i] << " ";
	cout << '\n';
	for (int i = 1; i <= n; i++) cout << check2[i] << " ";
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
