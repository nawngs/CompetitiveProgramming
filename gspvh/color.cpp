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
 
const string NAME = "color";
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
 
map < string, int > f; 
 
string a[7] = {"a", "Yellow", "Green", "Blue", "Violet", "Red", "Orange"};
 
void sol() {
	f["Yellow"] = 1;
	f["Green"] = 2;
	f["Blue"] = 3;
	f["Violet"] = 4;
	f["Red"] = 5;
	f["Orange"] = 6;	
	string s1, s2;
	cin >> s1 >> s2;
	if (f[s1] == f[s2]) {
		cout << "Same" << '\n';
		return ;
	}
	if (abs(f[s1] - f[s2]) == 1 || abs(f[s1] - f[s2]) == 5) {
		cout << "Adjacent" << '\n';
		return ;
	}
	if (abs(f[s1] - f[s2]) == 2 || abs(f[s1] - f[s2]) == 4) {
		if ((f[s1] == 5 && f[s2] == 1) || (f[s2] == 5 && f[s1] == 1)) {
			cout << a[6] << '\n';
			return ;
		}
		if ((f[s1] == 6 && f[s2] == 2) || (f[s2] == 6 && f[s1] == 2)) {
			cout << a[1] << '\n';
			return ;
		}
		cout << a[(f[s1] + f[s2]) / 2] << '\n';
		return ;
	}
	if (abs(f[s1] - f[s2]) == 3) {
		cout << "Complementary" << '\n';
		return ;
	}
	cout << "None" << '\n';
}
 
int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}