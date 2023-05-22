//#pragma GCC optimize ("O2")
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

int n, nxt[3];

string res = "";

void print(int x) {
	if (x == 0) res += 'A';
	if (x == 1) res += 'B';
	if (x == 2) res += 'C';
	return ;
}

void solve(int n, int a, int c) {
	if (n <= 0) return ;
	if (nxt[a] == c) {
		solve(n - 1, a, 3 - a - nxt[a]);
		print(a);
		solve(n - 1, 3 - a - nxt[a], nxt[a]);
	}
	else {
		solve(n - 1, a, c);
		print(a);
		solve(n - 1, c, a);
		print(nxt[a]);
		solve(n - 1, a, c);
	}
}

int main() {
	fast;
	//fre();
	cin >> n;
	nxt[0] = 1, nxt[1] = 2, nxt[2] = 0;
	solve(n, 0, 2);
	cout << res;
}
