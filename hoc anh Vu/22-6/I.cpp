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

string A, B, res, temp;

int na, nb, mu[12];

vector < string > f;

string create(int len, int num) {
	string ans = "";
	for (int i = 1; i <= len; i++) {
		if (num >= mu[len - i]) {
			ans += '1';
			num -= mu[len - i];
		}
		else ans += '0';
	}
	return ans;
}

int main() {
	//fast;
	cin >> A >> B;
	na = A.size();
	nb = B.size();
	A = ' ' + A;
	B = ' ' + B;
	mu[0] = 1;
	for (int i = 1; i <= 10; i++) mu[i] = mu[i - 1] * 2;
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < (1 << i); j++) {
			string tam = create(i, j);
			bool th = 1;
			for (int l = 0; l <= na - i + 1; l++) {
				string temp = "";
				for (int r = l; r <= l + i - 1; r++) temp += A[r];
				if (temp == tam) {
					th = false;
					break;
				}
			}
			if (!th) continue;
			for (int l = 0; l <= nb - i + 1; l++) {
				string temp = "";
				for (int r = l; r <= l + i - 1; r++) temp += B[r];
				if (temp == tam) {
					th = false;
					break;
				}
			}
			if (th) {
				cout << tam << '\n';
				return 0;
			}
		}
	}
	cout << res;
}
