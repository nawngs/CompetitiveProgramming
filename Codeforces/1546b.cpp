#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, ntest;
string s[100005], str;
int cnt[100005][30];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> ntest;
	while(ntest --){
		memset(cnt, 0, sizeof(cnt));
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> s[i];
		for(int i = 1; i < n; i++){
			cin >> str;
			for(int j = 0; j < m; j++){
				cnt[j][str[j] - 'a' + 1] ++;
			}
		}
		bool th = true;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < m; j++){
				if(cnt[j][s[i][j] - 'a' + 1] > 0) cnt[j][s[i][j] - 'a' + 1] --;
				else{
					cout << s[i] << '\n';
					th = false;
					break;
				}
			}
			if(!th) break;
		}
	}
}

