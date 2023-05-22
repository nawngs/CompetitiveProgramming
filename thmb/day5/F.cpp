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

string p, t;

int z[2 * nmax + 5], pre[130], pre_s[2 * nmax + 5];

int main() {
	fast;
	cin >> p >> t;
	string s = ' ' + t + ' ' + p;
	memset(pre, 255, sizeof(pre));
	memset(pre_s, 255, sizeof(pre_s));
	int l = 1, r = 1;
	vector < int > res;
	for (int i = 1; i < s.size(); i++) {
		pre_s[i] = pre[s[i]];
		pre[s[i]] = i;
	}
	for (int i = 2; i < s.size(); i++) {
		int &x = z[i];
		if (i <= r) x = min(r - i + 1, z[i - l + 1]);
		else l = i;
		while (i + x < s.size()) {
			int tam = (pre_s[i + x] < i ? -1 : pre_s[i + x]);
			int tam2 = pre_s[x + 1];
			if (tam == -1 && tam2 != -1) break;
			if (tam != -1 && tam2 == -1) break;
			if ((tam == tam2 && tam == -1) || i + x - tam == x + 1 - tam2) {
				x ++;
				l = i;
				r = i + x - 1;
			}
			else break;
		}
		if (z[i] >= t.size() && i > t.size() + 1) res.push_back(i - t.size() - 1);
	}
	cout << res.size() << '\n';
	for (auto x : res) cout << x << " ";
}
