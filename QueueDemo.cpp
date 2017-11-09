#include<stdio.h>
#include<iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

int main() {
	queue<int> q;
	q.push(12);
	q.push(3);
	q.push(5);
	q.push(11);
	q.push(22);
	
	cout << q.back() << endl;
	cout << q.front() << endl;
	
	q.pop();
	cout << q.back() << endl;
	cout << q.front() << endl;
}
