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

string str;

vector < pii > s;

int calc(char c) {
	s[0].fi = 0;
	s[0].se = 0;
	for (int i = 1; i <= n; i++) {
		if (str[i] == c) s[i].fi = s[i - 1].fi + 1;
		else s[i].fi = s[i - 1].fi - 1;
		s[i].se = i;
	}
	sort(s.begin(), s.end(), [] (pii &x, pii &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se > y.se);
	});
	int mina = s[0].se;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i].fi != s[i - 1].fi) ans = max(ans, s[i].se - mina);
		mina = min(mina, s[i].se);
	}
	return ans;
}

void sol() {
	cin >> n >> str;
	str = ' ' + str;
	s.resize(n + 1, {0, 0});
	cout << max(calc('a'), max(calc('b'), calc('c')));
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
