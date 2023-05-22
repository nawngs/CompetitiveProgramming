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

// 1 east
// 2 west
// 3 north
// 4 south

void change(int &x) {
	if (x == 1) x = 4;
	else if (x == 2)  x = 3;
		else if (x == 3) x = 1;
			else if (x == 4) x = 2;
}

void sol() {
	cin >> n >> s;
	int face = 1;
	int x = 0;
	int y = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'S') {
			if (face == 1) x ++;
			if (face == 2) x --;
			if (face == 3) y ++;
			if (face == 4) y --;
		}
		else change(face);
	}
	cout << x << " " << y << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
