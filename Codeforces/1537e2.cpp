//z_function
#include <bits/stdc++.h>
 
using namespace std;
 
int n, k, z[500005];
string s;
 
void build_z(){
	z[0] = n;
	int l, r;
	l = r = -1;
	for(int i = 1; i < n; i++){
		if(i > r){
			l = i;
			r = i - 1;
			while(r < n - 1 && s[r + 1] == s[r - l + 1]) r++;
			z[i] = r - l + 1;
		}
		else{
			if(z[i - l] < r - i + 1) z[i] = z[i - l];
			else{
				l = i;
				while(r < n - 1 && s[r + 1] == s[r - l + 1]) r++;
				z[i] = r - l + 1;
			}
		}
	}
}
 
int main(){
	cin >> n >> k >> s;
	build_z();
	int cuoi = n;
	for(int i = 1; i < n; i++){
		if(s[i] > s[0]){
			cuoi = i;
		}
		if(s[i] == s[0]){
			int last = i + z[i];
			if(s[last] > s[z[i]]) cuoi = i;
		}
		if(cuoi == i) break;
	}
	cuoi --;
	while(s[cuoi] == s[0] && cuoi != 0) cuoi --;
	//cout << cuoi << "\n";
	string news = "";
	for(int i = 0; i <= cuoi; i ++){
		news += s[i]; 
	}
	//cout << news << '\n';
	while((int) news.size() < k) news = news + news;
	for(int i = 0; i < k; i++) cout << news[i];
}