#include<stdio.h>
int main()
{
    int n,m;
    int a[114514]={0};
    int i,j;
    int t;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(m==0&&n==0) break;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(m>n) m=n;
        for(i=1;i<=m;i++)
            for(j=n;j>i;j--)
            {
                if(a[j]>a[j-1])
                    t=a[j],a[j]=a[j-1],a[j-1]=t;
            }
        for(i=1;i<=m;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}