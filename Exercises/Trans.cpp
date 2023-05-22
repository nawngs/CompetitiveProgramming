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

const string NAME = "trans";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int a, b, d;

int calc(int x) {
	if (x == 1) return 0;
	if (x <= d) return 1;
	int tam = -INF;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			if (i <= d) tam = max(tam, i);
			if (x / i <= d)tam = max(tam, x / i);
		}
	}
	if (tam == -INF) return tam;
	else return calc(x / tam) + 1;
}

void sol() {
	cin >> a >> b >> d;
	int tam = __gcd(a, b);
	cout << max(-1, calc(a / tam) + calc(b / tam));
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
