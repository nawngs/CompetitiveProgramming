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

char c[100003];

int main() {
	fast;
	cin >> n;
	int pos = -1;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 'X' && pos == -1) pos = i;
	}
	if (pos == -1) {
		cout << 0 << '\n';
		return 0;
	}
	int pre = -1;
	vector < int > res;
	for (int i = pos + 1; i <= n; i++) {
		if (c[i] == 'Z') {
			int tam = i - 1;
			while (tam > max(pre, pos)) {
				res.push_back(tam);
				tam --;
			}
			pre = i;
			res.push_back(i);
		}
	}
	cout << res.size() << '\n';
	for (auto x : res) cout << x - 1 << " ";
}
