#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ull unsigned ll
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ull n, dem[NMAX + 3];

bool f[NMAX + 3];

void sang() {
	memset(f, 1, sizeof(f));
	f[1] = f[0] = false;
	for (int i = 2; i * i <= NMAX; i++)
		if (f[i]) for (int j = i * i; j <= NMAX; j+=i) f[j] = false;
	for (int i = 1; i <= NMAX; i++) dem[i] = dem[i - 1] + f[i - 1];
}


void sol() {
	cin >> n;
	ull s = 0;
	for (int i = 1; i <= n; i++) {
		pll tam;
		tam.fi = dem[i * 2] - dem[i + 1];
		tam.se = dem[i + n + 1] - dem[i * 2 + 1];
		s += (tam.fi + tam.se) * (n - 2) - (tam.fi + tam.se) * (tam.fi + tam.se - 1);
	}
	cout << n * (n - 1) * (n - 2) / 6 - s / 2 << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	sang();
	int t; cin >> t; while (t --) sol();
}