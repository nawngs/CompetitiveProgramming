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

ll n, k, x[303], y[303];

struct Line {
	ll a, b, c;
};

vector < Line > f;

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	if (k == 1) {
		cout << "Infinity" << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			Line tam;
			tam.a = x[i] - x[j];
			tam.b = y[i] - y[j];
			tam.c = -(x[i] * tam.a + y[i] * tam.b);
			f.push_back(tam);
		}
	}
	sort(f.begin(), f.end(), [](Line &x, Line &y) {
		return (x.a < y.a) || (x.a == y.a && x.b < y.b) || (x.a == y.a && x.b == y.b && x.c < y.c);
	});
	ll dem = 1, res = 0;
	for (int i = 1; i < f.size(); i++) {
		if (f[i].a == f[i - 1].a && f[i].b == f[i - 1].b && f[i].c == f[i - 1].c) dem ++;
		else {
			if (k * (k - 1) / 2 <= dem) cout << f[i - 1].a << " " << f[i - 1].b << " " << f[i - 1].c << '\n';
			dem = 1;
		}
	}
	res += (k * (k - 1) / 2 <= dem);
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
