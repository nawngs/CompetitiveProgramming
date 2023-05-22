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

int n, a[(1 << 18) + 3];

pii f[(1 << 18)];

void merge(pii &x, pii y) {
	vector < int > temp;
	temp.push_back(x.fi);
	temp.push_back(x.se);
	temp.push_back(y.fi);
	temp.push_back(y.se);
	sort(temp.begin(), temp.end(), [&](int &x, int &y) {
		return a[x] > a[y];
	});
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	x = {temp[0], temp[1]};
}

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		cin >> a[i];
		f[i] = {i, (1 << n)};
	}
	a[(1 << n)] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (1 << n); j++) {
			if ((j >> i) & 1) merge(f[j], f[j ^ (1 << i)]);
		}
	int res = 0;
	for (int i = 1; i < (1 << n); i++) {
		//cout << i << " " << f[i].fi << " " << f[i].se << " " << a[f[i].fi] << " " << a[f[i].se] << '\n';
		res = max(res, a[f[i].fi] + a[f[i].se]);
		cout << res << '\n';
	}
}
