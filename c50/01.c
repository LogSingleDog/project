#include<stdio.h>
int main()
{
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a+b<=c||a+c<=b||b+c<=a)
        printf("0");
    else if(a==b&&a==c)
        printf("1");
    else if(a==b||a==c||b==c)
        printf("2");
    else printf("3");
    return 0;
}