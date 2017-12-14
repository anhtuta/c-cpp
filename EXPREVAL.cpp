#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define MAX 31

using namespace std;

long long n;
long long *a;
long long *b;
long long MODU = 1000000007;

void input() {
	cin >> n;
	a = (long long*)malloc(sizeof(long long)*(n));
	b = (long long*)malloc(sizeof(long long)*(n));
	
	for (long long i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (long long i = 1; i < n; ++i)
	{
		cin >> b[i];
	}
	b[0] = -1;
}

void expreval() {
	long long s = a[0];
	for (long long i = 1; i < n; ++i)
	{
		if(b[i] == 0) s = s - a[i];
		else if(b[i] == 1) s = s + a[i];
		else if(b[i] == 2) {
			//cout << "gap phep nhan: i = "<<i<<endl;

			// Lấy lại giá trị của s trước lúc gặp dấu nhân
			if(b[i-1] == 0) s = s + a[i-1];
			else if(b[i-1] == 1) s = s - a[i-1];

			long long temp = a[i-1];
			//cout <<"\ttemp = "<<temp<<endl;
			long long chiSoCuaDauNhanCuoiCung = i;
			for (long long j = i; j < n; ++j)
			{
				if(b[j] != 2) break;
				temp = temp*a[j];
				chiSoCuaDauNhanCuoiCung = j;
				//cout <<"\ttemp = "<<temp<<endl;
			}

			//cout <<"\n\ttemp = "<<temp<<endl;

			if(b[i-1] == 0) s = s - temp;
			else if(b[i-1] == 1) s = s + temp;
			else if(b[i-1] == -1) s = temp;	// trường hợp b[1] là dấu nhân
			i = chiSoCuaDauNhanCuoiCung;
			//cout <<"chiSoCuaDauNhanCuoiCung = "<<chiSoCuaDauNhanCuoiCung<<endl;
		}
		
		//cout << "s = "<<s<<endl;
		if(s > MODU) s = s%MODU;
		else if(s < 0) s = s + MODU;	// CHÚ Ý PHẢI CÓ DÒNG NÀY!
	}

	cout << s;
}

int main() {
	freopen("expreval2.txt", "r", stdin);
	input();
	expreval();
}