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

const string NAME = "LightRoad";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, f[30];

string s;

void sol() {
	cin >> n >> s;
	ld ans = 1;
	int pos, len;
	for (int i = 1; i <= 26; i++) {
		int l = 0, r = -1, res = 0, dem = 0, temp;
		memset(f, 255, sizeof(f));
		while (r < n - 1) {
			r ++;
			if (f[(int)s[r] - 'a'] < l) {
				if (dem == i) {
					if (f[(int)s[l] - 'a'] == l) dem --;
					l ++;
					r --;
					continue;
				}
				else dem ++;
			}
			f[(int) s[r] - 'a'] = r;
			if (res < r - l + 1) {
				res = r - l + 1;
				temp = l;
			}
		}
		ld tam = (ld) i / (ld) res;
		if (ans > tam) {
			ans = tam;
			pos = temp;
			len = res;
		}
	}
	cout << pos + 1 << " " << pos + len << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
