#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 5000
#define INF 99999999

using namespace std;
int n,k;

void phanTich(int n)
{
	for (int i = 2; i <= n; i++)
	{
		for (int j = i;;)
		{
			if (n % j == 0)
			{
				cout << j << " * ";
				n /= j;
			}
			else
				break;
		}
	}
}

int main(int argc, char const *argv[])
{
	phanTich(100);
	return 0;
}
