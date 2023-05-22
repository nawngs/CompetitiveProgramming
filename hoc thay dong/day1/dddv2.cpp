#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[33][33], pt[903][903], num = 0;

int calc(int i, int j) {
	return (i - 1) * n + j;
}

string mul(string a, string b) {
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
            tmp+=carry;
            carry=tmp/10;
            res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}

string mu(int a, int b) {
	if (b == 0) return "1";
	string x = mu(a, b / 2);
	x = mul(x, x);
	if (b % 2 == 1) x = mul(x, "2");
	return x;
}


void sol() {
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] != -1) {
				pt[++ num][0] = a[i][j];
				for (int change = 0; change < 4; change++) {
					int newi = i + dx[change];
					int newj = j + dy[change];
					if (newi < 1 || newj < 1 || newi > m || newj > n) continue;
					pt[num][calc(newi, newj)] = 1;
 				}
			}
		}
	int free = 0;
	for (int i = 1; i <= num; i++) {
		int pos = -1;
		for (int j = 1; j <= n * m; j++) {
			if (pt[i][j] == 1) {
				pos = j;
				break;
			}
		}
		//cout << i << " " << pos << '\n';
		if (pos == -1 && pt[i][0] != 0) {
			cout << 0 << '\n';
			return ;
		}
		if (pos == -1) {
			free ++;
			continue;
		}
		for (int j = i + 1; j <= num; j++) {
			if (pt[j][pos] == 1) for (int k = 0; k <= n * m; k++) pt[j][k] = (pt[j][k] + pt[i][k]) % 2;
		}
	}
	//cout << num << " " << free << '\n';
	cout << mu(2, m * n - num + free) << '\n';
}

int main() {
	fast;
	//fre();
	while (cin >> m >> n && m != 0 && n != 0) sol();
}
