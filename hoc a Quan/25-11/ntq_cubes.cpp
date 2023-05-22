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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int cnt[1003];

int main() {
	fast;
	//fre();
	ll s = 0;
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		s += x; cnt[x] ++;
	}
	for (int i = 1; i <= m; i++) {
		ll x; cin >> x;
		if (!cnt[x]) s += x;
		else cnt[x] --;
	}
	cout << s;
}
