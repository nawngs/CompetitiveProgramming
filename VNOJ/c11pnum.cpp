//link: https://oj.vnoi.info/problem/c11pnum
#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

const int nmax = 1e7;
ull n;
int k;
bool check[nmax + 3];
vector < ull > pnum;
void sang(){
	for(int i = 1; i <= nmax; i++) check[i] = true;
	check[1] = check[0] = false;
	for(int i = 2; i * i <= nmax; i++)
		if(check[i])
			for(int j = i * i; j <= nmax;  j+= i) check[j] = false;
	for(int i = 1; i <= nmax; i++){
		if(check[i]) pnum.push_back(i);
	}
}

int main(){
	sang();
	int t;
	cin >> t;
	while(t --){
		cin >> n >> k;
		ull ans = 0;
		for(int i = 0; i < pnum.size(); i++){
			//cout << ans << '\n';
			ull tmp = 1;
			bool th = true;
			for(int j = 1; j <= k; j++){
				//cout << n / tmp + 1 << " " << pnum[i + j - 1] <<  '\n';
				if((n / tmp) + 1 > pnum[i + j - 1]) tmp *= pnum[i + j - 1];
				else{
					th = false;
					break;
				}
			}
			if(th){
				ans = tmp;
			}
			else{
				if(ans != 0) cout << ans << '\n';
				else cout << (int) -1 << '\n';
				break;
			}	
		}
	}
}