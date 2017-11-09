#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>
struct ToaDo
{
	int x,y;
};
ToaDo Head,Tail,Body;
ToaDo TD[401];
int demTD=0,demV=90;
int DoDai = 2,CheckAnV=0,CheckV=0,ktDoAnV=0;
int DiemCT=0,DiemOLD=0,DiemV=0;
ToaDo DoAn,DoAnV;
int doKho=100;
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	return coninfo.dwCursorPosition.X;
}
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	return coninfo.dwCursorPosition.Y;
}
void gotoxy(int x, int y)
{
    static HANDLE  h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x,y};
    SetConsoleCursorPosition(h,c);
}
void SetTeColor(WORD color)
{ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void abcd()
{
	SetTeColor(13);
	gotoxy(15,2);
 	printf("Moi Thong Tin Chi Tiet Vui Long Lien He: ");
 	SetTeColor(14);
 	char *_="%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c";
	int __=3**_+5;
	printf("\n\n    \t\t\t");
	printf(_,__+59,__-32,__-19,__-4,__-21,__-40,__+17,__-7,__-21,__-44,__-19,__-17,__-9,__-15,__-2,__+58);
	printf("\n\t\t\t %c Vforum.vn %c",1,1);
	printf("\n\n");
}
void reset();
void intro();
void menu();
void menuchon(int chon, int choncu);
void xuatDiem();
int DieuKhien(int n, int x, int y);
void DiNgangT( int x, int y);
void DiLen( int x, int y);
void DiXuong( int x, int y);
void DiNgangL(int x, int y);
void xoaTail(ToaDo cuoi);
ToaDo ViTriDau();
bool Check();
void inDoAn(ToaDo DoAn);
void XoaDoAn(ToaDo DoAn);
void TaoDoAn();
void TaoDoAnV();
void Khung();
int main()
{
	menu();
	system("cls");
	Khung();
	srand(time(NULL));
	gotoxy(2,10);
 	Head = ViTriDau();
 	Body=Head;
 	Body.x=1;
 	TD[0] = Body;
 	TD[1] = Head;
 	TaoDoAn();
	DiNgangT(Head.x,Head.y);
	
}
int DieuKhien(int n, int x, int y)
{
	SetTeColor(2);
	if(DiemCT > DiemOLD)
	{
		TaoDoAn();
		DiemOLD = DiemCT;
		if(DiemCT % 5 == 0)
			ktDoAnV=0;
		ktDoAnV =0;
	}
	if(DiemCT != 0 && DiemCT % 5 == 0 && CheckV == 0 && ktDoAnV==0)
	{
		TaoDoAnV();
		CheckV=1;
	}
	if(CheckV == 1)
	{
		demV--;
	}
	if(CheckV == 0 || demV == 0)
	{
		demV=90;
		XoaDoAn(DoAnV);
		CheckV=0;
		ktDoAnV =1;
	}
	xuatDiem();
	if(Check() == true)
		if (kbhit())
		{  
			int a = getch();
			if(n == 4 || n == 2)
			{
				if(a == 115 )
					DiXuong(x,y);
				if(a == 119)
					DiLen(x,y);
			}
			if(n == 1 || n == 3)
			{
				if( a == 100)
					DiNgangT(x,y);
				if( a == 97)
					DiNgangL(x,y);
			}
			if(a == 112)
			{
				gotoxy(1,21);
				printf("                 ");
				while(1)
				{
					if(kbhit())
					{
						int p = getch();
						if( p == 112)
							break;
						if( p == 27)
						{
							reset();
							main();
						}
					}
					gotoxy(10,21);
					Sleep(100);
					printf("DANG TAM DUNG BAM p DE TIEP TUC -- BAM ESC DE QUAY LAI MENU");
					gotoxy(10,21);
					Sleep(100);
					printf("                                                           ");
				}
				
			}
			// s = 115     == 1 
			// a = 97		== 2
			// w = 119		== 3
			// d = 100		== 4
		}
	if(Check() == false)
	{
		system("cls");
		SetTeColor(12);
		printf("\t\tDIE CMNR\n");
		printf("\tdiem cua ban la : %d \n",DiemCT+DiemV);
		char tmp;
		SetTeColor(15);
		printf("\tBAM ENTER DE CHOI LAI\n\tBAM ESC DE THOAT LUON");
		while(1)
		{
			tmp = getch();
			if(tmp == 13)
			{
				reset();
				main();
			}
			if(tmp == 27)
			{
				printf("\n");
				printf("\t\t\t\tBye Bye !~~");
				printf("\t\t\t\tBye Bye !~~");
				printf("\t\t\t\tBye Bye !~~");
				printf("Thoat trong 3s");
				Sleep(3000);
				exit(1);
			}
		}
		exit(1);
	}
	return 0;
}
void DiNgangT(int x, int y)
{
	while(1)
	{
		Sleep(doKho);
		gotoxy(++x,y);
		printf("%c",1);
		if(x == DoAn.x&& y ==DoAn.y)
		{
			DiemCT++;
			DoDai++;
			printf("%c",7);
			goto daira;	
		}
		if(x == DoAnV.x&& y ==DoAnV.y )
		{
			CheckAnV=1;
			CheckV=0;
			DiemV+=demV;
			ktDoAnV=1;
		}
		xoaTail(TD[0]);
		for(int i = 0 ; i < DoDai-1 ; i ++ )
			TD[i] = TD[i+1];
		daira:;
		gotoxy(x,y);
		Head = ViTriDau();
		TD[DoDai-1]=Head;
		DieuKhien(4,x,y);
	}
}
void DiNgangL(int x, int y)
{
	int dem = 0;
	while(1)
	{
		Sleep(doKho);
		gotoxy(--x,y);
		printf("%c",1);
		if(x == DoAn.x&& y ==DoAn.y)
		{
			DiemCT++;
			DoDai++;
			printf("%c",7);
			goto daira;	
		}
		if(x == DoAnV.x&& y ==DoAnV.y )
		{
			CheckAnV=1;
			CheckV=0;
			DiemV+=demV;
			ktDoAnV=1;
		}
		xoaTail(TD[0]);
		for(int i = 0 ; i < DoDai-1 ; i ++ )
			TD[i] = TD[i+1];
		daira:;
		gotoxy(x,y);
		Head = ViTriDau();
		TD[DoDai-1]=Head;
		DieuKhien(4,x,y);
	}
}
void DiLen(int x, int y)
{
	while(1)
	{
		Sleep(doKho);
		gotoxy(x,--y);
		printf("%c",1);
		if(x == DoAn.x&& y ==DoAn.y)
		{
			DiemCT++;
			DoDai++;
			printf("%c",7);
			goto daira;
		}
		if(x == DoAnV.x&& y ==DoAnV.y )
		{
			CheckAnV=1;
			CheckV=0;
			DiemV+=demV;
			ktDoAnV=1;
		}
		xoaTail(TD[0]);
		for(int i = 0 ; i < DoDai-1 ; i ++ )
			TD[i] = TD[i+1];
		daira:;
		gotoxy(x,y);
		Head = ViTriDau();
		TD[DoDai-1]=Head;
		DieuKhien(3,x,y);
	}	
}
void DiXuong(int x, int y)
{
	while(1)
	{
		Sleep(doKho);
		gotoxy(x,++y);
		printf("%c",1);
		if(x == DoAn.x&& y ==DoAn.y)
		{
			DiemCT++;
			DoDai++;
			printf("%c",7);
			goto daira;
		}
		if(x == DoAnV.x&& y ==DoAnV.y )
		{
			CheckAnV=1;
			CheckV=0;
			DiemV+=demV;
			ktDoAnV=1;
		}
		xoaTail(TD[0]);
		for(int i = 0 ; i < DoDai-1 ; i ++ )
			TD[i] = TD[i+1];
		daira:;
		gotoxy(x,y);
		Head = ViTriDau();
		TD[DoDai-1]=Head;
		DieuKhien(3,x,y);
	}
}
ToaDo ViTriDau()
{
	ToaDo Dau;
	Dau.x = wherex();
	Dau.y = wherey();
	return Dau;
}
void TaoDoAn()
{
	int check = 0;
	do
	{
		DoAn.x = 2+rand()%76;
		DoAn.y = 2+rand()%18;
		for(int i = 0 ; i < DoDai ; i ++)
		{
			if(TD[i].x == DoAn.x && TD[i].y == DoAn.y)
			{
				check = 1;
				break;
			}	
		} 
		if(check == 0)
		{
			SetTeColor(14);
			inDoAn(DoAn);
		}
	}while(check == 1);
}
void TaoDoAnV()
{
	int check = 0;
	do
	{
		DoAnV.x = 2+rand()%76;
		DoAnV.y = 2+rand()%18;
		if( DoAnV.x == DoAn.x && DoAnV.y == DoAn.y)
		{
			check =1;
			continue;
		}
		for(int i = 0 ; i < DoDai ; i ++)
		{
			if(TD[i].x == DoAnV.x && TD[i].y == DoAnV.y)
			{
				check = 1;
				break;
			}	
		} 
		if(check == 0)
		{
			SetTeColor(13);
			inDoAn(DoAnV);
		}
	}while(check == 1);
}
void inDoAn(ToaDo DoAn)
{
	gotoxy(DoAn.x,DoAn.y);
	printf("*");
}
void XoaDoAn(ToaDo DoAn)
{
	gotoxy(DoAn.x,DoAn.y);
	printf(" ");
}
void xuatDiem()
{
	gotoxy(1,21);
	printf("BAM p DE TAM DUNG");
	gotoxy(1,22);
	printf("DIEM CUA BAN LA: %d",DiemCT+DiemV);
}
void xoaTail(ToaDo cuoi)
{
	gotoxy(cuoi.x,cuoi.y);
	printf(" ");	
}
bool Check()
{
	if(Head.x == 0 || Head.x == 78 || Head.y == 0 || Head.y == 20)
		return false;
	for(int i = 0 ; i < DoDai-1 ; i ++)
		if(TD[i].x == Head.x && TD[i].y == Head.y )
			return false;
	return true;
}
void intro()
{
	system("cls");
	SetTeColor(12);
	abcd();
	SetTeColor(15);
	printf("Bam enter de qua lai luc nay");
	char enter ;
	while(1)
	{
		enter = getch();
		if(enter == 13)
			break;
	}
	menu();
}
void Khung()
{
	for(int i = 0 ; i < 80 ; i ++)
	{
		if(i == 79)
			printf("%c",3);
		if(i < 79)
			printf("%c",31);
	}
	printf("%c                                                                             %c ",16,17);
	printf("%c                                                                             %c ",16,17);
	printf("%c                                                                             %c ",16,17);
	printf("%c                                                                             %cV",16,17);
	printf("%c                                                                             %cF",16,17);
	printf("%c                                                                             %cO",16,17);
	printf("%c                                                                             %cR",16,17);
	printf("%c                                                                             %cU",16,17);
	printf("%c                                                                             %cM",16,17);
	printf("%c                                                                             %c.",16,17);
	printf("%c                                                                             %cV",16,17);
	printf("%c                                                                             %cN",16,17);
	printf("%c                                                                             %c ",16,17);
	printf("%c                                                                             %c ",16,17);
	printf("%c                                                                             %c ",16,17);
	printf("%c                                                                             %c ",16,17);
	printf("%c                                                                             %c ",16,17);
	printf("%c                                                                             %c ",16,17);
	printf("%c                                                                             %c ",16,17);
	for(int i = 0 ; i < 80 ; i ++)
	{
		if(i == 79)
		printf("%c",3);
		if(i < 79)
		printf("%c",30);
	}
}
void menu()
{
	system("cls");
	int chon = 1,choncu=0;
	SetTeColor(11);
	gotoxy(23,2);
	printf(">>>>>GAME RAN SAN MOI<<<<<\n");
	SetTeColor(10);
	gotoxy(32,3);
	printf("Choi Luon");
	gotoxy(29,4);
	printf("Chon Muc Do Choi");
	gotoxy(32,5);
	printf("Huong Dan");
	gotoxy(32,6);
	printf("Thong Tin\n");
	menuchon(1,0);
	while(1)
	{
		char phim;
		if(kbhit())
		{
			phim = getch();
			if(phim == 13)
		 		break;
 			if(phim == 80)
 			{
				if(chon < 4)
				{
					chon++;
					choncu=chon-1;
					menuchon(chon,choncu);
				}
			}
			if(phim == 72)
 			{
				if(chon > 1)
				{
					chon--; 
					choncu=chon+1;	
					menuchon(chon,choncu);
				}
			}
		}
	}
	if(chon == 1)
		return;
	if(chon == 2)
	{
		system("cls");
		char chondokho;
		printf("Bam 1 2 3 chon muc do: ( dai qua nhat lam )\n");
		printf("1.De\n");
		printf("2.Binh Thuong\n");
		printf("3.Kho");
		
		do
		{
			chondokho = getch();
			if(chondokho < 49 || chondokho > 51)
				printf("chon lai de \n");
		}while(chondokho < 49 || chondokho > 51);
		system("cls");
		if(chondokho == 49)
		{
			doKho = 150;
			printf("Da chon muc do DE\n");
		}
		if(chondokho == 50)
		{
			doKho = 90;
			printf("Da chon muc do BINH THUONG\n");
		}
		if(chondokho == 51)
		{
			doKho = 40;
			printf("Da chon muc do KHO\n");
		}
		printf("Bam enter de choi game\nBam ESC de quay lai menu\n");
		char enter ;
		while(1)
		{
			enter = getch();
			if(enter == 27)
				break;
			if(enter == 13)
				return;
		}
		menu();	
	}
	if(chon == 3)
	{
		system("cls");
		printf("\tDung 4 phim a w d s de dieu khien con ran, dam dau zo tuong la chet\n");
		printf("\tKhi an duoc 5 con moi thi se xuat hien con moi dac biet\n\tton tai tron 90 buoc di cua con ran\n");
		printf("\tKhi an con moi dac biet se duoc diem rat la cao\n");
		printf("\tcung kha don gian\n");
		printf("\tBam enter de qua lai luc nay__");
		char enter ;
		while(1)
		{
			enter = getch();
			if(enter == 13)
				break;
		}
		menu();
	}
	if(chon == 4)
	{
		intro();
	}
	
}
void menuchon(int chon, int choncu)
{
	if(chon == 1 )
	{
		if(choncu == 2)
		{
			gotoxy(25,4);
			printf(" ");
			gotoxy(47,4);
			printf(" ");	
		}
		gotoxy(25,3);
		printf("%c",16);
		gotoxy(47,3);
		printf("%c",17);
	}
	if(chon == 2)
	{
		if(choncu == 1)
		{
			gotoxy(25,3);
			printf(" ");
			gotoxy(47,3);
			printf(" ");	
		}
		if(choncu == 3)
		{
			gotoxy(25,5);
			printf(" ");
			gotoxy(47,5);
			printf(" ");	
		}
		gotoxy(25,4);
		printf("%c",16);
		gotoxy(47,4);
		printf("%c",17);
	}
	if(chon == 3)
	{
		if(choncu == 2)
		{
			gotoxy(25,4);
			printf(" ");
			gotoxy(47,4);
			printf(" ");	
		}
		if(choncu == 4)
		{
			gotoxy(25,6);
			printf(" ");
			gotoxy(47,6);
			printf(" ");	
		}
		gotoxy(25,5);
		printf("%c",16);
		gotoxy(47,5);
		printf("%c",17);
	}
	if(chon == 4)
	{
		if(choncu == 3)
		{
			gotoxy(25,5);
			printf(" ");
			gotoxy(47,5);
			printf(" ");	
		}
		gotoxy(25,6);
		printf("%c",16);
		gotoxy(47,6);
		printf("%c",17);
	}
}
void reset()
{
	demTD=0;
	demV=90;
	DoDai = 2;
	CheckAnV=0;
	CheckV=0;
	ktDoAnV=0;
	DiemCT=0;
	DiemOLD=0;
	DiemV=0;
	doKho=100;
}
