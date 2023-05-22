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
const ll nmax = 135;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n;

bool check[nmax + 5];

vector < int > prime;

void sang() {
	for (int i = 1; i <= nmax; i++) check[i] = true;
	check[1] = check[0] = false;
	for (int i = 2; i * i <= nmax; i++) 
		if (check[i]) for (int j = i * i; j <= n; j += i) check[j] = false;
	for (int i = 2; i <= nmax; i ++) prime.push_back(i);
}

void sol() {
	cin >> n;
	for (auto x : prime) {
				
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
