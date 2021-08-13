#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = 1E9;

int n, w1, w2;
int dp[55][5005][255], trace1[55][5005][255], res[55];
int x, trace[1005], f[1005][5005];

pair < int, int > a[1005];

//sub 1 2 3

//###############################################################################

void sol1(){ 
	for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

	for(int i = 0; i <= w1; i++)
		for(int j = 0; j <= 250; j++) dp[0][i][j] = INF;

	dp[0][0][0] = 0;
	int v = 0;
	int w;

	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= w1; j++){
			for(int k = 0; k <= 250; k++){
				dp[i][j][k] = dp[i - 1][j][k];
				trace1[i][j][k] = 0;
				if(j - a[i].fi >= 0 && k >= a[i].se){
					//dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - a[i].fi][k - a[i].se]);
					if(dp[i][j][k] > dp[i - 1][j - a[i].fi][k - a[i].se]){
						dp[i][j][k] = dp[i - 1][j - a[i].fi][k - a[i].se];
						trace1[i][j][k] = 1;
					}
				}
				if(k >= a[i].se && dp[i - 1][j][k - a[i].se] + a[i].fi <= w2){
					//dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - a[i].se] + a[i].fi);
					if(dp[i][j][k] >  dp[i - 1][j][k - a[i].se] + a[i].fi){
						dp[i][j][k] =  dp[i - 1][j][k - a[i].se] + a[i].fi;
						trace1[i][j][k] = 2;
					}
				}
				if(i == n && dp[i][j][k] <= w2){
					if(k > v){
						v = k;
						w = j;
					}
				}
				//if(j == 900) cout << i << " " << j << " " << k << " " << dp[i][j][k] << '\n';
			}
		}
	}
	int i = n;
	while(i > 0){
		if(trace1[i][w][v] == 2){
			res[i] = 2;
			v -= a[i].se;
			i--;
			continue;
		}
		if(trace1[i][w][v] == 1){
			res[i] = 1;
			w -= a[i].fi;
			v -= a[i].se;
			i --;
			continue;
		}
		res[i] = 0;
		i --;
	}
	for(int i = 1; i <= n; i++) cout << res[i] << ' ';
}

//#########################################################################################################3

// sub4

bool cmp(pair < int, int > x, pair < int , int > y){
	return x.fi > y.fi;
}

void sol2(){
	memset(trace, 255, sizeof(trace));
	memset(f, 255, sizeof(f));
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi >> x;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= w1; i++) f[0][i] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= w1; j++){
			f[i][j] = f[i - 1][j];
			if(j >= a[i].fi) f[i][j] = max(f[i][j], f[i - 1][j - a[i].fi] + x);
		}
	}
	int pos = n;
	int w = w1;
	while(pos >= 1){
		if(f[pos][w] == f[pos - 1][w]){
			pos --;
			continue;
		}
		trace[a[pos].se] = 1;
		w -= a[pos].fi;
		pos --;
	}
	int sum = 0;
	for(int i = n; i >= 1; i--){
		if(trace[a[i].se] == 1){
			continue;
		}
		sum += a[i].fi;
		if(sum <= w2){
			trace[a[i].se] = 2;
		}
		else trace[a[i].se] = 0;
	}
	for(int i = 1; i <= n; i++) cout << trace[i] << ' ';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("KNAPSACK.Inp", "r", stdin);
	freopen("KNAPSACK.Out", "w", stdout);
	cin >> n >> w1 >> w2;
	if(n <= 50) sol1();
	else sol2();
}