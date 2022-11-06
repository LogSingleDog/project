#include<stdio.h>
int main()
{
    int t;
    int m,n,x,y;
    int a[1145][1145];
    int b[1145];
    int i,j,k,j1,k1;
    int max,sum;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d%d",&m,&n,&x,&y);
        for(j=1;j<=m;j++)
            for(k=1;k<=n;k++)
                scanf("%d",&a[j][k]);
        for(j=1;j<=m-x+1;j++)
            for(k=1;k<=n-y+1;k++)
            {
                sum=0;
                for(j1=j;j1<=j+x-1;j1++)
                    for(k1=k;k1<=k+y-1;k1++)
                        sum+=a[j1][k1];
                if(max<sum) 
                    max=sum;
            }
        b[i]=max;
    }
    for(i=1;i<=t;i++)
        printf("%d\n",b[i]);
}