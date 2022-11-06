#include<stdio.h>
int main()
{
    int n;
    int a[114];
    int i;
    int t;
    while(1)
    {
        int min=114514,m=0;
        scanf("%d",&n);
        if(n==0) break;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<min)
                min=a[i],m=i;
        }
        t=a[m];a[m]=a[1];a[1]=t;
        for(i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}