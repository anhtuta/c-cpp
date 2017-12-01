#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define MAX 600
int w[201], h[201];
int S[601][601];
int N;
int W, H;
int main(){
	freopen("marble.txt", "r", stdin);
    int testCase;
    cin >> testCase;
    while(testCase-->0){
        cin >> W >> H >> N;
        for(int i=1;i<=N;i++)
            cin >> w[i] >> h[i];
        for(int i=0;i<=H;i++){
            for(int j=0;j<=W;j++){
                S[i][j]=-1;
            }
        }
        for(int i=0;i<=H;i++)
            S[i][0]=0;
        for(int i=0;i<=W;i++)
            S[0][i]=0;
        S[1][1]=1;
        for(int i=1;i<=N;i++)
            S[h[i]][w[i]]=0;
        for(int i=1;i<=H;i++){
            for(int j=1;j<=W;j++){
                if(S[i][j]!=0){
                    int imin = i*j;
                    for(int ij=1;ij<j;ij++){
                        int temp = S[i][ij] + S[i][j-ij];
                        imin = temp<imin?temp:imin;
                    }
                    for(int ij=1;ij<i;ij++){
                        int temp = S[ij][j] + S[i-ij][j];
                        imin = temp<imin?temp:imin;
                    }
                    S[i][j]=imin;
                }
                //cout << "s["<<i<<"]["<<j<<"] = "<<S[i][j]<<endl;
            }
        }
        cout << S[H][W] << endl;
//        for(int i=0;i<=H;i++){
//            for(int j=0;j<=W;j++){
//                printf("%3d", S[i][j]);
//            }
//            cout << endl;
//        }
    }
    return 0;
}
