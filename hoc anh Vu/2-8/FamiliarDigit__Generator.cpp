#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int NTEST = 10; //so luong test
const string TESTNAME = "TASK"; // ten bai
const ll INF = 1e14;
const LL chimto = 1e16;
const ll LINF = 1E18;

long long get_random(long long l, long long h) {
    return l + rand() % (h - l + 1);
}

// get random(l , r) lay 1 so bat ki tu l den r

void make_test(){
	/*
	nhap input
	vd tao inp co n va day a[n]
	code:
	int n = get_random(l, r);
	for(int i = 1; i <= n; i++){
		int x;
		x = get_random(l, r);
		cout << x;
	}
	*/
	ll a = get_random(INF, LINF);
	ll b = get_random(chimto, LINF);
	ll k = get_random(1, 10);
	ll d = get_random(1, 10);
	cout << a << " " << b << " " << k << " " << d << '\n';
}

int main(){
	string fout = TESTNAME + ".inp"; //fout = "TASK.INP"
	//freopen(fout.c_str(), "w", stdout); //tao file .INP co input
	srand(time(NULL)); // tranh lap test
	cout << NTEST << '\n';
	for(int test = 1; test <= NTEST; test ++){
		make_test();
	}
}

