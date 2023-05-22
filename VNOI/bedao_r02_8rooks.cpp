#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const ll ESP = 1e-9;
const int INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int q, k, f[10][10], dp[10][260];

map < string, int > res;

int count_bits(int x) {
	int cnt = 0;
	while (x) {
		cnt += x & 1;
		x >>= 1;
	}
	return cnt;
}

bool getbit(int pos, int a){
	return (a & 1 << pos);
}


void bfs(int start) {
	for (int i = 0; i < 8; i++) f[start][i] = INF;
	f[start][start] = 0;
	queue < int > que;
	que.push(start);
	while (que.size()) {
		int tam = que.front();
		que.pop();
		int new1 = ((tam - k) % 8 + 8) % 8;
		int new2 = (tam + k) % 8;
		if (f[start][new1] == INF) {
			f[start][new1] = f[start][tam] + 1;
			que.push(new1);
		} 
		if (f[start][new2] == INF) {
			f[start][new2] = f[start][tam] + 1;
			que.push(new2);
		}
	}
}

void build_f() {
	for (int i = 0; i < 8; i++) bfs(i);
}

void update(string s) {
	for (int i = 0; i <= 8; i++)
		for (int j = 0; j < 256; j++) dp[i][j] = INF;

	dp[0][0] = 0; 
	for (int i = 1; i <= 8; i++) {
		for (int j = 0; j < 256; j++) {
			if (count_bits(j) == i) {
				for (int k = 0; k < 8; k++) {
					int tam = s[i - 1] - '1';
					if (getbit(k, j)) dp[i][j] = min(dp[i][j], dp[i - 1][j - (1 << k)] + f[tam][k]);
				}
				//cout << i << " " << j << " " << dp[i][j] << '\n';
			}
		}
	}
	res[s] = dp[8][255] == INF ? -1 : dp[8][255];
	return;
}

void sol() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if (res.find(s) != res.end()) {
		cout << res[s] << '\n';
		return;
	}
	update(s);
	cout << res[s] << '\n';
	return ;
}

int main() {
	slow;
	cin >> q >> k;
	build_f();
	while (q --) sol();
}