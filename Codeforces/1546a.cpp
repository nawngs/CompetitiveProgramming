#include <bits/stdc++.h>

using namespace std;

int ntest;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> ntest;
	while(ntest --){
		int n, a[105], b[105], sum = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++){
			cin >> b[i];
			sum += a[i] - b[i];
		}
		if(sum != 0){
			cout << -1 << '\n';
			continue;
		}
		else{
			int ans = 0;
			for(int i = 1; i <= n; i++){
				ans += abs(b[i] - a[i]);
			}
			ans /= 2;
			cout << ans << '\n';
			for(int i = 1; i <= n; i++){
				for(int j = i + 1; j <= n; j++){
					if(a[i] == b[i]) break;
					if(a[i] < b[i] && a[j] > b[j]){
						while(a[i] != b[i] && a[j] != b[j]){
							a[i] ++;
							a[j] --;
							cout << j << " "  << i << '\n';
						}
					}
					if(a[j] < b[j] && a[i] > b[i]){
						while(a[i] != b[i] && a[j] != b[j]){
							a[j] ++;
							a[i] --;
							cout << i << " " << j << '\n';
						}
					}
				}
			}
		}
	}
}