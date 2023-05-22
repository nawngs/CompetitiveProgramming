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

int n, a[100003];

void sol() {
	cin >> n;
	int cnt[4];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];	
		cnt[a[i]] ++;
	}
	if (cnt[1] == 0 &&  cnt[3] == 0 && cnt[2] % 2 == 1) {
		cout << 0;
		return ;
	}
	int val = 1;
	int dem = 0;
	if (cnt[2] % 2 == 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1 || a[i] == 3) {
				val = a[i];
				a[i] = 2;
				break;
			}
			dem ++;
		}
	}
	if (dem % 2 == 1) val = (val == 1 ? 3 : 1);
	int cur = (val == 1 ? 3 : 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] == 3 || a[i] == 1) a[i] = 2;
		else {
			a[i] = cur;
			if (cur == 1) cur = 3;
			else cur = 1;
		}
		cout << a[i] << ' ';
	}
	return ;
}	

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
