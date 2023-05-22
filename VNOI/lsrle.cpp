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

const string NAME = "lsrle";
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

string s;

vector < int > digit;

string change_to_str(string x) {
	string res = "";
	for (int i = 0; i < x.size(); i++) {
		if ('a' <= x[i] && x[i] <= 'z') {
			int j = i + 1;
			int tam = 0;
			while ('0' <= x[j] && x[j] <= '9') {
				tam = tam * 10 + (x[j] - '0');
				j++;
			}
			//cout << (char) x[i] << " " <<  tam << '\n';
			while (tam --) res += x[i];
		}
	}
	return res;
}

string change(string x) {
	int dem = 1;
	string res = "";
	for (int i = 1; i < x.size(); i++) {
		if (x[i] == x[i - 1]) dem ++;
		else {
			res += x[i - 1];
			digit.clear();
			while (dem > 0) {
				digit.push_back(dem % 10);
				dem /= 10;
			}
			reverse(digit.begin(), digit.end());
			for (auto x : digit) {
				char c = x + '0';
				res += c;
			}
			dem = 1;
		}
	}
	res += x[x.size() - 1];
	digit.clear();
	while (dem > 0) {
		digit.push_back(dem % 10);
		dem /= 10;
	}
	reverse(digit.begin(), digit.end());
	for (auto x : digit) {
		char c = x + '0';
		res += c;
	}
	return res;
}

void solve1() {
	string s1, s2;
	cin >> s1 >> s2;
	s1 = change_to_str(s1);
	s2 = change_to_str(s2);
	string res = s1 + s2;
	cout << "@1: " << change(res) << '\n';
}

void solve2() {
	string s1;
	int a, b;
	cin >> s1 >> a >> b;
	string res = "";
	s1 = change_to_str(s1);
	for (int i = 0; i < a - 1; i++) res += s1[i];
	for (int i = a + b - 1; i < s1.size(); i++) res += s1[i];
	//cout << res << '\n';  
	cout << "@2: " << change(res) << '\n';
}

void solve3() {
	string s1;
	int a, b;
	cin >> s1 >> a >> b;
	string res = "";
	s1 = change_to_str(s1);
	for (int i = 1; i <= b; i++) res += s1[a - 2 + i];
	cout << "@3: " << change(res) << '\n';
}

void solve4() {
	string s1, s2;
	int a;
	cin >> s1 >> s2 >> a;
	string res = "";
	s1 = change_to_str(s1);
	s2 = change_to_str(s2);
	for (int i = 1; i <= a; i++) res += s1[i - 1];
	res += s2;
	for (int i = a; i <= s1.size(); i++) res += s1[i - 1];
	cout << "@4: " << change(res) << '\n';
}


int main() {
	fast;
	//fre();
	while (cin >> s) {
		if (s[s.size() - 1] == '1') solve1();
		if (s[s.size() - 1] == '2') solve2();
		if (s[s.size() - 1] == '3') solve3();
		if (s[s.size() - 1] == '4') solve4();
	}
}
