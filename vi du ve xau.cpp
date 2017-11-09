//viet 1 hamf xuwr lys xau:
//- sao chep xau twf vij tris x ddeens vij tris y trong xaau S
// chenf ki twj C vao vi tri x trong xau S
//- xoa ki tuwj owr vij tris x trong xau S

//chu y rangwf: ddooj daif cuar 1 xaau ko tinhs kys twj NULL
//vi du st[100] = "anhtu"; st cos ddooj daif = 5

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<mem.h>
#include<stdlib.h>

char *copy(char *st, int x, int y)  { //sao chep xau twf vij tris x ddeens vij tris y trong xaau st
    char *d; //d = destination, la kq cua vieecj sao chep xau twf vij tris x ddeens vij tris y trong xaau st: sao chep xong gan kq vao xau d
    d = (char *)malloc(y-x+2);
    memcpy(d, st+x,y+x-1); // copy (y-x+1) byte twf vij tris x cuar xaau st vaof d
    *(d+y-x+1) = '\0';  //ket thucs xau d phair laf kys twj NULL
    return (d);
}

char *insert(char ch, char *st2, char x) { //chenf ki twj ch vao vi tri x trong xau st2
	char s[255], *temp; //2 bieens tamj thowif, s[255] laf 1 mangr, temp laf 1 xaau
	int len; len = strlen(st2);
	temp = copy(st2,0,x-1);
	strcpy(s,temp);
	free(temp);
	s[x] = ch;
	s[x+1] = '\0'; //1 xaau phair keets thucs = NULL
	temp = copy(st2,x,len+1);
	
	strcat(s,temp);
	free(temp);
	strcpy(st2,s);
	return (st2);   //chu ys neeus ko copy vaof xaau st2 maf return s thif sex bij looix
}

char *del(char *st, int x)  {             //xoa kys twj owr vij tris x cuar xaau st
	int len = strlen(st);
	for (int i=x-1; i<=len; i++)  //i<=len+1 vi xaau st cos kys twj NULL owr cuoois cungf, vaf ta caanf laays car kys twj ddoos
	   st[i] = st[i+1];
	   return (st);
}
int main() {
	char st[100] = "anhtuta95dhbkhn";
	char *temp;   //temp cos vai trof laf 1 xaau chws ko phair laf 1 con tror
	printf("xau ban dau la: %s\n", st);
	temp = copy(st,2,7);
	printf("xau copy la: %s\n",temp);
	free(temp);
	
	printf("insert a : %s\n", insert('a',st,9));
	printf("delete h : %s\n", del(st,3));
}
