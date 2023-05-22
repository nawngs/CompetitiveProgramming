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

const string NAME = "floor";
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

int n, u, v, a[2003][2003], dem = 1;

bool check(int xa, int ya, int xb, int yb, int u, int v) {
	return (xa <= u && u <= xb && ya <= v && v <= yb);
}

void color_square(int xa, int ya, int xb, int yb, int u, int v) {
	for (int i = xa; i <= xb; i++) {
			for (int j = ya; j <= yb; j++) {
				if (i == u && j == v) continue;
				a[i][j] = dem;
			}
		}
		dem ++;
}

void solve(int xa, int ya, int xb, int yb, int u, int v) {
	//cout << xa << " " << ya << " " << xb << " " << yb << " " << u << " " << v << '\n';
	if (xb - xa == yb - ya && xb - xa == 1) {
		color_square(xa, ya, xb, yb, u, v);
		return ;
	}
	int xmida = (xb + xa) / 2;
	int ymida = (yb + ya) / 2;
	/*
	4hv:
	xa ya 		 		xmida ymida
	xa ymida + 1 		xmida yb
	xmida + 1 ya 		xb ymida
	xmida + 1 ymida + 1 xb yb
	*/
	if (check(xa, ya, xmida, ymida, u, v)) {
		color_square(xmida, ymida, xmida + 1, ymida + 1, xmida, ymida);
		solve(xa, ya, xmida, ymida, u, v);
		solve(xa, ymida + 1, xmida, yb, xmida, ymida + 1);
		solve(xmida + 1, ya, xb, ymida, xmida + 1, ymida);
		solve(xmida + 1, ymida + 1, xb, yb, xmida + 1, ymida + 1);
		return ;
	} 
	if (check(xa, ymida + 1, xmida, yb, u, v)) {
		color_square(xmida, ymida, xmida + 1, ymida + 1, xmida, ymida + 1);
		solve(xa, ya, xmida, ymida, xmida, ymida);
		solve(xa, ymida + 1, xmida, yb, u, v);
		solve(xmida + 1, ya, xb, ymida, xmida + 1, ymida);
		solve(xmida + 1, ymida + 1, xb, yb, xmida + 1, ymida + 1);
		return ;
	}
	if (check(xmida + 1, ya, xb, ymida, u, v)) {
		color_square(xmida, ymida, xmida + 1, ymida + 1, xmida + 1, ymida);
		solve(xa, ya, xmida, ymida, xmida, ymida);
		solve(xa, ymida + 1, xmida, yb, xmida, ymida + 1);
		solve(xmida + 1, ya, xb, ymida, u, v);
		solve(xmida + 1, ymida + 1, xb, yb, xmida + 1, ymida + 1);
		return ;
	}
	if (check(xmida + 1, ymida + 1, xb, yb, u, v)) {
		color_square(xmida, ymida, xmida + 1, ymida + 1, xmida + 1, ymida + 1);
		solve(xa, ya, xmida, ymida, xmida, ymida);
		solve(xa, ymida + 1, xmida, yb, xmida, ymida + 1);
		solve(xmida + 1, ya, xb, ymida, xmida + 1, ymida);
		solve(xmida + 1, ymida + 1, xb, yb, u, v);
		return ;
	}
}

void sol() {
	cin >> n;
	n = (1 << n);
	cin >> u >> v;
	solve(1, 1, n, n, u, v);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
		cout << '\n';
	}	
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
