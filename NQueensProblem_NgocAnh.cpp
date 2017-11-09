#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MAXHOLES 144
int n=0, m=0;
int hau[12];
bool cot[12],cheo1[23],cheo2[23];
int hole[MAXHOLES][2];
int countSolutions = 0;

bool isHole(int x, int y){
    for(int i=0;i<m;i++){
        if(x==hole[i][0] && y==hole[i][1])
            return true;
    }
    return false;
}

void Try(int i)
{
    for (int j=0; j<n; j++)
    if(!isHole(i+1,j+1))
        if (cot[j] && cheo1[i+j] && cheo2[j-i+n])
        {
            hau[i] = j;
            cot[j] = false;
            cheo1[i+j] = false;
            cheo2[j-i+n] = false;
            if (i==n-1) countSolutions++;
            else Try(i+1);
            cot[j] = true;
            cheo1[i+j] = true;
            cheo2[j-i+n] = true;
        }
}

int main()
{
    cin >> n >> m;
    while(n!=0){
        countSolutions = 0;
        for(int i=0;i<m;i++){
            cin >> hole[i][0] >> hole[i][1];
        }
        for(int i=0;i<n;i++)
            cot[i]=true;
        for(int i=0;i<2*n;i++){
            cheo1[i]=true;
            cheo2[i]=true;
        }
        Try(0);
        cout << countSolutions << endl;
        cin >> n >> m;
    }
    return 0;
}
