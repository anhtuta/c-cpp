#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 10000

using namespace std;

int a[MAX+1];
int n;
char xauInput [10000];
char xauKq [10000];
bool isPrint = false;
char temp [5];

void clearData() {
	for(int i=0; i<=n; i++) {
		a[i] = -1;
	}
}

void printSolution() {
	if(isPrint) {
		cout << "isPrint=true:\n";
		for(int i=1; i<=n; i++) {
			cout<<a[i];
		}
		cout<<endl;
		isPrint = false;
		return;
	}
	
	strcpy(xauKq, "");
	for(int i=1; i<=n; i++) {
		sprintf(temp, "%d", a[i]);	//copy so nguyen i vao xau temp
		strcat(xauKq, temp);
	}
	if(strcmp(xauKq, xauInput)) {
		cout << "xauKq = " << xauKq << endl;
		isPrint = true;
	}
}

bool thuocTapUCV(int i, int k) {	//kiem tra so i co thuoc tap UCV Sk hay ko
	if(a[k-1] == 0 && i==0) return false;
	return true;
}

///sinh xau nhi phan do dai n
void permutation(int k) {
	for(int i=0; i<=1; i++) {
		a[k] = i;
		if(k==n) printSolution();
		else permutation(k+1);
	}
}


int main() {
	cin >> n;
	cin >> xauInput;
	clearData();
	permutation(1);
}

