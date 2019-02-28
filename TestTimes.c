#include"stdio.h"
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
int dp[1005][50];
int main()
{
	int n,m,i,cnt,ind,k;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
    {
        dp[i][1]=i;
    }
    for (cnt=2;cnt<=m;cnt++)
    {
        for (ind=1;ind<=n;ind++)
        {
            dp[ind][cnt]=1+dp[ind-1][cnt];
            for (k=2;k<=ind;k++)
                dp[ind][cnt]=Min( dp[ind][cnt] , 1+Max( dp[k-1][cnt-1] , dp[ind-k][cnt] ) );
        }
    }
    printf("%d\n",dp[n][m]);
	return 0;
} 
