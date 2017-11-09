///phan so

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

class PS  {
	int ts, ms;
	void rutgon();
	public: 
	   //void rutgon();
	   PS(int t = 0, int m = 1)  { ts = t; ms = m; rutgon(); }
	   friend PS operator+(PS p, PS q);
	   friend PS operator-(PS p, PS q);
	   friend ostream& operator<<(ostream & os, PS p);
	   
	   
};
int ucln(int a, int b) {
	while(a!=b) {
		if(a>b) a=a-b;
    	else b=b-a;
	}
	return a;
}

void PS::rutgon() {
	int usc = ucln(fabs(ts),fabs(ms));
	ts = ts/usc; ms = ms/usc;
}
PS operator+(PS p, PS q) {  return PS(p.ts*q.ms+p.ms*q.ts, p.ms*q.ms);  }
PS operator-(PS p, PS q) {
	
	/** tai sao cach sau lai sai?
	PS r;
	r.ts = p.ts*q.ms-p.ms*q.ts;
	r.ms = p.ms*q.ms;
	return r; **/
	//cach tren sai la vi ham rutgon co dang private.
	//chi can cho ham rutgon() owr dangj public laf ok
	//thees neen ta aps dungj cach sau:
	
	return PS(p.ts*q.ms-p.ms*q.ts, p.ms*q.ms);
}
ostream& operator<<(ostream & os, PS p) {  return (os<<p.ts<<"/"<<p.ms);  }  //hoac: os<<p.ts<<"/"<<p.ms; return os;


int main()  {
	PS p(6,10), q(4,10);
	cout<<"p = "<< p <<endl;
	cout<<"q = "<< q <<endl;
    cout<<p<<" + "<<q<<" = "<< p+q<<endl;
    cout<<p<<" - "<<q<<" = "<< p-q<<endl;
}
