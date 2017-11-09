#include <cstdio>

int matrix[10][10];
int result = 0; // flags

int check(int x, int y, int value)
{
	for(int i=0; i<9; i++)
		if(value==matrix[x][i]||value==matrix[i][y])return 1;
	return 0;
}
int check_block(int x, int y, int value)
{
	int start_x = x/3;
	int start_y = y/3;
	int i=start_x*3, end_x = i+3, j = start_y*3, end_y = j+3;
	for(i=start_x*3; i<end_x; i++)
		for(j=start_y*3; j<end_y; j++)
			if(value==matrix[i][j])return 1;
	return 0;
}
void get_solution(int x, int y)
{
	if(x>=9){
		// ton tai solution
		result = 1;
		return;
	}
	if(matrix[x][y]!=0)
	{
		// da duoc dat gia tri
		if(y<8)get_solution(x, y+1);
		else get_solution(x+1, 0);
	}
	else
	{
		int last = matrix[x][y];
		// thu tung gia tri thich hop
		for(int i=9; i>=1; i--)
			if(check(x, y, i)==0&&check_block(x, y, i)==0)
			{
				matrix[x][y] = i; 
				if(y<8)get_solution(x, y+1);
				else get_solution(x+1, 0);
				if(result==1)return;
				matrix[x][y] = last;
			}
	}
}

int main()
{
	freopen("easudoku.txt", "r", stdin);
	int nTestCase;
	scanf("%d", &nTestCase);
	for(int test=0; test<nTestCase; test++)
	{
		for(int i=0; i<9; i++)
			for(int j=0; j<9; j++)
				scanf("%d", &matrix[i][j]);
		result = 0;
		get_solution(0,0);
		if(result!=0)
		{
			for(int i=0; i<9; i++)
			{
				for(int j=0; j<9; j++)
				{
					printf("%d ", matrix[i][j]);
				}
				printf("\n");
			}
		}
		else printf("No solution\n");
	}
	return 0;
}
