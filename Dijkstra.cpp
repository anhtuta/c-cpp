#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 100
#define INF 99999999

using namespace std;

int n;
int d[MAX];		//d[v] = khoang cach ngan nhat tu dinh s toi dinh v
int p[MAX];		//p[v] = cha cua v tren ddnn
int w[MAX][MAX];		//w[a][b] = gia cua canh (a,b), w la matrix trong so
int s, t;	//s = source point, t = dinh can tim khoang cach ngan nhat tu s
//s, t = 1,2,...,n
int T[MAX];		//T neen laf danh sachs lieen keets, lwu trwx cacs ddinhr trong ddoof thij. Nhwng trong C, tao ddeos bieets DSLK neen dungf mangr thay thees!	

void input() {
	cin >> n >> s >> t;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> w[i][j];
		}
	}
}

void output() {
	for(int i = 1; i <= n; i++) {
		cout << "d["<<i<<"] = "<<d[i]<<endl;
	}
	
	for(int i = 1; i <= n; i++) {
		cout << "p["<<i<<"] = "<<p[i]<<endl;
	}
	
	for(int i = 1; i <= n; i++) {
		cout << "T["<<i<<"] = "<<T[i]<<endl;
	}
}

// neeus mangr T ko chwas ddinhr naof cuar ddoof thij nwax thif return true;
bool isEmpty() {
//	cout << "T = [";
//	for(int u = 1; u <= n; u++) {
//		cout << T[u] << " ";
//	}
//	cout << "]\n";

	for(int u = 1; u <= n; u++) {
		if(T[u] > 0) return false;	
	}
	return true;
}

int main() {
	freopen("dijkstra.txt", "r", stdin);
	input();
	
	// khowir taoj
	for(int u = 1; u <= n; u++) {
		if(u == s) {
			T[u] = -1;	// T = V\{s}, trong ddos V laf taapj cacs ddinhr cuar ddoof thij: G = {V,E}
			d[s] = 0;
			p[u] = s;
			continue;
		}
		
		d[u] = (w[s][u] > 0 ? w[s][u] : INF);
		p[u] = s;
		
		T[u] = u;	//ban dau mang T se chua cac dinh cua do thi, do do T = {1,2,3,...,n}. Chu y: bat dau mang la chi so 1, nen ta se bo thang T[0]
	}

	output();
	
	cout <<"\nMang d:\n";
		for(int i = 1; i <= n; i++) {
			cout << d[i] << " ";
		}
		cout <<endl;
	while(!isEmpty()) {		//lawpj cho towis khi mangr T roongx
		cout <<"vong lap while\n";
		// Laays ddinhr u laf ddinhr trong T maf d[u] laf nhor nhaats. CHU Y: u phair laf ddinhr trong T
		int u;
		int min = INF;
		for(int i = 1; i <= n; i++) {
			if(i == s) continue;
			if(T[i] == -1) continue;	// Chir xets ddinhr u thuoocj taapj T
			
			//cout << "\td[" << i << "] = "<<d[i]<<endl;
			if(d[i] < min) {
				u = T[i];
				min = d[i];	
			}
		}
		
		T[u] = -1;		// T = T\{u}: Do ddax timf dc dduwowngf ddi ngawns nhaats twf s towis u neen ta ko xets u nwax!
		
		cout << "u = "<<u<<endl;
		
		// laays cacs ddinhr v keef voiws ddinhr u
		for(int v = 1; v <= n; v++) {
			if(v == s) continue;
			if(w[u][v] > 0) {
				cout << "\tv = "<<v<<endl;
				if(d[v] > d[u] + w[u][v]) {
					cout << "\t\tv = "<<v<<endl;
					d[v] = d[u] + w[u][v];
					p[v] = u;
					//cout << "\tdv = "<<d[v]<<endl;
				}
			}	
		}
		
		cout <<"\nMang d:\n";
		for(int i = 1; i <= n; i++) {
			cout << d[i] << " ";
		}
		cout <<endl;
		cout <<"Mang T:\n";
		for(int i = 1; i <= n; i++) {
			cout << T[i] << " ";
		}
		cout <<endl;cout <<endl;
	}
	
	output();
}

