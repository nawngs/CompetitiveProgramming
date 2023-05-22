#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, cnt[26][2];

string s;

void sol() {
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) {
		cin >> s;
		cnt[s[0] - 'a'][0] ++; cnt[s.back() - 'a'][1] ++;
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < 26; i++) {
		if (abs(cnt[i][0] - cnt[i][1]) > 1) {
			cout << "NO" << '\n';
			return ;
		}
		if (cnt[i][0] - cnt[i][1] == 1) cnt1 ++;
		if (cnt[i][1] - cnt[i][0] == 1) cnt2 ++;
	}
	//cout << cnt1 << " " << cnt2 << '\n';
	if ((cnt1 == 1 && cnt2 == 1) || (cnt1 == 0 && cnt2 == 0)) {
		cout << "YES" << '\n';
	}
	else cout << "NO" << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}