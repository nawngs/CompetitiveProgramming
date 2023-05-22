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
const string NAME2 = "TEST";
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

int p1, p2;

string x1, x2;

void sol() {
	cin >> x1 >> p1;
	cin >> x2 >> p2;
	if (x1.size() + p1 > x2.size() + p2) {
		cout << ">" << '\n';
		return ;
	}
	if (x1.size() + p1 < x2.size() + p2) {
		cout << "<" << '\n';
		return ;
	}
	while (x1.size() < x2.size()) {
		x1 += '0';
		p1 --;
	}
	while (x1.size() > x2.size()) {
		x2 += '0';
		p2 --;
	}
	if (x1 == x2) cout << "=" << '\n';
	if (x1 < x2) cout << "<" << '\n' ;
	if (x1 > x2) cout << ">" << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
