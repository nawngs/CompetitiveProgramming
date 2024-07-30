#include "coprobber.h"
#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 500;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

using tiii = tuple < int, int, int >;

bool dp[2][N][N]; // 0 la can 1 la trom

int nxt[N][N], cnt[N][N], cur; 

// int n, a[N][N];

int start(int n, bool a[N][N]) {
	queue < tiii > heap;
	for (int i = 0; i < n; i++) dp[0][i][i] = dp[1][i][i] = 1, heap.push({0, i, i}), heap.push({1, i, i});
	for (int t = 0; t < n; t++)
	for (int i = 0; i < n; i++) {
		if (t == 0) for (int j = 0; j < n; j++) cnt[t][i] += a[i][j];
		else cnt[t][i] = cnt[t - 1][i];
	}
	while (heap.size()) {
		int ope, i, j; tie(ope, i, j) = heap.front(); heap.pop();
		if (ope == 0) { // luot can
			for (int pre = 0; pre < n; pre++) if (a[j][pre]) {
				cnt[i][pre] --;
				if (cnt[i][pre] == 0) {
					dp[ope ^ 1][i][pre] = 1;
					heap.push({ope ^ 1, i, pre});
				}
			}
		}
		else {
			for (int pre = 0; pre < n; pre++) if ((i == pre || a[i][pre]) && !dp[ope ^ 1][pre][j]) {
				dp[ope ^ 1][pre][j] = 1;
				heap.push({ope ^ 1, pre, j});
				nxt[pre][j] = i;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		bool th = 1;
		for (int j = 0; j < n; j++) th &= dp[0][i][j];
		if (th) return cur = i;
	}
	return -1;
}

int nextMove(int R) {
	return cur = nxt[cur][R];
}
/*
int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++) cin >> a[i][j];
	cout << start();
}*/