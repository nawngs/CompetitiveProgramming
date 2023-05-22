#include <bits/stdc++.h>

using namespace std;

int k, n;
string s[1000005], a[12];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("TAOSO.INP", "r", stdin);
	//freopen("TAOSO.OUT", "w", stdout);
	cin >> k >> n;
	for(int i = 1; i <= k; i++) cin >> a[i];
	sort(a + 1, a + k + 1);
	if(k == 1){
		for(int i = 1; i <= n; i++){
			cout << a[1];
		}
		return 0;
	}
	for(int i = 1; i <= k; i++){
		//cout << a[i] << '\n';
		s[i] = a[i];
		if(i == n) cout << a[i] << "\n";
	}
	if(n <= k) return 0;
	int len = k;
	int cnt = k;
	while(1){
		vector < string > news;
		for(int i = 1; i <= len; i++){
			//cout << s[i] << '\n
			for(int j = 1; j <= k; j++){
				string tmp = s[i] + a[j];
				news.push_back(tmp);
				cnt ++;
				if(cnt <= n){
					if(cnt == n) cout << tmp << '\n';
				}
				else return 0;
			}
		}
		len = news.size();
		for(int i = 1; i <= len; i++) s[i] = news[i - 1];
	}
}