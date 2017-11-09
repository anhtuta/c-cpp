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

void printSolution() {
	FOR(i, 1, 8) {
		FOR(j, 1, 8) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/*
 * return true nghiax laf blocks chwas ddieemr (x,y) thoar manx ddieeuf kieenj: Mooix block 4x4 chir toonf taij nhieeuf nhaats 2 soos gioongs nhau
 */
bool checkBlock(int value, int x, int y) {
	cout << "calling checkbox: x,y = "<<x<<", "<<y<<endl;
	int F[9];
	FOR(i, 0, 9) F[i] = 0;
	if(x <= 4 && y <= 4) {
		cout << "vao block 1\n";
		FOR(i, 1, 4) {
			FOR(j, 1, 4) {
				if(a[i][j] != 0) {
					if(i==x && j==y) {
						F[value]++;
						if(F[value] > 2) return false;
					} else{
						F[a[i][j]]++;
						if(F[a[i][j]] > 2) return false;	
					}
				}
			}
		}
		return true;
	} else if(x <= 4 && y > 4 && y <= 8) {
		cout << "vao block 2\n";
		for(i=1; i<=4; i++) {
			for(j=5; j<=8; j++) {
				
				//cout << "i, j = "<<i<<", "<<j<<endl;
				if(a[i][j] != 0) {
					if(i==x && j==y) {
						F[value]++;
						if(F[value] > 2) return false;
					} else{
						F[a[i][j]]++;
						if(F[a[i][j]] > 2) return false;	
					}
				}
				cout <<"F[a[" <<i<<"]["<<j<<"]] = "<<F[a[i][j]]<<endl;
			}
		}
		cout <<"xong block2\n";
		return true;
	} else if(x > 4 && x <= 8 && y <= 4) {
		cout << "vao block 3\n";
		FOR(i, 5, 8) {
			FOR(j, 1, 4) {
				if(a[i][j] != 0) {
					if(i==x && j==y) {
						F[value]++;
						if(F[value] > 2) return false;
					} else{
						F[a[i][j]]++;
						if(F[a[i][j]] > 2) return false;	
					}
				}
			}
		}
		return true;
	} else if(x > 4 && y > 4) {
		cout << "vao block 4\n";
		FOR(i, 5, 8) {
			FOR(j, 5, 8) {
				if(a[i][j] != 0) {
					if(i==x && j==y) {
						F[value]++;
						if(F[value] > 2) return false;
					} else{
						F[a[i][j]]++;
						if(F[a[i][j]] > 2) return false;	
					}
				}
			}
		}
		return true;
	}
	return true;
}


void sudoku(int k1, int k2) {	//ddieenf soos vaof oo (k1, k2)
	if(a[k1][k2] == 0) {
		FOR(i, 1, 8) {
			cout <<"i, k1, k2 = "<<i<<", "<<k1<<", "<<k2<<endl;
			if(markRow[k1][i] == 0 && markColumn[k2][i] == 0 && checkBlock(i, k1, k2)) {
				a[k1][k2] = i;
				markRow[k1][i] = 1;
				markColumn[k2][i] = 1;
				if(k1 == 8 && k2 == 8) {
					FOR(i, 1, 8) {
						FOR(j, 1, 8) {
							if(markRow[i][j] == 0 || markColumn[i][j] == 0) return;		//ko co loi giai cho de bai nay
						}
					}
					flag = true;
					printSolution();
					return;
				} else {
					if(k2 < 8) sudoku(k1, k2+1);
					else if(k1 < 8) sudoku(k1+1, 1);
				}
				
				markRow[k1][i] = 0;
				markColumn[k2][i] = 0;
			} else cout<<"vao else roi!\n";
		}
	} else {
		if(k1 == 8 && k2 == 8) {
			FOR(i, 1, 8) {
				FOR(j, 1, 8) {
					if(markRow[i][j] == 0 || markColumn[i][j] == 0) return;		//ko co loi giai cho de bai nay
				}
			}
			flag = true;
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
					markRow[i][temp] = 1;
					markColumn[j][temp] = 1;
				}
			}
		}
		
		
		if(checkBlock(a[1][1],1,1) && checkBlock(a[1][5],1,5) && checkBlock(a[5][1],5,1) && checkBlock(a[5][5],5,5)) {
			sudoku(1,1);	//bawts ddaauf ddieenf soos twf oo (1,1)
			if(flag==true) {
				cout << "Test case #" << currentTest << ": YES" << endl;
				printSolution();
			} else cout << "Test case #" << currentTest << ": NO" << endl;
		} else cout << "Test case #" << currentTest << ": NO" << endl;
	}
}
