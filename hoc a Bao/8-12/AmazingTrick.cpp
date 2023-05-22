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

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int n, pos[100003], a[100003], p[100003];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		pos[x] = i;
	}
	for (int i = 1; i <= n; i++) a[i] = i;
	for (int loveyou = 1; loveyou <= 1000; loveyou++) {
		shuffle(a + 1, a + n + 1, rd);
		bool th = 1;
		for (int i = 1; i <= n; i++) 
			if (a[i] == i || a[i] == pos[i]) th = false;
		if (!th) continue;
		cout << "Possible" << '\n';
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
			p[a[i]] = i;
		}
		cout << '\n';
		for (int i = 1; i <= n; i++) cout << p[pos[i]] << " ";
		cout << '\n';
		return;
	}
	cout << "Impossible" << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) solve();
}
