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

const string NAME = "shuffle";
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

int n, k, pos, s[100003], m[100003], t[100003], x;

int undo(int pos, int i) {
	int l = t[i];
	int r = t[i] + m[i] - 1;
	//cout << pos << '\n';
	if (pos < l) return pos;
	if (l <= pos && pos <= r) return s[i] + pos - l;
	int res = pos - r;
	if (res < s[i]) return res;
	res -= s[i] - 1;
	return res + s[i] + m[i] - 1;
}

void sol() {
	cin >> n >> k >> x;
	for (int i = 1; i <= x; i++) cin >> s[i] >> m[i] >> t[i];
	for (int i = 1; i <= k; i++) {
		int pos = i;
		for (int j = x; j >= 1; j--) pos = undo(pos, j);
		cout << pos << " ";
	} 
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
