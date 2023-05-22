#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
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

int n, g, m, res1[100003], res2[100003];

bool th1[100003], th2[100003];

pii vs1[100003], vs2[100003];

pair < int, char > a[100003];

int add(int x, int y) {
	int z = x + y;
	z %= n;
	if (z < 0) z += n;
	return z;
}

void sol() {
	cin >> n >> g >> m;
	for (int i = 0; i < n; i++) {
		th1[i] = th2[i] = false;
		vs1[i] = vs2[i] = {-1, -1};
		res1[i] = res2[i] = 0;
	}
	queue < piii > xuoi, nguoc;
	for (int i = 1; i <= g; i++) {
		cin >> a[i].fi >> a[i].se;
		a[i].fi --;
		if (a[i].se == 'C') {
			if (th1[a[i].fi]) continue;
			th1[a[i].fi] = 1;
			xuoi.push({a[i].fi, {add(a[i].fi, m), m}});
		}
		else {
			if (th2[a[i].fi]) continue;
			th2[a[i].fi] = 1;
			nguoc.push({a[i].fi, {add(a[i].fi, -m), m}});
		}
	}
	int cnt = n;
	while (xuoi.size()) {
		auto u = xuoi.front(); xuoi.pop();
		if (vs1[u.se.fi].fi == -1) {
			vs1[u.se.fi] = {u.se.se, u.fi};
			cnt --;
			if (cnt == 0) break;
			if (u.se.se == 0) continue;
			xuoi.push({u.fi, {add(u.se.fi, -1), u.se.se - 1}});
		}
	}
	cnt = n;
	while (nguoc.size()) {
		auto u = nguoc.front(); nguoc.pop();
		if (vs2[u.se.fi].fi == -1) {
			vs2[u.se.fi] = {u.se.se, u.fi};
			cnt --;
			if (cnt == 0) break;
			if (u.se.se == 0) continue;
			nguoc.push({u.fi, {add(u.se.fi, 1), u.se.se - 1}});
		}
	}
	for (int i = 0; i < n; i++) {
		//cout << i << " " << vs1[i].fi << " " << vs1[i].se << " " << vs2[i].fi << " " << vs2[i].se << '\n';
		int mx = max(vs1[i].fi, vs2[i].fi);
		if (mx == -1) continue;
		if (vs1[i].fi == mx) res1[vs1[i].se] ++;
		if (vs2[i].fi == mx) res2[vs2[i].se] ++; 
	}
	for (int i = 1; i <= g; i++) {
		if (a[i].se == 'C') cout << res1[a[i].fi] << ' ';
		else cout << res2[a[i].fi] << " ";
	}
	cout << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
