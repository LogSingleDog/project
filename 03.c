#include<stdio.h>
#define num 5
void p(int a,char b)
{
    int j;
    for(j=1;j<=a;j++)
        printf("%c",b);
}
int main()
{
    int i;
    for(i=0;i<=(num/2);i++)
    {
        p(i,' ');
        p((num-2*i),'*');
        printf("\n");
    }
    for(i=(num/2-1);i>=0;i--)
    {
        p(i,' ');
        p((num-2*i),'*');
        printf("\n");
    }
    return 0;
}