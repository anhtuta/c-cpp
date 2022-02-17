// AES.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AES.h"

char decode[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void displayBlock(unsigned char * block)
{
	for (int i = 0; i < 16; i++)
	{
		printf("%c%c ", decode[block[i] >> 4], decode[block[i] & 15]);
	}
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned char plaintext[] = {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0, 
		0, 0, 0, 0
	};

	unsigned char key[] = {
		0x24, 0x75, 0xa2, 0xb3,
		0x34, 0x75, 0x56, 0x88,
		0x31, 0xe2, 0x12, 0x00, 
		0x13, 0xaa, 0x54, 0x87
	};

	unsigned char cipherText[] = {
		0x63, 0x2c, 0xd4, 0x5e,
		0x5d, 0x56, 0xed, 0xb5, 
		0x62, 0x04, 0x01, 0xa0, 
		0xaa, 0x9c, 0x2d, 0x8d
	};
	printf("theo VD trang 58 slide:\n");
	printf("plaintext:\n");
	displayBlock(plaintext);
	printf("key:\n");
	displayBlock(key);
	printf("ciphertext:\n");
	displayBlock(cipherText);

	printf("\n\nket qua mo phong:\n");
	printf("khoi truoc ma hoa:\n");
	displayBlock(plaintext);
	printf("\n\n");

	aesEncrypt(plaintext, key);

	printf("khoi sau ma hoa:\n");
	displayBlock(plaintext);
	printf("\n\n");

	aesDecrypt(plaintext, key);
	
	printf("giai ma khoi sau ma hoa:\n");
	displayBlock(plaintext);

	_getch();
	return 0;
}

