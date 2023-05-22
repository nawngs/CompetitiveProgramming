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

ll A, B;

vector < int > res;

int main() {
	fast;
	cin >> A >> B;
	while (A != B) {
		if (A % 2 == 0 && B % 2 == 0) {
			A /= 2;
			B /= 2;
			continue;
		}
		if (A % 2 == 1 && B % 2 == 0) {
			res.push_back(1);
			A = (A + A) / 2;
			B /= 2;
			continue;
		}
		if (A % 2 == 0 && B % 2 == 1) {
			res.push_back(2);
			A /= 2;
			B = (B + B) / 2;
			continue;
		}
		if (A % 2 == 1 && B % 2 == 1) {
			if (A < B) {
				res.push_back(4);
				res.push_back(1);
				B = (A + B) / 2;
				A = (A + A) / 2;
			}
			else {
				res.push_back(3);
				res.push_back(2);
				A = (A + B) / 2;
				B = (B + B) / 2;
			}
		}
	}
	cout << res.size() << '\n';
	for (auto x : res) {
		if (x == 1) cout << ("A+=A");
		if (x == 2) cout << ("B+=B");
		if ( x== 3) cout << ("A+=B");
		if (x == 4) cout << ("B+=A");
		cout << '\n';
	}
}
