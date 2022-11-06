#include<stdio.h>
int main()
{
    int m,n;
    int i;
    int t;
    int a[10]={0};
    scanf("%d%d",&m,&n);
    for(i=m;i<=n;i++)
    {
        t=i;
        while(t!=0)
        {
            a[t%10]++;
            t=t/10;
        }
    }
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    return 0;
}