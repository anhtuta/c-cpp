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
//int flag;
int currentTest;

void printMarks() {
	cout << "print mark matrixs:\n";
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
	cout << "finish printing mark matrixs:\n";
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

bool checkMarks() {
	FOR(i, 1, 8) {
		FOR(j, 1, 8) {
			if(markRow[i][j] > 1) return false;
			if(markColumn[i][j] > 1) return false;
		}
	}
	return true;
}

int abc = 0;
void sudoku(int k1, int k2) {	//ddieenf soos vaof oo (k1, k2)
	cout <<"sudoku(). currentTest = "<<currentTest<<endl;
	if(k1 >= 9) {
		abc = 1000;
		return;
	}
	
	if(a[k1][k2] == 0) {
		FOR(i, 1, 8) {
			if(markRow[k1][i] == 0 && markColumn[k2][i] == 0) {
				a[k1][k2] = i;
				markRow[k1][i] = 1;
				markColumn[k2][i] = 1;
				if(checkBlock(k1, k2)) {
					if(k2 < 8) sudoku(k1, k2+1);
					else sudoku(k1+1, 1);
					
					markRow[k1][i] = 0;
					markColumn[k2][i] = 0;
				} else {
					a[k1][k2] = 0;
				}
			}
			if(abc==1000)return;
		}
	} else {
		if(k2 < 8) sudoku(k1, k2+1);
		else sudoku(k1+1, 1);
	}
}

int main() {
	freopen("sudoku.txt", "r", stdin);
	cin >> testcase;
	currentTest = 10;
	while(testcase--) {
		//==========reset data============//
		currentTest++;
		abc=0;
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
		cout <<"2. currentTest = "<<currentTest<<endl;
		if(checkBlock(1,1) && checkBlock(1,5) && checkBlock(5,1) && checkBlock(5,5) && checkMarks()) {
			cout <<"3. currentTest = "<<currentTest<<endl;
			sudoku(1,1);	//bawts ddaauf ddieenf soos twf oo (1,1)
			//currentTest++;
			cout <<"4. currentTest = "<<currentTest<<endl;
			if(abc==1000) {
				cout << "Test case #" << currentTest << ": YES" << endl;
				printSolution();
			} else {
				cout << "Test case #" << currentTest << ": NO" << endl;
				cout <<"abc = "<<abc<<endl;
				//cout << "flag = " << flag<<endl;
				//printSolution();
			}
		} else {
			cout << "Test case #" << currentTest << ": NO" << endl;
			//printMarks();
		}
	}
}
