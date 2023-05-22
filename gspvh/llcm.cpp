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

const string NAME = "llcm";
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
ll n, a[1000003], cnt[10000004], val1 = -1, val2 = -1, gt[4];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]] ++;
	}	
	ll ans = INF;
	for (int i = 1; i <= 1e7; i++) {
		if (i > ans) break;
		if (cnt[i] >= 2) {
			ans = i;
			val1 = val2 = i;
		}	
		else{
			int num = 0;
			for (int j = i; j <= 1e7; j+=i) {
				if (cnt[j]) gt[num++] = j;
				if (num == 2) break;
			}
			if (num < 2) continue;
			if (gt[0] * gt[1] / i < ans) {
				ans = gt[0] * gt[1] / i;
				val1 = gt[0];
				val2 = gt[1];
			}
		}
	}
	int pos1 = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == val1) {
			pos1 = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == val2 && i != pos1) {
			cout << min(pos1, i) << " " << max(pos1, i);
			return ;
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
