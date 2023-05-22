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

int n;

ld a[1000003];

int main() {
	fast;
	cin >> n;
	cout << fixed << setprecision(11);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector < pair < ld, int > > f;
	pair < ld, int > temp;
	for (int i = 1; i <= n; i++) {
		temp = {a[i], 1};
		while (f.size() && f.back().fi > temp.fi) {
			temp.fi = temp.fi * temp.se + f.back().fi * f.back().se;
			temp.se += f.back().se;
			temp.fi /= temp.se;
			f.pop_back();
		}
		f.push_back(temp);
	}
	for (auto x : f) for (int i = 1; i <= x.se; i++) cout << x.fi << '\n';
	
}
