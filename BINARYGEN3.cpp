#include<iostream>
#include<bits/stdc++.h>
#define MAX 10000

/*
Chú ý: ddeef baif vaanx nhw cux, 
Cach binh thuong: lieetj kee taat car cac xaau nhij phaan, sau dos neeus gawpj xaau nafo = xaau input nhaapj vafo thif in ra xaau kee tieeps cuar nos
baif nayf lamf cachs khac: coi nhu ta cong 1 vao xau input
do vay bai nay chi ddown gianr laf thwcs hieenj pheps coongj vowis 1 vaof xaau input, 
*/
using namespace std;

int n = 0;
char s[MAX];

int main(){
    cin >> n;
    cin >> s;
    int temp='1';
    for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            s[i]=temp;
            temp = '0';
        } else {
            if(temp=='0'){
               s[i] = '1';
            } else {
                s[i] = '0';
                temp = '1';
            }
        }
    }
    if(temp == '1')
        cout << char(temp);
    cout << s;
    return 0;
}

