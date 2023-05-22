#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(F) F.begin(), F.end()

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

int n;

pii a[1000003];

int main() {
	fast;
	cin >> n;
	vector < int > val;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		val.push_back(a[i].fi);
		val.push_back(a[i].se);
	}
	sort(all(val));
	val.erase(unique(all(val)), val.end());
	for (int i = 1; i <= n; i++) {
		a[i].fi = upper_bound(all(val), a[i].fi) - val.begin();
		a[i].se = upper_bound(all(val), a[i].se) - val.begin();
	}
	sort(a + 1, a + n + 1);
	
}
