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

const string NAME = "PTTNT";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 100;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n;

void sol() {
	cin >> n;
	for (int i = 15; i >= 0; i --) {
		for (int j = 20; j >= 0; j--) {
			for (int p = 35; p >= 0; p--) {
				int temp = n - i * 7 - j * 5 - p * 3;
				if (temp < 0 || temp % 2 != 0) continue;
				int tam = i;
				while (tam --) cout << 7 << " ";
				tam = j;
				while (tam --) cout << 5 << " ";
				tam = p;
				while (tam --) cout << 3 << " ";
				tam = temp / 2;
				while (tam --) cout << 2 << " ";
				cout << '\n';
			} 
		}	
	}
}

int main() {
	fast;
	//	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
