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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[13], c[13], b[13];

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[i] = n + 1;
	}
	for (int i = 1; i <= n; i++) 
		for (int j = i + 1; j <= n; j++) {
			if (a[j] > a[i]) {
				c[i] = j;
				break;
			}
		}
	for (int i = 1; i <= n; i++) b[i] = i;
	int dem = 0;
	do {
		bool th = 1;
		for (int i = 1; i <= n; i++) {
			int pos = n + 1;
			for (int j = i + 1; j <= n; j++) {
				if (b[j] > b[i]) {
					pos = j;
					break;
				}
			}
			if (pos != c[i]) {
				th = false;
				break;
			}
		}
		dem += th;
	}
	while (next_permutation(b + 1, b + n + 1));
	cout << dem;
}
