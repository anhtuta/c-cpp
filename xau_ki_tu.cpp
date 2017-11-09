///vi du dinh nghia lai toan tu
//dinh nghia lai toan tu + de noi 2 xau, va toan tu xuat nhap : >>,<<


#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>

using namespace std;

class String {
	char *str; //con tro tro toi noi dung xau
	public: 
	   String (char *s="")  {
	   	  if(s==0) str = strdup("");
	   	  else str = strdup(s);
	   }
	   
	   ~String();
	   int len()  { return strlen(str);  }
	   friend String operator+(const String&, const String&);
	   friend ostream& operator << (ostream & os, String & s);
	   friend ostream& operator >> (ostream&, String&);
};

String operator+(const String& s1, const String& s2) {
	char *nstr = new char[s1.len() + s2.len() + 1];
	
	strcpy(nsrt,s1.str);
	strcat(nsrt,s2.str);
	String s(nstr);
	delete [] nstr;
	return s;
}

ostream& operator << (ostream& os, String& s) {
	return (os << s.str);
}

ostream& operator >> (ostream& is, String& s) {
	char temp[80];
	is.getline(temp, sizeof(temp));
	s = temp;
	return is;
}

int

