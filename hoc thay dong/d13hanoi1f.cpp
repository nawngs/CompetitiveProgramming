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

int n, g[3][3];

vector < pair < char, char > > res;

void add(int x, int y) {
	pair < char, char > s;
	if (x == 0) s.fi = 'A';
	if (x == 1) s.fi = 'B';
	if (x == 2) s.fi = 'C';
	if (y == 0) s.se = 'A';
	if (y == 1) s.se = 'B';
	if (y == 2) s.se = 'C';
	res.push_back(s);
}

void solve(int n, int a, int b, int c) {
	if (n <= 0) return ;
	if (g[a][c] == 1) {
		solve(n - 1, a, c, b);
		add(a, c);
		solve(n - 1, b, a, c);
	}
	else {
		solve(n - 1, a, b, c);
		add(a, b);
		solve(n - 1, c, b, a);
		add(b, c);
		solve(n - 1, a, b, c);
	}
} 

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) 
			cin >> g[i][j];
	solve(n, 0, 1, 2);
	cout << res.size() << '\n';
	for (auto x : res) cout << x.fi << x.se << '\n';
}
