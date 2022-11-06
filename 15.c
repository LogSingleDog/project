#include<stdio.h>
int main()
{
    int t;
    int a[1145];
    int i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=t;i++)
        printf("%c",a[i]);
    return 0;
}