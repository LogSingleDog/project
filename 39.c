#include<stdio.h>
int rmb[6]={100,50,10,5,2,1};
int money(int a)
{
    int s=0;
    int i;
    for(i=0;i<6;i++)
    {
        s+=a/rmb[i];
        a=a%rmb[i];
    }
    return s;
}
int main()
{
    int n;
    int a[114];
    int sum;
    int i;
    while(1)
    {
        sum=0;
        scanf("%d",&n);
        if(n==0) break;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=money(a[i]);
        }
        printf("%d\n",sum);
    }
    return 0;
}