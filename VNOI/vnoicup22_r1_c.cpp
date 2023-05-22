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

vector < int > res;

vector < string > suff[1000001];

vector < string > s;

map < string, int > f;

int solve(int index) {								
	if (res[index] != -1) return res[index];
	res[index] = 1e9 + 7;
	suff[index].resize(s[index].size() + 1);
	suff[index][s[index].size()] = "";
	for (int i = s[index].size() - 1; i >= 0; i--) suff[index][i] = s[index][i] + suff[index][i + 1];
		string prev = "";
	for (int i = 0; i < s[index].size(); i++) {
		prev += s[index][i];
		string tam = prev + s[index][i] + suff[index][i + 1];
		//cout << s[index] << " " << prev << " " << s[index][i] << " " << suff[index][i + 1] << '\n';
		int postam = f[tam];
		if (postam != 0) {
			solve(postam);
			res[index] = min(res[index], res[postam] + 1);
		}
		else {
			res[index] = 1;
			break;
		}
	}
	return res[index];
}

int main() {
	fast;
	//fre();
	cin >> n;
	res.resize(n + 2, -1);
	s.resize(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		f[s[i]] = i;
	}
	for (int i = 1; i <= n; i++) cout << solve(i) << '\n';
	
}
