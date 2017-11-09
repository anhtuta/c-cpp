#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <iostream>
#define MAX 20
#define FOR(i, a, b) for(i = a; i <= b; i++)

using namespace std;

int a[9][9];
int testcase;
int i,j;
int markRow[9][9];	//VD: neeus owr hangf 3 ddax coos cacs soos 2,5,8,9 thif: markRow[3][2] = markRow[3][5] = markRow[3][8] = markRow[3][9] = 1
int markColumn[9][9];	//VD: neeus owr cootj 5 ddax coos cacs soos 1,2,4 thif: markColumn[5][1] = markColumn[5][2] = markColumn[5][7] = 1
bool flag;
int currentTest;

void printMarks() {
	cout << "\nmarkRow:" << endl;
	FOR(i, 1, 8) {
		FOR(j, 1, 8) {
			cout << markRow[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "\nmarkColumn:" << endl;
	FOR(i, 1, 8) {
		FOR(j, 1, 8) {
			cout << markColumn[i][j] << " ";
		}
		cout << endl;
	}
}

void printSolution() {
	FOR(i, 1, 8) {
		FOR(j, 1, 8) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

/*
 * return true nghiax laf blocks chwas ddieemr (x,y) thoar manx ddieeuf kieenj: Mooix block 4x4 chir toonf taij nhieeuf nhaats 2 soos gioongs nhau
 */
int F[9];
int sidx, sidy;
bool checkBlock(int x, int y) {
	FOR(i, 0, 9) F[i] = 0;
	if(x <= 4 && y <= 4) {
		sidx=1; sidy=1;
	} else if(x <= 4 && y > 4 && y <= 8) {
		sidx=1; sidy=5;
	} else if(x > 4 && x <= 8 && y <= 4) {
		sidx=5; sidy=1;
	} else if(x > 4 && y > 4) {
		sidx=5; sidy=5;
	}
	
	FOR(i, sidx, sidx+3) {
		FOR(j, sidy, sidy+3) {
			if(a[i][j] != 0) {
				F[a[i][j]]++;
				if(F[a[i][j]] > 2) return false;	
			}
		}
	}
	return true;
}
int F_row[10];
int F_col[10];
bool check_row_col(int x, int y) {
    for(int i=0; i<9; i++)F_row[i] = F_col[i] =0;
    
    // hang
    for(i=1; i<=8; i++){
        if(a[x][i]==0)continue;
        F_row[a[x][i]]++;
        if(F_row[a[x][i]]>1)
            return false;
    }
    // cot
    for(i=1; i<=8; i++){
        if(a[i][y]==0)continue;
        F_col[a[i][y]]++;
        if(F_col[a[i][y]]>1)
            return false;
    }
    return true;
}

bool checkMarks() {
	FOR(i, 1, 8) {
		FOR(j, 1, 8) {
			if(markRow[i][j] > 1) return false;
			if(markColumn[i][j] > 1) return false;
		}
	}
	return true;
}
void sudoku(int k1, int k2) {	//ddieenf soos vaof oo (k1, k2)
	if(k1 >= 9) {
		flag = 1;
		return;
	}
	
	if(a[k1][k2] == 0) {
		FOR(i, 1, 8) {
			a[k1][k2] = i;
			
			if(check_row_col(k1, k2) && checkBlock(k1, k2)) {
				if(k2 < 8) sudoku(k1, k2+1);
				else sudoku(k1+1, 1);
			}
			a[k1][k2] = 0;
		}
		
	} else {
		if(k2 < 8) sudoku(k1, k2+1);
		else sudoku(k1+1, 1);
	}
}

int main() {
	freopen("sudoku.txt", "r", stdin);
	cin >> testcase;
	currentTest = 0;
	while(testcase--) {
		//==========reset data============//
		currentTest++;
		flag = false;
		FOR(i, 1, 8) {
			FOR(j, 1, 8) {
				markRow[i][j] = 0;
				markColumn[i][j] = 0;
				a[i][j] = 0;
			}
		}
		
		//========begin solving problem===========//
		int temp;
		FOR(i, 1, 8) {
			FOR(j, 1, 8) {
				cin >> temp;
				a[i][j] = temp;
				if(temp != 0) {
					markRow[i][temp]++;
					markColumn[j][temp]++;
				}
			}
		}
		
		
		if(checkBlock(1,1) && checkBlock(1,5) && checkBlock(5,1) && checkBlock(5,5) && checkMarks()) {
			sudoku(1,1);	//bawts ddaauf ddieenf soos twf oo (1,1)
			if(flag==true) {
				cout << "Test case #" << currentTest << ": YES" << endl;
				printSolution();
			} else cout << "Test case #" << currentTest << ": NO" << endl;
		} else cout << "Test case #" << currentTest << ": NO" << endl;
	}
}
