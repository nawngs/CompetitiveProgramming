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

int l, r, a[131075], dem1[25], dem2[25];

bool getbit(int a, int pos){
	return (a & 1 << pos);
}


void sol() {
	cin >> l >> r;
	memset(dem1, 0, sizeof(dem1));
	memset(dem2, 0, sizeof(dem2));
	for (int i = 1; i <= r - l + 1; i++) {
		cin >> a[i];
		for (int j = 0; j <= 22; j++) dem1[j] += getbit(a[i], j);
		for (int j = 0; j <= 22; j++) dem2[j] += getbit(i + l - 1, j);
	}
	for (int i = 1; i <= r - l + 1; i++) {
		a[i] = (a[i] ^ l);
		bool th = true;
		for (int j = 0; j <= 22; j++) {
			int tam = dem1[j];
			if (getbit(a[i], j)) tam = (r - l + 1) - tam;
			if (tam != dem2[j]) {
				th = false;
				break;
			}
		}
		if (th) {
			cout << a[i] << '\n';
			return ;
		}
	} 
}

int main() {
	//1cout << (6 ^ 1) << '\n';
	//fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
