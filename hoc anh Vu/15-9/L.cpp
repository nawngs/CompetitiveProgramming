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

int n, m, len[1000003], res = 0, cnt[1000003];

vector < int > s[1000003], pos[1000003];

void add(int x) {
	if (!cnt[x]) res ++;
	cnt[x] ++;
}

void remove(int x) {
	cnt[x] --;
	if (!cnt[x]) res --;
}

int main() {
	fast;
	cin >> n >> m;
	vector < int > roi_rac;
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		len[i] = k;
		s[i].resize(k + 2);
		s[i][0] = 0;
		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			s[i][j] = s[i][j - 1] + x;
		}
		for (int j = 0; j <= k; j++) {
			roi_rac.push_back(s[i][j] + 1);
			roi_rac.push_back(n - (s[i][k] - s[i][j]) + 1);
		}
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 1; i <= m; i++) {
		int k = len[i];
		for (int j = 0; j <= k; j++) {
			pos[lower_bound(roi_rac.begin(), roi_rac.end(), s[i][j] + 1) - roi_rac.begin()].push_back(i);
			pos[lower_bound(roi_rac.begin(), roi_rac.end(), (n - (s[i][k] - s[i][j]) + 1)) - roi_rac.begin()].push_back(-i);
		}
	}
	int ans = 0;
	for (int i = 0; i < roi_rac.size() - 1; i++) {
		for (auto x : pos[i]) {
			if (x > 0) add(x);
			else remove(-x);
		}
		if (res == m) ans += roi_rac[i + 1] - roi_rac[i];
	}
	cout << n - ans;
}
