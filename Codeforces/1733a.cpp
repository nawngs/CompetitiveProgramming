#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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

int n, k, maxa[103];

void sol() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) maxa[i] = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		maxa[i % k] = max(maxa[i % k], x);
	}
	int res = 0;
	for (int i = 0; i < k; i++) res += maxa[i];
	cout << res << '\n';
}

 main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
