#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define ull unsigned long long
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "divpow";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ull LIM = 1E19;
const ull INF = 15e18;
const int nmax = cbrtl(LIM);
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ull n;

int f[nmax + 5];

vector < int > prime;

map < ull, int > min_v;
 
void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = i;
	for (int i = 2; i * i <= nmax; i++)
		if (f[i] == i) for (int j = i * 2; j <= nmax; j += i) f[j] = i;
	for (int i = 2; i <= nmax; i++)
		if (f[i] == i) prime.push_back(i);
}

bool check(ull x) {
	for (auto v : prime) {
		if (1ll * v * v > x) break;
		if (x % v == 0) return false;
	}
	return true;
}

void sol() {
	cin >> n;
	if (min_v[n]) {
		cout << min_v[n] << ' ';
		return ;
	}
	ull tam = sqrtl(n);
	if (tam * tam == n && check(tam)) {
		cout << tam << " ";
		return ;
	}
	cout << -1 << " ";
}

int main() {
	fast;
	//fre();
	sang();
	for (int i = nmax; i >= 1; i--) {
		int s = 1, x = i, pre = -1, dem = 0;
		while (x > 1) {
			if (pre == f[x]) dem ++;
			else {
				s *= (dem + 1);
				dem = 1;
			}
			pre = f[x];
			x /= f[x];
		}
		s *= (dem + 1);
		ull val = 1;
		while (s--) {
			if (INF / val < (ull)i) {
				val = INF;
				break;
			}
			val = val * i;
		}
		if (val != INF) min_v[val] = i;
	}
	int t = 1;
	cin >> t;
	while (t --) sol();
}

