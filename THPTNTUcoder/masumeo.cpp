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

ll n;

bool check[nmax + 5];

vector < int > prime;

void sang() {
	for (int i = 1; i <= nmax; i++) check[i] = true;
	check[1] = check[0] = false;
	for (int i = 2; i * i <= nmax; i++)
		if (check[i]) for (int j = i * i; j <= nmax; j+=i) check[j] = false;
	for (int i = 1; i <= nmax; i++) if (check[i]) prime.push_back(i);
}

void sol() {
	cin >> n;
	int chan = 0, le = 0;
	for (auto i : prime) {
		int dem = 0;
		while (n % i == 0) {
			dem ++;
			n /= i;
		}
		if (dem == 0) continue;
		if (dem % 2 == 0) chan += dem;
		else le += dem;
	}
	if (n != 1) le ++;
	cout << chan << '\n' << le << '\n';
}

int main() {
	fast;
	sang();
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
