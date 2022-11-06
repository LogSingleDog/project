#include<stdio.h>
int a[1145];
int jump(int n)
{
    if(n==2||n==3) return 2;
    if(a[n]!=0) return a[n];
    else return a[n]=((jump(n-1)+2*jump(n-2))%10000);
}
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        printf("%d\n",jump(n));
    }
    return 0;
}