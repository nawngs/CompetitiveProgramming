//link: https://oj.vnoi.info/problem/fc125_gcdarr
#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e5;
int n, a[nmax + 5], f[nmax + 5], g[nmax + 5];

vector < int > prime[nmax + 5];

void sang(){
	for(int i = 1; i <= nmax; i++) f[i] = i;
	for(int i = 2; i * i <= nmax; i++)
		if(f[i] == i) for(int j = i * 2; j <= nmax; j += i) f[j] = i;
}

void ptich(int i){
	int x = a[i];
	while(x > 1){
		int temp = f[x];
		prime[i].push_back(temp);
		while(temp == f[x]) x /= temp;
	}
}

int main(){
	sang();
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ptich(i);
	}
	for(auto v : prime[1]) g[v] = 1;
	int ans = 1e9, pos;
	for(int i = 2; i <= n; i++){
		int len = 0;
		for(auto u : prime[i]){
			bool th = false;
			for(auto v : prime[i - 1]){
				if(u == v){
					th = true;
					continue;
				}
			}
			if(th) g[u] ++;
			else g[u] = 1;
			len = max(len, g[u] + 1);
		}
		//cout << i << " " << len << '\n';
		if(len != 0 && i - len + 1 != 0){
			if(ans > len){
				ans = len;
				pos = i;
			}
		}
	}
	if(ans == 1e9) cout << -1;
	else cout << ans << " " << pos - ans + 1 << " " << pos;
}