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

int n, m;

string s;

void sol() {
	cin >> n >> m >> s;
	int d, u, l, r;
	d = u = l = r = 0;
	int x = 0, y = 0;
	int resx = n, resy = m;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'L') y --;
		if (s[i] == 'R') y ++;
		if (s[i] == 'U') x --;
		if (s[i] == 'D') x ++;
		l = max(l, -y);
		r = max(r, y);
		d = max(d, x);
		u = max(u, -x);
		if (1 + u > n - d || 1 + l > m - r) break;
		resx = 1 + u;
		resy = 1 + l;

	}
	cout << resx << " " << resy << '\n';

}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
