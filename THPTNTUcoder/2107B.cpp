#include <bits/stdc++.h>

using namespace std;

int h1, h2, m1, m2, ans = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> h1 >> m1 >> h2 >> m2;
	for(int i = h1; i <= h2; i++){
		for(int j = 0; j <= 59; j++){
			if(i == h1 && j < m1) continue;
			if(j == 0) ans += (i % 12) + 12 * (i % 12 == 0);
			if(j == 30) ans ++;
			if(i == h2 && j == m2) break;
		}
	}
	cout << ans;
}