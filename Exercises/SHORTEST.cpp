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

const string NAME = "SHORTEST";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int x[4] = {-1, 0, 0, 1};
const int y[4] = {0, -1, 1, 0};
int n, m, a[1005][1005], d[1005][1005];

int bfs(){
	queue < pii > que;
	d[1][1] = 1;
	que.push({1, 1});
	while(que.size() > 0){
		pii u = que.front();
		que.pop();
		for(int i = 0; i < 4; i++){
			int newx = u.fi + x[i];
			int newy = u.se + y[i];
			if(newx > 0 && newy > 0 && newx <= n && newy <= m && d[newx][newy] == -1 && a[newx][newy] != 1){
				d[newx][newy] = d[u.fi][u.se] + 1;
				que.push({newx, newy});
			}
		}
	}
	return d[n][m];
}

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

void sol() {
	memset(d, 255, sizeof(d));
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) cin >> a[i][j];
	cout << bfs() << '\n';	
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
