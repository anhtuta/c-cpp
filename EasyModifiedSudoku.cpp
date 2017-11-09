#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <iostream>
#define MAX 20
#define for(i, a, b) for(i = a; i <= b; i++)

using namespace std;

int a[9][9];
int testcase;
int i,j;
int markRow[9][9];	//VD: neeus owr hangf 3 ddax coos cacs soos 2,5,8,9 thif: markRow[3][2] = markRow[3][5] = markRow[3][8] = markRow[3][9] = 1
int markColumn[9][9];	//VD: neeus owr cootj 5 ddax coos cacs soos 1,2,4 thif: markColumn[5][1] = markColumn[5][2] = markColumn[5][7] = 1
bool isPrint;
int currentTest;
bool isDone;	//Neu ko thoa man dieu kien: trong 1 block 4x4 chi ton tai nhieu nhat 2 so giong nhau, thi truong hop nay coi nhu giai xong luon va in ra kq la: NO! (ko the giai dc)

void printMarks() {
	//cout << "\nmarkRow:" << endl;
	for(i, 1, 8) {
		for(j, 1, 8) {
			cout << markRow[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "\nmarkColumn:" << endl;
	for(i, 1, 8) {
		for(j, 1, 8) {
			cout << markColumn[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void printSolution() {
	isPrint = true;
	cout << "Test case #" << currentTest << ": YES" << endl;
	for(i, 1, 8) {
		for(j, 1, 8) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

/*
 * return true nghiax laf blocks chwas ddieemr (x,y) thoar manx ddieeuf kieenj: Mooix block 4x4 chir toonf taij nhieeuf nhaats 2 soos gioongs nhau
 */
bool checkBlock(int x, int y) {
	int F[9];
	int fuckCplus =0;
	for(i, 0, 9) F[i] = 0;
	if(x <= 4 && y <= 4) {
		//cout << "vao block 1\n";
		for(i, 1, 4) {
			for(j, 1, 4) {
				F[a[i][j]]++;
				if(F[a[i][j]] > 2) return false;
			}
		}
		return true;
	} else if(x <= 4 && y > 4 && y <= 8) {
		for(i, 1, 4) {
			for(j, 5, 8) {
				//cout << "a[i][j] = " << a[i][j] << endl;
				F[a[i][j]]++;
				//cout << "F[a[i][j]] = " << F[a[i][j]] << endl;
				if(F[a[i][j]] > 2) return false;
			}
		}
		return true;
	} else if(x > 4 && x <= 8 && y <= 4) {
		//cout << "vao block 3\n";
		for(i, 5, 8) {
			for(j, 1, 4) {
				F[a[i][j]]++;
				if(F[a[i][j]] > 2) return false;
			}
		}
		return true;
	} else if(x > 4 && y > 4) {
		//cout << "vao block 4\n";
		for(i, 5, 8) {
			for(j, 5, 8) {
				F[a[i][j]]++;
				if(F[a[i][j]] > 2) return false;
			}
		}
		return true;
	}
	return true;
}

void sudoku(int k1, int k2) {	//ddieenf soos vaof oo (k1, k2)
	if(isDone) return;
	//cout <<"k1, k2 = " << k1<<", "<<k2 <<endl;
	if(a[k1][k2] == 0) {
		for(i, 1, 8) {
			//cout << "calling checkbox\n";
			if(markRow[k1][i] == 0 && markColumn[k2][i] == 0) {
				a[k1][k2] = i;
				markRow[k1][i] = 1;
				markColumn[k2][i] = 1;
				if(!checkBlock(k1, k2)) {
					isDone = true;
					cout << "false\n";
				}
				if(k1 == 8 && k2 == 8) {
					for(i, 1, 8) {
						for(j, 1, 8) {
							if(markRow[i][j] == 0 || markColumn[i][j] == 0) return;		//ko co loi giai cho de bai nay
						}
					}
					printSolution();
					return;
				} else {
					if(k2 < 8) sudoku(k1, k2+1);
					else if(k1 < 8) sudoku(k1+1, 1);
				}
				
				markRow[k1][i] = 0;
				markColumn[k2][i] = 0;
			}
		}
	} else {
		if(k1 == 8 && k2 == 8) {
			for(i, 1, 8) {
				for(j, 1, 8) {
					if(markRow[i][j] == 0 || markColumn[i][j] == 0) return;		//ko co loi giai cho de bai nay
				}
			}
			printSolution();
			return;
		}
		else if(k2 < 8) sudoku(k1, k2+1);
		else if(k1 < 8) sudoku(k1+1, 1);
	}
}

int main() {
	freopen("sudoku.txt", "r", stdin);
	cin >> testcase;
	currentTest = 0;
	while(testcase--) {
		//==========reset data============//
		isDone = false;
		currentTest++;
		isPrint = false;
		for(i, 1, 8) {
			for(j, 1, 8) {
				markRow[i][j] = 0;
				markColumn[i][j] = 0;
				a[i][j] = 0;
			}
		}
		
		//========begin solving problem===========//
		int temp;
		for(i, 1, 8) {
			for(j, 1, 8) {
				cin >> temp;
				a[i][j] = temp;
				if(temp != 0) {
					markRow[i][temp] = 1;
					markColumn[j][temp] = 1;
				}
			}
		}
		//cout << "before solving:\n";
		//printMarks();
		//cout << endl << endl << "after solving:\n";
		
		sudoku(1,1);	//bawts ddaauf ddieenf soos twf oo (1,1)
		if(isDone) cout << "Test case #" << currentTest << ": NO" << endl;
		else if(!isPrint) {
			cout << "Test case #" << currentTest << ": NO" << endl;
			//printMarks();
			/*
			for(i, 1, 8) {
				for(j, 1, 8) {
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			*/
		}
		
	}
}

/*
VD:
matrix a:
1 2 3 4 5 6 7 0
5 6 2 1 3 4 0 7
6 5 0 7 2 1 3 4
3 4 7 8 6 5 2 1
2 1 5 6 8 7 4 3
4 3 6 5 7 8 1 2
0 7 1 2 4 3 5 6
7 0 4 3 1 2 6 5

markRow:
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
//cacs hangf 1,2,3,7,8 ddeeuf thieeus soos 8

markColumn:
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
*/
