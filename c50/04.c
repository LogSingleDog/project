#include<stdio.h>
int gcd(int m,int n)
{
    if(n==0) return m;
    else return gcd(n,m%n);
}
int main()
{
    int m,n;
    int t;
    scanf("%d%d",&m,&n);
    if(m<n) t=m,m=n,n=t;
    printf("%d",gcd(m,n));
}