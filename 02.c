#include<stdio.h>
int main()
{
    int a,b;
    int i=0;
    scanf("%d%d",&a,&b);
    if(a>100||a<0||b<0||b>100) i=-1;
    else if(a>=60&&b>=60) i=1;
    switch(i)
    {
        case 1:printf("it is pass.");break;
        case 0:printf("it is not pass.");break;
        case -1:printf("it is error.");break;
    }
    return 0;
}