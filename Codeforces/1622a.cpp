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

ll a, b, c;

vector < ll > p;

void sol() {
	cin >> a >> b >> c;
	p.clear();
	p.push_back(a);
	p.push_back(b);
	p.push_back(c);
	sort(p.begin(), p.end());
	if (p[2] == p[1] + p[0]) {
		cout << "YES" << '\n';
		return ;
	}
	for (int i = 1; i <= 2; i++) {
		if (p[i] == p[i - 1] && p[(i + 1) % 3] % 2 == 0) {
			cout << "YES" << '\n';
			return ;
		}
	}
	cout << "NO" << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
