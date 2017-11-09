#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<malloc.h>
#define MAX 10000

using namespace std;

int main() {
	int someInt = 368;
	int n;
	char str[12];
	char temp[10];
	
	//==============================
	sprintf(str, "%d", someInt);
	cout << str << endl;
	//==============================
	
	//==============================
	char *mystr;
	cout << "enter n = ";
	cin >> n;
	mystr = (char *) malloc(sizeof(char)*n + 10);
	
	char str2[100];
	strcpy(str2, "str2");
	//==============================
	
	strcpy(mystr, "anhtu");
	cout << mystr << endl;
	
	for(int i=0; i<n; i++) {
		sprintf(temp, "%d", i);
		cout << "temp = " << temp << endl;
		strcat(mystr, temp);
		strcat(str2, temp);
	}
	
	cout << mystr << endl;
	cout << str2 << endl;
}
