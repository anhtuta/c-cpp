#include<stdio.h>
#include<iostream>
#include<time.h>
#include <stdlib.h>

using namespace std;

#define MAX 1000000
float a[MAX];
int n;

void swap(float &a,float &b) {
	float temp = a;
	a = b;
	b = temp;
}

void input() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%f", &a[i]);
	}
}

void input_charWay() {
	cin >> n;
	int i;
	getchar();
	fflush(stdin);
	for(i=0; i<n; i++) {
		a[i] = readInt();
	}
}

float readInt() {
	bool isNeg;
	char ch;
	int val = 0;
	
	while(true) {
		ch = getchar();
		if(ch=='-') {
			isNeg=true;
			continue;
		}
		if(ch=='.') continue;
		if(ch<'0' || ch>'9') break;
		val = val*10 + ch-'0';
	}
	val=isNeg?-val:val;
	return val/100.;	//do input la so thuc voi 2 chu so dang sau dau phay
}

void generateInput() {
	freopen("input2.txt", "w", stdout);
	srand (time(NULL));
	n = 100000;
	cout << n <<endl;
	for(int i=0; i<n; i++) {
		a[i] = rand()%10000;
		cout<<a[i]<<" ";
	}
}

void insertionSort() {
	int i,j;
	for(i=1; i<n; i++) {
		float temp = a[i];
		j = i;
		while(j>0 && a[j-1]>temp) {		//cach de chen 1 so vao dung vi tri, how to insert a number into the correct position
			a[j] = a[j-1];
			j--;
		}
		a[j] = temp;
	}
}

void selectionSort() {
	int i,j, indexMin;
	for(i=0; i<n; i++) {
		indexMin = i;
		for(j=i+1; j<n; j++) {
			if(a[j] < a[indexMin]) indexMin = j;
		}
		swap(a[i], a[indexMin]);
	}
}

int PartitionR(int p, int r) {
	float x = a[r];
	int j = p - 1;
	for (int i = p; i < r; i++) {
		if (x >= a[i]) {
		    j = j + 1;
		    swap(a[i], a[j]);
		}
	}
	a[r] = a[j + 1]; a[j + 1] = x;
	return (j + 1);
}

void quickSort(int p, int r) {
	if (p < r) {
		int q = PartitionR(p, r);
		quickSort(p, q - 1);
		quickSort(q + 1, r);
	}
}

int partition(int L, int R, int pivotIndex) {
	int i;
	float pivot = a[pivotIndex];
	int storeIndex = L;
	swap(a[pivotIndex], a[R]);
	
	//dich chuyen cac phan tu nho hon pivot ve phia ben trai cua day
	for(i=L; i<R; i++) {
		if(a[i] < pivot) {
			//dich chuyen a[i] ve ddaauf dayx
			swap(a[storeIndex], a[i]);
			storeIndex++;
		}
	}
	swap(a[R], a[storeIndex]);	//dat phan tu chot ve dung vi tri (put pivot into its right position)
	return storeIndex;
}

void quick_sort(int L, int R) {
	if(L < R) {
		int mid = (L+R)/2;
		int pivotIndex = partition(L, R, mid);
		quick_sort(L, pivotIndex-1);
		quick_sort(pivotIndex+1, R);
	}
}

void heapSort(int n) {
	buildHeap(n);
	for(int i =n-1; i>0; i--) {
		swap(a[0])
	}
}

void displayResult() {
	int i;
	for(i=0; i<n; i++) {
		printf("%.2f ", a[i]);
	}
}

int main() {
	//generateInput();
	freopen("input.txt", "r", stdin);
	input_charWay();
	//insertionSort();
	//selectionSort();
	quick_sort(0, n-1);
	displayResult();
	
	return 0;
}
