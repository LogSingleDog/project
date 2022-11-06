#include<stdio.h>
char a[114514];
int b[114];
int len(const char a[])
{
    int l = 0;
    while(a[l])
        l++;
    return l;
}
int main()
{
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",a);
        for(j=1;j<=len(a);j++)
        {
            if(a[j]>='0'&&a[j]<='9')
                b[i]++;
        }
    }
    for(i=1;i<=n;i++)
        printf("%d\n",b[i]);
    return 0;
}