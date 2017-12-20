#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define MAX 31
#define PLUS 0
#define SUB 1
#define MULTIPLY 2
#define DIVIDE 3

using namespace std;

// Bài này thêm dấu chia nữa. Do đó kq sẽ ở dạng số thực
// s = a0 b1 a1 b2 a2 b3 a3 ... bn an, trong đó bi là 1 trong 4 dấu +,-,x,:
/*
VD:
input:
16
3 15 31 18 21 11 24 8 6 7 12 22 41 42 34 2
2 0 1 2 1 3 0 2 3 2 1 0 1 3 2

output:


explain:
3 * 15 + 31 - 18 * 21 - 11 / 24 + 8 * 6 / 7 * 12 - 22 + 41 - 42 / 34 * 2 = -203.6432
*/
long long n;
long long *a;
long long *b;
long long MODU = 1000000007;

void input() {
	cin >> n;
	a = (long long*)malloc(sizeof(long long)*(n));
	b = (long long*)malloc(sizeof(long long)*(n));
	
	for (long long i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (long long i = 1; i < n; ++i) {
		cin >> b[i];
	}
	b[0] = -1;

	for (long long i = 0; i < n; ++i) {
		cout << a[i]<< " ";
	}
	cout<<endl;
	for (long long i = 0; i < n; ++i) {
		cout << b[i]<< " ";
	}
	cout<<endl;
}

void debug(int i, double s) {
	cout <<"i = "<<i <<", s = "<<s<<endl;
	cout << a[0];
	for (int k = 1; k <= i; ++k)
	{
		if(b[k] == PLUS) cout<<"+";
		if(b[k] == SUB) cout<<"-";
		if(b[k] == MULTIPLY) cout<<"*";
		if(b[k] == DIVIDE) cout<<"/";
		
		cout<< a[k];
	}
	cout << " = " << s<<endl<<endl;
}

double expreval() {
	double s = a[0];
	for (int i = 1; i < n; ++i)
	{
		switch(b[i]) {
			case PLUS:
				s = s + a[i];
				break;
			case SUB:
				s = s - a[i];
				break;
			case MULTIPLY:
			case DIVIDE:
				cout << "Gap phep nhan hoac chia, b["<<i<<"] = "<<b[i]<<endl;
				// Lấy lại giá trị của s trước lúc gặp dấu nhân
				if(b[i-1] == PLUS) s = s - a[i-1];
				else if(b[i-1] == SUB) s = s + a[i-1];
				
				int j = i;
				int chiSoDauNhanCuoiCung;
				double temp = a[j-1];		// temp là biến lưu tất cả phép toán từ khi gặp phép * hoặc chia tới khi gặp cộng hoặc trừ
				// VD trên, i = 8 thì ban đầu temp = a[i-1] = a[7] = 8. Cuối cùng temp = 8 * 6 / 7 * 12
				
				while(b[j] != PLUS && b[j] != SUB && j < n) {	// nếu quên điểu kiện j < n là sai phần cuối, vì mảng b có kích thước > n
					if(b[j] == MULTIPLY) temp *= a[j];
					else temp /= a[j];
					chiSoDauNhanCuoiCung = j;
					j++;
				}

				if(b[i-1] == PLUS) s = s + temp;
				else if(b[i-1] == SUB) s = s - temp;
				else s = temp;	// trường hợp b[1] là dấu nhân hoặc chia
				i = chiSoDauNhanCuoiCung;
				break;
		}
		debug(i, s);
	}
	return s;
}

int main(int argc, char const *argv[])
{
	freopen("expreval_extend.txt", "r", stdin);
	input();
	cout << expreval();
	return 0;
}
