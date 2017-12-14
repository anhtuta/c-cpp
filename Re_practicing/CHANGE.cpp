#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 20

/*
Chủ cửa hàng có các tờ tiền là: 1, 5, 10, 50, 100, 500.
item giá = N. Minh có 1000, 
hỏi số tờ tiền cần trả lại ít nhất = ?

Bài này giải = thuật toán tham lam: cứ trả lại tiền thừa = tờ 
tiền to nhất, sau đó lấy các tờ nhỏ hơn... Như vậy số tờ cần trả
lại sẽ ít nhất. Vậy ban đầu trả = 500, sau đó 100, 50,...

*/

using namespace std;

int N;	//item's price
int a[] = {500, 100, 50, 10, 5, 1};

int moneyChanging(int m) {		//m = so tien can tra lai
	int cnt = 0;	// biến này để đếm số lượng tờ cần tìm
	int sid = 0;
	while(m != 0) {
		for (int i = sid; i < 6; ++i)
		{
			if(m >= a[i]) {
				m = m - a[i];
				cnt++;
				sid = i;	// khi đã lấy các tờ tiền to trả
				// lại rồi thì ko thể lấy nữa. VD: khi đã trả
				// lại 500, 100 rồi thì các lần tính sau chỉ
				// cần xét với các tờ bé hơn, tức là từ i = 2 trở đi
				break;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> N;
	cout << moneyChanging(1000 - N);
}