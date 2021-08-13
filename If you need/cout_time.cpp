#include <bits/stdc++.h>

using namespace std;

int main(){
	//nhap input
	clock_t start, end;   
    double time_use;     
    start = clock();
    //xu ly
    end = clock();
	time_use = double(end - start) / CLOCKS_PER_SEC;
	cout << time_use;
}