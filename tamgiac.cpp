#include<stdio.h>
#include<conio.h>
#include<math.h>

typedef struct {
	float x,y;
}diem;

typedef struct {
	diem A, B, C;
}tamgiac;

void nhaptoado(tamgiac *t) { //t thu?c ki?u c?u trúc tamgiac. hàm này nh?p t?a d? 3 d?nh A,B,C c?a tam giac t
	float temp;

	printf("\nDinh A: ");
	printf("\nxA = "); scanf("%f", &temp); t->A.x = temp;
	printf("\nyA = "); scanf("%f", &temp); t->A.y = temp;

	printf("\nDinh B: ");
	printf("\nxB = "); scanf("%f", &temp); t->B.x = temp;
	printf("\nyB = "); scanf("%f", &temp); t->B.y = temp;

	printf("\nDinh C: ");
	printf("\nxC = "); scanf("%f", &temp); t->C.x = temp;
	printf("\nyC = "); scanf("%f", &temp); t->C.y = temp;
}

float kc2d(diem a, diem b) {  //kho?ng cách 2 di?m: chính là d? dài 1 c?nh c?a 1 tam giác
	float kc;
	kc = sqrt(((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
	return kc;
}

int loaiTG(tamgiac *t) {
	float a1; float b1; float c1; //a1 = BC^2; b1 = CA^2; c1 = AB^2, chú ý tam giác t có 3 d?nh là A,B,C
	a1 = (kc2d(t->B, t->C))*(kc2d(t->B, t->C));
	b1 = (kc2d(t->A, t->C))*(kc2d(t->A, t->C));
	c1 = (kc2d(t->B, t->A))*(kc2d(t->B, t->A));

	if (a1==b1||b1==c1||c1==a1) {
		if ((a1 == b1)&&(b1 == c1)) return 1;
		else if (a1 == b1 + c1 || b1 == c1 + a1 || c1 == a1 + b1) return 2;
		else return 3;
		else if (a1 == b1 + c1 || b1 == c1 + a1 || c1 == a1 + b1) return 4;
   }
	else return 5;
}

float dientichtg(tamgiac *tg) {  //ham nay tinh dien tich tam giac tg thuoc kieu cau truc tamgiac
	float p; // p = nua chu vi cua tam giac
	float x;
	float y;
	float z; //do dai 3 canh cua tam giac
	
	x = kc2d(tg->A,tg->B); //x = AB
	y = kc2d(tg->B,tg->C);
	z = kc2d(tg->C,tg->A);
	
	p = (x + y + z)/2;
	p = sqrt(p*(p-x)*(p-y)*(p-z));
	
	return p;
}

int main()
{ 
	tamgiac abc;
	float ab;
	float bc;
	float ca;
	
	printf("\nnhap toa do cac dinh cua tam giac ABC: ");
	nhaptoado(&abc);
	
	ab = kc2d(abc.A,abc.B);
	bc = kc2d(abc.B,abc.C);
	ca = kc2d(abc.C,abc.A);
	
	printf("\nDo dai canh AB la: %5f",ab);
	printf("\nDo dai canh BC la: %5f",bc);
	printf("\nDo dai canh CA la: %5f",ca);
	
	int loaitamgiac;
	loaitamgiac = loaiTG(&abc);
	switch (loaitamgiac) {
		case 1: printf("\nDay la tam giac deu"); break;
		case 2: printf("\nDay la tam giac vuong can"); break;
		case 3: printf("\nDay la tam giac can"); break;
		case 4: printf("\nDay la tam giac vuong"); break;
		case 5: printf("\nDay la tam giac thuong"); break;
	}
	
	float dt;
	dt = dientichtg(&abc);
	printf("\nDien tich tam giac tren la: %5f",dt);
}
