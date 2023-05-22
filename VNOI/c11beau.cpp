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

ll cnta, cntb, maxa, maxb;

void sol() {
	cin >> cnta >> cntb >> maxa >> maxb;
	if (maxa == 0 || cnta == 0) {
		cout << min(maxb, cntb) << '\n';
		return ;
	}
	if (maxb == 0 || cntb == 0) {
		cout << min(maxa, cnta) << '\n';
		return ;
	}
	ll ans = 0;
	if (cnta < cntb) {
		swap(cnta, cntb);
		swap(maxa, maxb);
	}
	ans += min(maxa, cnta - cntb);
	cnta = max(cntb, cnta - maxa);
	while (cnta > cntb) {
		if (cntb == 0) break;
		cntb --;
		ans ++;
		ans += min(maxa, cnta - cntb);
		cnta = max(cntb, cnta - maxa);
	}
	if (cnta == cntb) ans += 2 * cnta;
	cout << ans << '\n';
	
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
