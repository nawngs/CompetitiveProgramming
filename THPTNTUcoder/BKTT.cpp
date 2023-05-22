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

int n, k, dem[30];

string s;

void sol() {
	cin >> n >> s >> k;
	char maxc = 'a';
	char minc = 'z';
	for (int i = 0; i < n; i++) {
		maxc = max(maxc, s[i]);
		minc = min(minc, s[i]);
		dem[s[i] - 'a'] ++;
	}
	if (k > n) {
		cout << s;
		for (int i = 1; i <= k - n; i++) cout << minc;
		return ; 
	}
	else {
		for (int i = k - 1; i >= 0; i--) {
			if (s[i] != maxc) {
				int tam;
				for (int j = s[i] - 'a' + 1; j <= maxc - 'a'; j++) {
					if (dem[j] != 0) {
						tam = j;
						break;
					}
				}
				for (int j = 0; j < i; j++) cout << s[j];
				char c = tam + 'a';
				cout << c;
				for (int j = i + 1; j < k; j++) cout << minc;
				return ;
			}
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
