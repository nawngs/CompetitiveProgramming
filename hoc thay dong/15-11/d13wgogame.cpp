#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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

string s, a[32];

int dp[32][32][32][32][12][4];

int nn, mm, n;

vector < vector < int > > nxt;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
        	if (i == n - 1) aut[i][c] = i;
        	else {
	            if (i > 0 && 'A' + c != s[i])
	                aut[i][c] = aut[pi[i - 1]][c];
	            else
	                aut[i][c] = i + ('A' + c == s[i]);
	        }
        }
    }
}

int Go_Down(int x1, int y1, int x2, int y2, int p, int id);

int Go_Left(int x1, int y1, int x2, int y2, int p, int id);

int Go_Up(int x1, int y1, int x2, int y2, int p, int id);

int Go_Right(int x1, int y1, int x2, int y2, int p, int id) {
	p = nxt[p][a[x1][y1] - 'A'];
	if (x1 > x2 || y1 > y2) 
		return (p + 1 == n);
	if (dp[x1][y1][x2][y2][p][id] != -1) return dp[x1][y1][x2][y2][p][id];
	int &res = dp[x1][y1][x2][y2][p][id];
	res = 0;
	if (x1 == x2) {
		for (int i = y1; i <= y2; i++)
			if (i != y1)
			p = nxt[p][a[x1][i] - 'A'];
		res = (p + 1 == n);
		return res;
	}
	for (int i = y1; i <= y2; i++) {
		if (i != y1)
			p = nxt[p][a[x1][i] - 'A'];
		 res += Go_Down(x1 + 1, i, x2, y1, p, (id + 1) % 4);
	}
	return res;
}

int Go_Down(int x1, int y1, int x2, int y2, int p, int id) {
	p = nxt[p][a[x1][y1] - 'A'];
	if (x1 > x2 || y1 < y2) {
		return (p + 1 == n);
	}
	if (dp[x1][y1][x2][y2][p][id] != -1) return dp[x1][y1][x2][y2][p][id];
	int &res = dp[x1][y1][x2][y2][p][id];
	res = 0;
	if (y1 == y2) {
		for (int i = x1; i <= x2; i++) 
			if (i != x1) p = nxt[p][a[i][y1] - 'A'];
		res = (p + 1 == n);
		return res;
	}
	for (int i = x1; i <= x2; i++) {
		if (i != x1) p = nxt[p][a[i][y1] - 'A'];
		res += Go_Left(i, y1 - 1, x1, y2, p, (id + 1) % 4);
	}
	return res;
}

int Go_Left(int x1, int y1, int x2, int y2, int p, int id) {
	p = nxt[p][a[x1][y1] - 'A'];
	if (y1 < y2 || x1 < x2) {
		return (p + 1 == n);
	}
	if (dp[x1][y1][x2][y2][p][id] != -1) return dp[x1][y1][x2][y2][p][id];
	int &res = dp[x1][y1][x2][y2][p][id];
	res = 0;
	if (x1 == x2) {
		for (int i = y1; i >= y2; i--) 
			if (i != y1) p = nxt[p][a[x1][i] - 'A'];
		res = (p + 1 == n);
		return res;
	}
	for (int i = y1; i >= y2; i--) {
		if (i != y1) p = nxt[p][a[x1][i] - 'A'];
		res += Go_Up(x1 - 1, i, x2, y1, p, (id + 1) % 4);
	}
	return res;
}

int Go_Up(int x1, int y1, int x2, int y2, int p, int id) {
	p = nxt[p][a[x1][y1] - 'A'];
	if (x1 < x2 || y1 > y2) {
		return (p + 1 == n);
	}
	if (dp[x1][y1][x2][y2][p][id] != -1) return dp[x1][y1][x2][y2][p][id];
	int &res = dp[x1][y1][x2][y2][p][id];
	res = 0;
	if (y1 == y2) {
		for (int i = x1; i >= x2; i--) 
			if (i != x1) p = nxt[p][a[i][y1] - 'A'];
		res += (p + 1 == n);
		return res;
	}
	for (int i = x1; i >= x2; i--) {
		if (i != x1) p = nxt[p][a[i][y1] - 'A'];
		res += Go_Right(i, y1 + 1, x1, y2, p, (id + 1) % 4);
	}
	return res;
}

signed main() {
	fast;
	//fre();
	cin >> nn >> mm >> s;
	for (int i = 1; i <= nn; i++) {
			cin >> a[i];
			a[i] = ' ' + a[i];
	}
	compute_automaton(s, nxt);
	memset(dp, 255, sizeof(dp));
	cout << Go_Right(1, 1, nn, mm, 0, 0);
}

/*
3 3
VOI
VVV
IOI
OVO*/
