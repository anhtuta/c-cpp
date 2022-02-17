#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 100
#define INF 99999999

using namespace std;

int n;
int d[MAX];		
//d[v] = khoang cach ngan nhat tu dinh s toi dinh v
// = độ dài đường đi từ s đến v ngắn nhất hiện biết (cận trên cho độ dài đường đi ngắn nhất thực sự).
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
	cout << "s = "<<s<< ", t = "<<t<<endl;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout <<w[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for(int i = 1; i <= n; i++) {
		cout << "d["<<i<<"] = "<<d[i]<<endl;
	}
	cout << endl;
	for(int i = 1; i <= n; i++) {
		cout << "p["<<i<<"] = "<<p[i]<<endl;
	}
	cout << endl;
	for(int i = 1; i <= n; i++) {
		cout << "T["<<i<<"] = "<<T[i]<<endl;
	}
	cout << endl;
}

// neeus mangr T ko chwas ddinhr naof cuar ddoof thij nwax thif return true;
bool isEmpty() {
	for(int u = 1; u <= n; u++) {
		if(T[u] > 0) return false;	
	}
	return true;
}

void init() {
	for(int u = 1; u <= n; u++) {
		if(u == s) {
			T[u] = -1;	// T = V\{s}, trong ddos V laf taapj cacs ddinhr cuar ddoof thij: G = {V,E}
			d[s] = 0;
			p[u] = s;
			continue;
		}
		
		d[u] = (w[s][u] > 0 ? w[s][u] : INF);
		p[u] = s;
		T[u] = 1;	//T là mảng đánh dấu. T[u] = 1 nghĩa là chưa tìm DDNN từ s đến u. T[u] = 0 nghĩa là đã có DDNN từ s -> u
	}
}

void dijkstra() {
	init();

	while(!isEmpty()) {
		// Laays ddinhr u laf ddinhr trong T maf d[u] laf nhor nhaats. CHU Y: u phair laf ddinhr trong T
		int u;
		int min = INF;
		for(int i = 1; i <= n; i++) {
			if(T[i] == -1 || i == s) continue;	// Chir xets ddinhr u thuoocj taapj T
			if(d[i] < min) {
				u = i;
				min = d[i];	
			}
		}
		
		T[u] = -1;		// T = T\{u}: Do ddax timf dc dduwowngf ddi ngawns nhaats twf s towis u neen ta ko xets u nwax!
		if(u == t) break;  //Duyệt tới node đích rồi thì dừng lại luôn

		// Cập nhật lại d[v] và p[v] của các đỉnh v kề với u
		for(int v = 1; v <= n; v++) {
			if(v == s) continue;
			if(w[u][v] > 0) {
				if(d[v] > d[u] + w[u][v]) {
					d[v] = d[u] + w[u][v];	// do d[u] là ddnn từ s -> u đã tìm đc ở trên nên ddnn từ s->v phải đi qua u nếu v kề với u
					p[v] = u;
				}
			}	
		}
	}
}

int ddnn() {
	cout << "Shortest path:\n";
	int ddnn = 0;
	int currNode = t;
	while(currNode != s) {
		cout << currNode << " <- ";
		ddnn += w[currNode][p[currNode]];
		currNode = p[currNode];
	}
	cout << currNode << endl;		//currNode lúc này = s
	return ddnn;
}

int main() {
	freopen("dijkstra.txt", "r", stdin);
	input();
	dijkstra();
	cout << "DDNN = " <<ddnn()<<endl;
	//output();
}

