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

ll x_all, a, b;

bool th[12];

string s;

//##############################################################################

bool check(ll x) {
	while (x > 0) {
		if (!th[x % 10]) return false;
		x /= 10;
	}
	return true;
}

void ezver() {
	ll val = (a + x_all - 1) / x_all * x_all;
	ll dem = 0;
	while (val <= b) {
		dem += check(val);
		val += x_all;
	}
	cout << dem << '\n';
}

//##############################################################################

vector < ll > digit;

ll f[15][100003][2];

ll mu(ll a, ll b) {
	if (b == 0) return 1 % x_all;
	ll tam = mu(a, b / 2);
	tam = (tam * tam) % x_all;
	if (b % 2 == 1) tam = (tam * a) % x_all;
	return tam;
}

ll dp(ll pos, ll mod_x, ll less) {
	if (pos == digit.size()) return (mod_x == 0);
	if (f[pos][mod_x][less] != -1) return f[pos][mod_x][less];
	f[pos][mod_x][less] = 0;
	for (int i = 0; i <= 9; i++) {
		if (th[i] && (less || i <= digit[pos])) {
			 //cout << pos << " " << i << " " << mod_x << " " << i  << '\n';
			f[pos][mod_x][less] += dp(pos + 1, (mod_x + i * mu(10, digit.size() - pos - 1)) % x_all, (less || i < digit[pos]));
		}
	} 
	return f[pos][mod_x][less];
}	

ll calc(ll x) {
	digit.clear();
	memset(f, 255, sizeof(f));
	while (x > 0) {
		digit.push_back(x % 10);
		x /= 10;
	}
	reverse(digit.begin(), digit.end());
	return dp(0, 0, 0);
}

void hardver() {
	cout << calc(b) - calc(a - 1);
}

void sol() {
	cin >> x_all >> a >> b >> s;
	for (int i = 0; i < s.size(); i++) th[s[i] - '0'] = 1;
	if (x_all >= 1e5) ezver();
	else hardver();
}

int main() {
	//fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
