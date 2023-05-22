#include <bits/stdc++.h>

using namespace std;

const int NTEST = 1; //so luong test
const string TESTNAME = "TASK"; // ten bai

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long get_random(long long l, long long r) {
    return l + (rd() % (r - l + 1));
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
	int n = get_random(1, 10);
	cout << n << '\n';
	for (int i = 1; i <= n; i++) {
		int x = get_random(-100, 100);
		cout << x << ' ';
	}
	cout << '\n';
}

int main(){
	string fout = TESTNAME + ".inp"; //fout = "TASK.INP"
	//freopen(fout.c_str(), "w", stdout); //tao file .INP co input
	srand(time(NULL)); // tranh lap test
	for(int test = 1; test <= NTEST; test ++){
		make_test();
	}
}

