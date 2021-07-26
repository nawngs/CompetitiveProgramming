//link: https://oj.vnoi.info/problem/krect
#include <bits/stdc++.h>

using namespace std;

int n, m, cnt[105][105][30], ans = 0, x;
string s;


int calc(int x1, int y1, int x2, int y2){
	int res = 0;
	for(int i = 1; i <= 26; i++){
		res += (cnt[x2][y2][i] + cnt[x1 - 1][y1 - 1][i] - cnt[x2][y1 - 1][i] - cnt[x1 - 1][y2][i]) > 0;
	}
	return res;
}

int main(){
	cin >> n >> m >> x;
	for(int i = 1; i <= n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			for(int k = 1; k <= 26; k++){
				cnt[i][j + 1][k] = cnt[i - 1][j + 1][k] + cnt[i][j][k] - cnt[i - 1][j][k] + (s[j] == 'A' + k - 1);
			}
			//cout << j << '\n';
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int temp1 = m;
			int temp2 = m;
			for(int k = i; k <= n; k++){
				while(temp1 >= 1 && calc(i, j, k, temp1) >= x) temp1 --;
				while(temp2 >= 1 && calc(i, j, k, temp2) > x) temp2 --;
				//if(temp2 <= j) break;
				ans += temp2 - temp1;
				//cout << i << " " << j << " " << k << " " << temp1 << " " << temp2 << '\n';
			}
		}
	}
	cout << ans << '\n';
}