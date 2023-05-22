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

string s;

ll cntupper[1000003], cntlower[1000003], cntnum[1000003];

int bs(int pos) {
	int l = 0, r = pos - 6, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (cntupper[pos] - cntupper[mid] && cntnum[pos] - cntnum[mid] && cntlower[pos] - cntlower[mid]) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

void sol() {
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		cntupper[i] = cntupper[i - 1];
		cntlower[i] = cntlower[i - 1];
		cntnum[i] = cntnum[i - 1];
		if ('a' <= s[i] && s[i] <= 'z') cntlower[i] ++;
		if ('A' <= s[i] && s[i] <= 'Z') cntupper[i] ++;
		if ('0' <= s[i] && s[i] <= '9') cntnum[i] ++;
	}
	ll ans = 0;
	for (int i = 6; i <= n; i++) ans += bs(i) + 1;
	cout << ans;
	
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
