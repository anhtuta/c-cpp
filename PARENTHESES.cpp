#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <string>
#include <stack> 

using namespace std;

bool match(char c, char cc) {
    if(c=='(' && cc==')') return true;
    if(c=='[' && cc==']') return true;
    if(c=='{' && cc=='}') return true;
    return false;
}

int checkParentheses(string str) {
	if(str.length() < 0) return 0;
	stack<char> s;
	
    int i;
    char c, cc;
    for (i = 0; i < str.length(); i++) {
        c = str[i];
        if(c=='(' || c=='[' || c=='{') s.push(c);
        else if(c==')' || c==']' || c=='}') {
            if(s.empty()) {
                return 0;
            }
            cc = s.top();
            s.pop();
            if(!match(cc, c)) {
                return 0;
            }
        }
    }
    
    if(s.empty()) return 1;
    else return 0;
}

int main() {
	//freopen("parentheses_input.txt", "r", stdin);
	int n,i;
	string str;
	
	cin >> n;
	int * kq;
	kq = new int[n];
	for(i=0; i<n; i++) {
		cin >> str;
		kq[i] = checkParentheses(str);
	}
	
	for(i=0; i<n; i++) {
		cout << kq[i] << endl;
	}
}
