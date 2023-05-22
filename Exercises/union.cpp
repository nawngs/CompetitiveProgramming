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

const string NAME = "union";
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

int n;

ll res = 0;

vector < ll > Node;

vector < pll > a;

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		while (x >= 1) {
			Node.push_back(x);
			x /= 2;
		}
	}
	sort(Node.begin(), Node.end(), greater < ll > ());
	int dem = 1;
	for (int i = 1; i < Node.size(); i++) {
		if (Node[i] == Node[i - 1]) dem ++;
		else {
			a.push_back({Node[i - 1], dem});
			dem = 1;
		}
	}
	a.push_back({Node.back(), dem});
	for (auto x : a) {
		if (x.se != n) res ++;
	}
	cout << res << '\n';
}