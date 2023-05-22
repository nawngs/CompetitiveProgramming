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

ll n, A, O, X;

vector < ll > val;

void sol() {
	cin >> n >> A >> O >> X;
	if ((A & O) != A || (X & O) != X) {
		cout << -1 << '\n';
		return ;
	}
	if (n == 1) {
		if (A == O && O == X) cout << A << '\n';
		else cout << -1 << '\n';
		return ;
	}
	if (((A & X) == A) == (n % 2 == 0)) {
		cout << -1 << '\n';
		return ;
	}
	val.clear();
	for (int i = 1; i <= n; i++) val.push_back(A);
	val[1] = O;
	ll tam = (val[0] ^ val[1]) ^ X;
	if (n >= 3) val[2] = (val[2] | tam);
	for (auto x : val) cout << x << " ";
	cout << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
