#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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

ll n, pos[1000001], ans = 0, dem = 0, f[1000001];

vector < ll > a;

pii p[1000001];

void roirac() {
	for (int i = 0; i < n; i++) {
		p[i + 1].fi = a[i];
		p[i + 1].se = i;
	}
	sort(p + 1, p + n + 1);
	p[0].fi = -(1e9 + 7);
	for (int i = 1; i <= n; i++) {
		dem += (p[i].fi != p[i - 1].fi);
		f[dem] = a[p[i].se];
		a[p[i].se] = dem;
	}
}

void calc() {
	for (int i = 0; i <= dem + 1; i++) pos[i] = 1e9 + 7;
	for (int i = 0; i < n; i++) pos[a[i]] = min(pos[a[i]], 1ll * i);
	for (int i = dem; i >= 1; i--) pos[i] = min(pos[i + 1], pos[i]);
	for (int i = 0; i < n; i++) if (pos[a[i]] <= i) ans = max(ans, f[a[i]] * (i - pos[a[i]]));
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		a.push_back(x);
	}
	roirac();
	calc();
	reverse(a.begin(), a.end());
	calc();
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}