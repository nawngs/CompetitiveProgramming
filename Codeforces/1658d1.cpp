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
 
 
int l, r, a[131075], dem1[20], dem2[20];
 
bool getbit(int a, int pos){
	return (a & 1 << pos);
}
 
int mu(int a, int b) {
	if (b == 0) return 1;
	int x = mu(a, b / 2);
	x = x * x;
	if (b % 2 == 1) x = x * a;
	return x;
}
 
void sol() {
	cin >> l >> r;
	memset(dem1, 0, sizeof(dem1));
	memset(dem2, 0, sizeof(dem2));
	for (int i = 1; i <= r - l + 1; i++) {
		cin >> a[i];
		for (int j = 0; j <= 18; j++) dem1[j] += getbit(a[i], j);
		for (int j = 0; j <= 18; j++) dem2[j] += getbit(i + l - 1, j);
	}
	int ans = 0;
	for (int i = 0; i <= 18; i++) if (dem1[i] != dem2[i]) ans += mu(2, i);
	
	cout << ans << '\n';
}
 
int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}