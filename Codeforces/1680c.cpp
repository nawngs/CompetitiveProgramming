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

int n, dem0[200003];

vector < int > pos;

bool check(int x) {
	if (dem0[n] <= x) return true;
	for (int i = 0; i < min((int) pos.size(), x + 1); i++) {
		int r = max(i, (int)pos.size() - (x - i + 1));
		//if (x == 3) cout << pos[i] << " " << pos[r] << '\n';
		if (dem0[pos[r]] - dem0[pos[i]] <= x) return true;
	}
	return false;
}

void sol() {
	cin >> s;
	n = s.size();
	s = ' ' + s;
	pos.clear();
	dem0[0] = 0;
	for (int i = 1; i <= n; i++) {
		dem0[i] = dem0[i - 1] + (s[i] == '0');
		if (s[i] == '1') pos.push_back(i);
	}
	if (pos.size() == 0 || dem0[pos.back()] - dem0[pos[0]] == 0) {
		cout << 0 << '\n';
		return ;
	}
	int l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
