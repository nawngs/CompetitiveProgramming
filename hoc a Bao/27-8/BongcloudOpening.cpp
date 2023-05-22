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

int n, k, x, a[2003], b[2003], c[2003], d[2003];

map < pii, int > mp;

int solve(int id, int val) {
	if (id == n + 1) return val;
	if (mp.find({id, val}) != mp.end()) return mp[{id, val}];
	if (val < x - k) {
		int tam = solve(id + 1, val + (c[id] == 0 ? -b[id] : a[id]));
		mp[{id, val}] = tam;
		return tam;
	}
	if (val > x + k) {
		int tam = solve(id + 1, val + (d[id] == 0 ? -b[id] : a[id]));
		mp[{id, val}] = tam;
		return tam;
	}
	int tam = max(solve(id + 1, val + (c[id] == 0 ? -b[id] : a[id])), solve(id + 1, val + (d[id] == 0 ? -b[id] : a[id])));
	mp[{id, val}] = tam;
	return tam;
}

int main() {
	fast;
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	cout << solve(1, x) << '\n';
}
