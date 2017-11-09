#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#define PI acos(-1.0)
#define eps 1e-6
#define mem(a,b) memset(a,b,sizeof(a))
#define sca(a) scanf("%d",&a)
#define pri(a) printf("%d\n",a)
#define MM 100005
#define MN 1005
#define INF 10000007
using namespace std;
typedef long long ll;
int n,m;
double a[MM];
int gao(double mid)
{
    int sum=0,i;
    for(i=0;i<n;i++)
        sum+=int(a[i]/mid);
    if(sum<m) return 0;
    return 1;
}
int main()
{
	freopen("pie.txt", "r", stdin);
    int t;
    sca(t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        m++;
        double l,r,mid;
        for(int i=0; i<n; i++)
        {
            scanf("%lf",&a[i]);
            a[i]*=a[i]*PI;
            if(r<a[i]) r=a[i];
        }
        l=0;
        while(r-l>eps)
        {
            mid=(l+r)/2;
            if(gao(mid)) l=mid;
            else r=mid;
        }
        printf("%.4f\n",mid);
    }
    return 0;
}
