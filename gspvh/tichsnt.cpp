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

const string NAME = "tichsnt";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str() , "w", stdout);
}

bool f[nmax + 3];

vector < int > prime;

ll n, k;

void sieve() {
	memset(f, 1, sizeof(f));
	f[0] = f[1] = false;
	for (int i = 2; i * i <= nmax; i++)
		if (f[i])
			for (int j = i * i; j <= nmax; j+=i) f[j] = false;
	for (int i = 2; i <= nmax; i++)
		if (f[i]) prime.push_back(i);
}

void sol() {
	cin >> n >> k;
	if (k > 15 || n == 1) {
		cout << "No" << '\n';
		return ;
	}
	if (k == 1) {
		for (auto x : prime) 
			if (n == x) {
				cout << "Yes" << '\n';
				return ;
			}
		for (auto x : prime) 
			if (n % x == 0) {
				cout << "No" << '\n';
				return ;
			}
		cout << "Yes" << '\n';
		return ;
	}
	for (int i = k - 1; i < prime.size(); i++) {
		ll temp = 1;
		for (int j = i - k + 1; j <= i; j++) {
			temp *= prime[j];
			if (temp > n) break;
		}
		if (temp == n) {
			cout << "Yes" << '\n';
			return ;
		}
	}
	cout << "No" << '\n';
}

int main() {
	fast;
	fre();
	sieve();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
