#include<stdio.h>
#include<math.h>
double sum(int n)
{
    double i,s;
    for(i=1;i<=n;i++)
        s+=pow((-1),(i-1))*(1/i);
    return s;
}
int main()
{
    int m;
    int i;
    int a[114];
    scanf("%d",&m);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        printf("%.2f\n",sum(a[i]));
    return 0;
}