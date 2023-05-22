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

const string NAME = "";
const string NAME2 = "TEST";
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

string s;

int z[100005], n, sum[100005];

void sol() {
	cin >> s;
	int n = s.size();
	z[0] = n;
	sum[0] ++;
	int l = -1, r = -1;
	for(int i = 1; i < n; i++){
		if(i > r){
			l = i, r = i - 1;
			while(r < n - 1 && s[r + 1] == s[r - l + 1]) r ++;
			z[i] = r - l + 1;	
		}
		else{
			if(z[i - l] < r - i + 1) z[i] = z[i - l];
			else{
				l = i;
				while(r < n - 1 && s[r + 1] == s[r - l + 1]) r++;
				z[i] = r - l + 1;
			}
		}
		sum[0] ++;
		sum[z[i]] --;
	}
	cout << sum[0] << ' ';
	for (int i = 1; i < n; i++) {
		sum[i] += sum[i - 1];
		cout << sum[i] << " ";
	}	
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
