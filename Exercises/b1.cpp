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
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n;

bool check[nmax + 3];

vector < int > prime;

void sang() {
	for (int i = 1; i <= nmax; i++) check[i] = true;
	check[1] = check[0] = false;
	for (int i = 2; i * i <= nmax; i++) 
		if (check[i]) for (int j = i * i; j <= nmax; j += i) check[j] = false;
	for (int i = 2; i <= nmax; i++) if (check[i]) prime.push_back(i); 
}

void sol() {
	cin >> n;
	sang();
	int dem = 0;
	for (auto x : prime) {
		if (n % x == 0) {
			dem ++;
			while (n % x == 0) n /= x;
		}
	}
	if (n != 1) dem ++;
	cout << dem;
}

int main() {
	//fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
