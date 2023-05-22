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

pii dp[2003][2003], jump[2003];

int kmp[2003], nxt[2003][26];

string s, p;

void maximize(pii &x, pii y) {
	if (y.se == (int)p.size() - 1) {
		y.fi ++;
		y.se = 0;
	}
	x = max(x, y);
}

int main() {
	fast;
	//fre();
	cin >> s >> p;
	s = ' ' + s; p = ' ' + p;
	kmp[1] = 0;
   	int k = 0;
   	for (int i = 2; i < p.size() - 1; i++) {
      while (k > 0 && p[k + 1] != p[i])
         k = kmp[k];
      if (p[k + 1] == p[i])
         k = k + 1;
      kmp[i] = k;
   }
   for (int i = 0; i < p.size() - 1; i++) {
      for (int c = 0; c < 26; c++) {
         if (p[i + 1] == c + 'a')
            nxt[i][c] = i + 1;
         else nxt[i][c] = nxt[kmp[i]][c];
      }
   }
  	for (int i = 1; i < s.size(); i++) {
  		int cur = 0, cnt = 0, pos;
  		for (int j = i; j < s.size(); j++) {
  			if (s[j] == p[cur + 1]) {
  				cur ++;
  				if (cur == p.size() - 1) {
  					pos = j;
  					break;
  				}
  			}
  			else cnt ++;
  		}
  		if (cur == p.size() - 1) jump[i] = {pos, cnt};
  		else jump[i] = {-1, -1};
  	}
	for (int i = 0; i < s.size() - 1; i++) {
		for (int j = 0; j <= i; j++) {
			maximize(dp[i + 1][j + 1], dp[i][j]);
			maximize(dp[i + 1][j], {dp[i][j].fi, nxt[dp[i][j].se][s[i + 1] - 'a']});
			if (jump[i + 1].fi != -1 && j + jump[i + 1].se <= s.size() - 1) 
				maximize(dp[jump[i + 1].fi][j + jump[i + 1].se], {dp[i][j].fi + 1, 0});
		}
	}
	for (int i = 0; i < s.size(); i++) cout << dp[s.size() - 1][i].fi << ' ';
}
 