//vi du ve struct, danh sach lien ket don


#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Date {
	unsigned ngay;
	unsigned thang;
	unsigned nam;
};

typedef struct thoi_tiet  {
	struct Date thoigian;
	char diadiem[35];
	float luongmua;
	int nhietdo;
	struct thoi_tiet *tiep; //con tror tror toiws phaanf twr tieeps theo
} thoitiet;

int main()  {
	thoitiet thoitietngay, *dau=NULL, *cuoi, *q, *duyet;   //danh sach lien ket nay co 4 con tro: dau, cuoi, tiep(chir ddeens phaanf twr tieeps theo trong danh sachs) va duyet(con tror nayf duyeetj tuwngf phaanf twr trong danh sach
	int n=0,i,nhietdomax; //n la so dia diem nhaapj vaof
	float luongmuatb; //tong luong mua trung binh trong ngay cua tat ca cac khu vuc coongj laij
	
	printf("nhap du lieu, nhap ngay = 0 de dung lai: \n");
	do  {
		int temp; float temp2; //cac bien trung gian dungf ddeer nhaapj dwx lieeuj cho cacs bieens caaus trucs
		printf("\nNgay: "); scanf("%d",&temp); thoitietngay.thoigian.ngay = temp;
		
		if(temp!=0)  {   //neu ngay != 0
			printf("Thang: "); scanf("%d",&temp); thoitietngay.thoigian.thang = temp;
			if(temp!=0)  {   //neu thang != 0
				printf("Nam: "); scanf("%d",&temp); thoitietngay.thoigian.nam = temp;
				if(temp!=0)  {   //neu nam != 0
					printf("Dia diem: "); fflush(stdin); gets(thoitietngay.diadiem);
				    printf("Nhiet do: "); scanf("%d",&temp); thoitietngay.nhietdo = temp;
			    	printf("Luong mua: "); scanf("%f",&temp2); thoitietngay.luongmua = temp2;
			    	printf("\n");
				}
			} 
		}
		
		if(thoitietngay.thoigian.ngay!=0)  {
			q = (thoitiet *)malloc(sizeof(thoitiet));  //caaps phats booj nhows cho 1 banr tin, nghiax laf cho 1 khu vwcj dc nhaapj duw lieeuj. chu y laf chir cho 1 khu vuwcj thooi nhes
			if(q==0) {  //het booj nhows
				printf("\nKo du bo nho cho chuong trinh!");
				exit(1);   //thoat khoi chuong trinh 1 cach binh thuong
			}
			*q = thoitietngay; // ddwa nooij dung vuwaf nhaapj vaof q
			/////bat dau boor xung q vafod cuoois danh sach:////////////
			
			if(dau==0) {  //neu danh sach rong
				dau = q;
				dau->tiep = NULL;  //phan tu cuoi cua danh sach
				cuoi = dau;  //giwx laays nuts cuoois cho laanf nhaapj sau
			}
			else  {
				cuoi->tiep = q;  //boor xung nuts mowis q vwaf nhaapj vaof cuoois danh sach
				cuoi = cuoi->tiep; // = q  //di chuyeenr con tror cuoi ddeer tror vaof phaanf twr cuoois cungf trong danh sachs
				cuoi->tiep = NULL;  //nuts cuoois cuar danh sachs sau khi theem phaanf twr q vafo, nuts cuoois nayf phair tror ddeesn NULL
			}
		}
	} while(thoitietngay.thoigian.ngay!=0);
	
	///////////tim nhiet do cao nhat va tinh luong mua trung binh////////
	nhietdomax = -128; //khoi taoj
	luongmuatb = 0;
	n = 0; //bat dauf duyeetj tuw ddaauf
	duyet = dau;  //con tror duyeetj: bawts ddaauf duyeetj twf ddaauf danh sachs: twf phaanf twr ddaauf tieen
	if(duyet == NULL) {
		//danh sach roongx
		printf("\nChua co phan tu nao!");
		return 0;
	}
	while(duyet!=NULL)  {  //bat dau duyet
		if(nhietdomax < duyet->nhietdo) {
			nhietdomax = duyet->nhietdo;
			q = duyet; //q tror ddeens phaafn twr cos nhiet do cao nhat
		}
		
		luongmuatb += duyet->luongmua;
		n++;
		duyet = duyet->tiep; //tror ddeens phaanf tuwr tieeps theo ddeer duyeetj tieps
	}
	//////////tim xong nhiet do cao nhat va tinh xong luong mua trung binh///////////
	
	////////////in kq////////////
	printf("\nNhiet do cao nhat quan sat duoc la: %d, tai vi tri %s, vao ngay %d thang %d nam %d",nhietdomax,q->diadiem,q->thoigian.ngay,q->thoigian.thang,q->thoigian.nam);  
	printf("\ntong luong mua trung  cua %d khu vuc la %f",n,(luongmuatb/n));
	return 0;
}
