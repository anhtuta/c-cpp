//////tham kh?o t? tác gi?: Kashif Latif
/////National University of Sciences & Technology, Pakistan

#include<stdio.h>
#include<conio.h>
#include <iostream>

using namespace std;


int main()
{
	//long long int khai báo s? ki?u hexa có it nh?t 64bit, có ð?nh d?ng là %llx
	unsigned long long  P,C,key,k[17],c[17],d[17],L[17],R[17],ep48_out[17],sb_in[17],sb32_out[17],pb_out[17],a,temp16,LR;
	int ch,r,i,j; //r=round, là s? v?ng sinh khóa, r t? 1-16
	unsigned char sbox6,row,col,b=0;
	printf("Encrypt or Decrypt?\n");
	printf("Encrypt: 1\nDecrypt: 2\n");
	scanf("%d",&ch);
	switch (ch)  {
	    case 1: printf("nhap plaintext dang Hex 64bit : ");
		case 2: printf("nhap ciphertext dang Hex 64bit : ");
	}
	scanf("%llx",&P);
	printf("\nnhap key dang Hex 64bit: ");
	scanf("%llx",&key); 

	static unsigned char pc1[56] = {   //kh?i parity drop, dùng trong key generation
		57, 49, 41, 33, 25, 17,  9,  
		1, 58, 50, 42, 34, 26, 18,  
		10,  2, 59, 51, 43, 35, 27,       
		19, 11,  3, 60, 52, 44, 36,      
		63, 55, 47, 39, 31, 23, 15,        
		7, 62, 54, 46, 38, 30, 22,       
		14,  6, 61, 53, 45, 37, 29,      
		21, 13,  5, 28, 20, 12,  4}; 

	static unsigned char pc2[48] = {   //Compression P-box, dùng trong key generation
		14, 17, 11, 24,  1,  5,  
		3, 28, 15,  6, 21, 10,       
		23, 19, 12,  4, 26,  8,       
		16,  7, 27, 20, 13,  2,       
		41, 52, 31, 37, 47, 55,       
		30, 40, 51, 45, 33, 48,       
		44, 49, 39, 56, 34, 53,       
		46, 42, 50, 36, 29, 32}; 

	static unsigned char ip[64] = { 58, 50, 42, 34, 26, 18, 10, 2,//Initial Permutation: IP
		60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6,
		64, 56, 48, 40, 32, 24, 16, 8,
		57, 49, 41, 33, 25, 17, 9, 1,
		59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5,
		63, 55, 47, 39, 31, 23, 15, 7};

	static unsigned char ep[48] = { 32, 1, 2, 3, 4, 5, //Expansion Permutation, dung trong ham f
		4, 5, 6, 7, 8, 9,
		8, 9, 10, 11, 12, 13,
		12, 13, 14, 15, 16, 17,
		16, 17, 18, 19, 20, 21,
		20, 21, 22, 23, 24, 25,
		24, 25, 26, 27, 28, 29,
		28, 29, 30, 31, 32, 1};

	static unsigned char p[32] = { 16, 7, 20, 21, //Straight Permutation, dung trong ham f
		29, 12, 28, 17,
		1, 15, 23, 26,
		5, 18, 31, 10,
		2, 8, 24, 14,
		32, 27, 3, 9,
		19, 13, 30, 6,
		22, 11, 4, 25};

	static unsigned char s[8][4][16] = {
		{ {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,},  //S1
		{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,},
		{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,},
		{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13,},},
		{ {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,},  //S2
		{ 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,},
		{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,},
		{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9,},},
		{ {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,},  //S3
		{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,},
		{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,},
		{ 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12,},},
		{ { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,}, //S4
		{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,},
		{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,},
		{ 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,},},
		{ { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,}, //S5
		{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,},
		{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,},
		{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3,},},
		{ {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,},  //S6
		{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,},
		{ 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,},
		{ 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13,},},
		{ { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,}, //S7
		{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,},
		{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,},
		{ 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12,},},
		{ {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,},  //S8
		{ 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,},
		{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,},
		{ 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}};

	static unsigned char iip[64] = { 40, 8, 48, 16, 56, 24, 64, 32,//Inverse Permutation
		39, 7, 47, 15, 55, 23, 63, 31,
		38, 6, 46, 14, 54, 22, 62, 30,
		37, 5, 45, 13, 53, 21, 61, 29,
		36, 4, 44, 12, 52, 20, 60, 28,
		35, 3, 43, 11, 51, 19, 59, 27,
		34, 2, 42, 10, 50, 18, 58, 26,
		33, 1, 41, 9, 49, 17, 57, 25};

	for(i=0;i<=16;i++) { //kh?i t?o
		c[i]=d[i]=0; 
		k[i]=0; 
		L[i]=R[i]=0;
		ep48_out[i]=0;
		sb_in[i]=sb32_out[i]=0;
		pb_out[i]=0;
	} 
	//chú ? là n?u ko kh?i t?o = 0 th? k?t qu? sai nhé. c? th? mà xem!
	//i=0 là kh?i ð?u, i=1-16 ?ng v?i 16 v?ng(round) nhé! k[0] ko dùng
	//sb_in[0], sb_out[0], pb_out[0] c?ng ko dùng

	
	//t?m C0,D0
	for (j=27; j>=0;j--) {   
		c[0] = c[0] ^ (((key >> (64-pc1[(27-j)])) & 0x1) << j);
		d[0] = d[0] ^ (((key >> (64-pc1[(55-j)])) & 0x1) << j); 
	} //ð? t?m xong C0,D0
	
	//////////t?o 16 khóa con Subkey////////////////
	for(r=1;r<=16;r++) {
		a=0;  
		//t?m các C1-C16,D1-D16
		if((r==1)|(r==2)|(r==9)|(r==16)) {
			for(i=26;i>=0;i--)  {
				c[r]=(c[r]) ^ (((c[r-1]>>i) &0x1) <<i) ;
				d[r]=(d[r]) ^ (((d[r-1]>>i) &0x1) <<i) ;
	        }
	        c[r]=(c[r]<<1) ^ ((c[r-1]>>27)&0x1); 
			d[r]=(d[r]<<1) ^ ((d[r-1]>>27)&0x1); 
		}
		else  {
			for(i=25;i>=0;i--)  {
				c[r]=(c[r]) ^ (((c[r-1]>>i) &0x1) <<i) ;
				d[r]=(d[r]) ^ (((d[r-1]>>i) &0x1) <<i) ;
			}
			c[r]=(c[r]<<2)+((c[r-1]>>26)&0x3); 
			d[r]=(d[r]<<2)+((d[r-1]>>26)&0x3); 
		}
		//ð? t?m xong C1-C16,D1-D16, chính là m?ng c[16],d[16]

	    k[r]=(c[r]<<28)+d[r]; //công th?c này bi?u di?n vi?c g?p 2 n?a c[i] và d[i] l?i v?i nhau t?o thành k[i]. ph?i cho các k[i] này ði qua P-box PC2, thu ðc k[i] là các Subkey

	    //cho các k[i] ? trên ði qua Compression P-box, cách làm týõng t? nhý lúc tính c[0] và d[0]
	    for (j=47; j>=0;j--)  {
		    a=a^(((k[r]>>(56-(pc2[47-j]))&0x1) << j)); 
	    }
		k[r]=a;
	}
	///////////xong ph?n subkey//////////////////////
	//th? in k?t qu? 16 subkey ra màn h?nh
	for(i=1;i<=16;i++)
		printf("k%d=%llx\n",i,k[i]);

	//bây gi? ð?n ph?n plaintext
	//cho qua kh?i initial permutation: gi?ng nhý tính c0, d0, ta tính L0,R0
	for(i=31;i>=0;i--)  {
		L[0] = L[0] ^ (((P>>(64-ip[31-i]))&0x1)<<i); 
		R[0] = R[0] ^ (((P>>(64-ip[63-i]))&0x1)<<i); //L0 và R0 có 32bit
	}
	//xong L0,R0

	//////////b?t ð?u vào hàm f:có 16 v?ng://////////////////////
	for(r=1;r<=16;r++)  {
		ep48_out[r] = 0;
		//qua Expansion P-box: ep[48], gi?ng nhý tính c0, d0
		for(i=47;i>=0;i--)  {
			ep48_out[r] = ep48_out[r] ^ ((long long)((R[r-1]>>(32-ep[47-i]))&0x1)<<i); //v? R[r-1] ch? có 32bit
		}
		if(ch==1) sb_in[r]= ep48_out[r] ^ k[r];     //encript
		if(ch==2) sb_in[r]= ep48_out[r] ^ k[17-r];  //decript
		printf("\nsb_in[%d] = %llx",r,sb_in[r]);  //th? in kq

		//b?t ð?u cho sb_in vào Array of S-boxes
		//gi? s? sb_in[r] = s1s2s3....s48 : 48 bit
		//bây gi? tính sb32_out[r]:là ð?u ra có 32 bit

		/////////////cho qua S-boxes: ///////////////////////ph?n S-box này ðau ð?u. Th? m?y ngày ko ra ðc,ko bi?t code sai ? ðâu, nên ðành chép/////////////
		sb32_out[r] = 0;
		for(i=0;i<8;i++)  {  //i là ch? s? ?ng või ch? s? s-box
			row = 0; col = 0; sbox6 = 0;
			sbox6 = sb_in[r] >> ((48-(i+1)*6) & 0x3f) ; //l?y 6 bit cho m?i sbox
			row = row ^ (((sbox6 >>5)&0x1)<<1);  //row là bit th? 1 và 6 c?a sbox6 h?p l?i
			row = row ^  + (sbox6 & 0x1) ;
			col = col ^ ((sbox6>>1) & 0xf);      //col là 4 bit gi?a c?a sbox6
			sb32_out[r] = sb32_out[r] ^ ((int) s[i][row][col]<<(32-(i+1)*4)) ;
		}		
		/////////////xong S-boxes///////////////////////////
		//th? in kq ra
		printf("\nsb32_out[%d] = %llx",r,sb32_out[r]);

		////////////straight permutation: p[32]////////////
		for(j=31;j>=0;j--)  {
			pb_out[r] = pb_out[r] ^ (((sb32_out[r]>>(32-p[31-j]))&0x1)<<j); //pb_out[r] có 32 bit
		}
		////////////xong straight permutation///////////////

		L[r] = R[r-1];
		R[r] = L[r-1] ^ pb_out[r];
	}
	//xong 16 v?ng
	//hoán v? l?i L16 và R16 v? v?ng cu?i cùng ko có b? swapper
	temp16 = L[16]; L[16] = R[16]; R[16] = temp16;

	//th? in kq
	for(j=1;j<=16;j++)  {
		printf("\nL%d = %llx",j,L[j]);
		printf("\nR%d = %llx",j,R[j]);
	} 

	//cho L16 và R16 qua IP^-1 thu ðc Ciphertext
	C=0;
	LR=0;//kh?i t?o
	LR = (L[16]<<32) + R[16];
	//cho qua iip[64]:
	for(i=63;i>=0;i--)  {
		C = C ^ (((LR>>(64-iip[63-i]))&0x1)<<i);
	}
	/////////////xong r?i!//////////////////////

	if(ch==1)  printf("\nCiphertext là %llx",C);
	if(ch==2)  printf("\nPlaintext là %llx",C);
	getch();
	return 0;
}

//th? Plaintext: 123456ABCD132536
//Key:           AABB09182736CCDD
//Ciphertext:    c0b7a8d05f3a829c


