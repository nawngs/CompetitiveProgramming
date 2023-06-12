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

ll n, p, res[103], s[103], total = 0;

void print(int x) {
	if (x == 0) cout << 'A';
	if (x == 1) cout << 'B';
	if (x == 2) cout << 'C';
	return ;
}

void calc1(int n, int a, int b, int c, ll cur) {
	if (cur <= (1ll << (n - 1)) - 1) {
		calc1(n - 1, a, c, b, cur);
		return ;
	}
	cur -= (1ll << (n - 1)) - 1;
	for (int i = 1; i < n; i++) res[i] = b;
	if (!cur) return ;
	cur --;
	res[n] = c;
	if (!cur) return ;
	calc1(n - 1, b, a, c, cur);
}

void calc2(int n, int a, int b, int c, int last) {
	//cout << n << " " << a << " " << b << " " << c << '\n';
	if (n == 0) return ;
	if (s[last] == a) {
		calc2(n - 1, a, c, b, last - 1);
		return ;
	}
	total += (1ll << (n - 1)) - 1;
	for (int i = 1; i < n; i++) res[i] = b;
	res[n] = c; total ++;
	calc2(n - 1, b, a, c, last - 1);
}

int main() {
	fast;
	//fre();
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		s[i] = c - 'A';
	}
	for (int i = 1; i <= n; i++) res[i] = 0;
	calc1(n, 0, 1, 2, p);
	for (int i = 1; i <= n; i++) print(res[i]);
	cout << '\n';
	for (int i = 1; i <= n; i++) res[i] = 0;
	calc2(n, 0, 1, 2, n);
	cout << total << '\n';
}
