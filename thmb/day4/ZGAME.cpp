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

int n;

string s;


int main() {
	//fast;
	cin >> n >> s;
	s = ' ' + s;
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			if (i % 2 == 1) a ++;
			else b ++;
		}
	}
	if (a % 2 == 0 && b % 2 == 0) {
		cout << 0 << '\n';
		while (1) {
			int x;
			cin >> x;
			s[abs(x)] = (s[abs(x)] == '1' ? '0' : '1');
			if (x < 0) s[abs(x) - 1] = (s[abs(x) - 1] == '1' ? '0' : '1');
			a = 0, b = 0;
			for (int i = 1; i <= n; i++) {
				if (s[i] == '1') {
					if (i % 2 == 1) a ++;
					else b ++;
				}
			}
			if (a % 2 == 1 && b % 2 == 1) {
				for (int i = n; i >= 1; i--) 
					if (s[i] == '1') {
						s[i] = '0';
						s[i - 1] = (s[i - 1] == '1' ? '0' : '1');
						cout << -i << '\n';
						break;
					}
			}
			else {
				if (a % 2 == 1) {
					for (int i = 1; i <= n; i += 3) 
						if (s[i] == '1') {
							s[i] = '0';
							cout << i << '\n';
							break;
						}
				}
				else {
					for (int i = 2; i <= n; i += 2) {
						if (s[i] == '1') {
							s[i] = '0';
							cout << i << '\n';
							break;
						}
					}
				}
			}
			a = 0, b = 0;
			for (int i = 1; i <= n; i++) {
				if (s[i] == '1') {
					if (i % 2 == 1) a ++;
					else b ++;
				}
			}
			if (a == 0 && b == 0) return 0;
		}
	}
	cout << 1 << '\n';
	while (1) {
		a = 0, b = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') {
				if (i % 2 == 1) a ++;
				else b ++;
			}
		}
		if (a % 2 == 1 && b % 2 == 1) {
			for (int i = n; i >= 1; i--) 
				if (s[i] == '1') {
					s[i] = '0';
					s[i - 1] = (s[i - 1] == '1' ? '0' : '1');
					cout << -i << '\n';
					break;
				}
		}
		else {
			if (a % 2 == 1) {
				for (int i = 1; i <= n; i += 3) 
					if (s[i] == '1') {
						s[i] = '0';
						cout << i << '\n';
						break;
					}
			}
			else {
				for (int i = 2; i <= n; i += 2) {
					if (s[i] == '1') {
						s[i] = '0';
						cout << i << '\n';
						break;
					}
				}
			}
		}
		a = 0, b = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') {
				if (i % 2 == 1) a ++;
				else b ++;
			}
		}
		if (a == 0 && b == 0) return 0;
		int x;
		cin >> x;
		s[abs(x)] = (s[abs(x)] == '1' ? '0' : '1');
		if (x < 0) s[abs(x) - 1] = (s[abs(x) - 1] == '1' ? '0' : '1');
	}
}
 