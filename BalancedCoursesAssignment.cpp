


int avail[MAXN][MAXN] = {};
int conflict[MAXN][MAXN] = {};
int m,n;
int w[MAXN][MAXN] = {};
int fopt = INF;

void input() {
	cin >> m >> n;
	
	//ddocj nhwngx moon hocj maf giaos vieen i dayj ddc
	for(int i = 1; i <= m; i++) {
		cin >> avail[i][0];
		for(int j = 1; j <= avail[i][0]; j++) {
			cin >> avail[i][j];
		}	
	}
	
	int conflictCnt, u, v;
	cin >> conflictCnt;
	
	//ddocj cacs conflict
	for(int i = 1; i <= conflictCnt; i++) {
		cin >> u >> v;
		conflict[u][v] = 1;
	}
}

bool thuocUCV(int i, int k) {
	if(!avail[i][k]) return false;
	for(int j = 1; j <= w[i][0]; j++) {
		if(conflict[ w[i][j] ] [k]) return false;
	}
	return true;
}
int maxLoad() {
	int maxL = w[1][0];
	for(int i = 2; i <= m; i++) {
		maxL = max(maxL, w[i][0]);
	}
	return maxL;
}

void BCA(int k) {
	//tim thay i co the day mon k
	for(int i = 1; i <= m; i++) {
		if(thuocUCV(i, k)) {
			w[j][0]++;
			w[j][ w[j][0] ] = k;
			if(k == n) {
				if(maxLoad() < fopt) {
					fopt = maxLoad();
				}
			} else BCA(k+1);
			w[j][0]--;
			w[j][ w[j][0] ] = 0;
		}
	}
}

int main() {
	freopen("bca.txt", "r", stdin);
	input();
	BCA(1);
	cout << fopt;
	
}
