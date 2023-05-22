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

const string NAME = "HaNoiTower";
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

int n;

stack < int > a[4];

void solve(int n, int x, int y, int z) {
	if (n == 1) {
		//cout << x << " " << z << '\n';
		cout << a[x].top() << " " << z << '\n';
		a[z].push(a[x].top());
		a[x].pop();
		return ;
	}
	solve(n - 1, x, z, y);
	solve(1, x, y, z);
	solve(n - 1, y, x, z);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) a[1].push(n - i + 1);
	solve(n, 1, 2, 3);	
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
