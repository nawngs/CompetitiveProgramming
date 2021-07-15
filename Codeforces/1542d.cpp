#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;
long long n, a[505], f[505][505], ans = 0;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		char ch;
		cin >> ch;
		if(ch == '-') a[i] = -1;
		else cin >> a[i];
	}
	for(int k = 1; k <= n; k++){
		if(a[k] > 0){
			memset(f, 0, sizeof(f));
			f[0][0] = 1;
			for(int i = 1; i <= n; i++){
				for(int j = 0; j <= n; j++){
					f[i][j] = f[i - 1][j];
					if(a[i] == -1){
						f[i][j] += f[i - 1][j + 1];
						if(j == 0 && i < k) f[i][j] += f[i - 1][j];
						f[i][j] %= MOD;
						//cout << a[k] << " " << i << " " << j << " " << f[i][j] << '\n';
						continue;
					}
					if(a[i] > a[k] || (a[i] == a[k] && i < k)){
						f[i][j] += f[i - 1][j];
						f[i][j] %= MOD;
					}
					if((a[i] < a[k] || (a[i] == a[k] && i > k)) && j > 0){
						f[i][j] += f[i - 1][j - 1];
						f[i][j] %= MOD;
					}
					//cout << a[k] << " " << i << " " << j << " " << f[i][j] << '\n';
				}	
			}
			long long cnt = 0;
			for(int j = 0; j <= n; j++) cnt = (cnt + f[n][j]) % MOD;
			//	cout << cnt << '\n';
			ans = (ans + (a[k] * cnt) % MOD) % MOD;
		}
	}
	cout << ans;
}