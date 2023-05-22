#pragma GCC optimize ("O3")
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
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll a, b, x;

bool check[nmax + 5];

vector < ll > prime;

void sang() {
	for (int i = 1; i <= nmax; i++) check[i] = true;
	check[1] = check[0] = false;
	for (int i = 2; i * i <= nmax; i++)
		if (check[i]) for (int j = i * i; j <= nmax; j+=i) check[j] = false;
	for (int i = 1; i <= nmax; i++) if (check[i]) prime.push_back(i);
}

void ptich(ll res) {
	ll x = res;
	for (auto p : prime) {
		int cnt = 0;
		while (x % p == 0) {
			cnt ++;
			x /= p;
		}
		if (cnt != 0) cout << cnt << " ";
	}
	if (x != 1) cout << 1;
	cout << '\n';
	for (auto p : prime) {
		if (res % p == 0) cout << p << " ";
	}
	if (x != 1) cout << x << '\n';
}

void sol() {
	cin >> a >> b >> x;
	ll dem = 1, tam = a;

	if (b % a != 0) {
		cout << -1 << '\n';
		return ;
	}
	while (tam < b / a) {
		tam *= a;
		dem ++;
	}
	if (tam != b / a) {
		cout << -1 << '\n';
		return ;
	}
	dem ++;
	ptich(dem * x);
}

int main() {
	fast;
	sang();
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
