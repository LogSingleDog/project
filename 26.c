#include<stdio.h>
int gcd(int m,int n)
{
    if(n==0) return m;
    else return gcd(n,m%n);
}
int main()
{
    int a,b,c;
    int t;
    scanf("%d%d",&a,&b);
    if(a<b) t=a,a=b,b=t;
    c=a*b/gcd(a,b);
    printf("%d",c);
    return 0;
}