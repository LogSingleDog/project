#include<stdio.h>
int main()
{
    int a,b;
    int t;
    int m[114514];
    int i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        if(a%b==0)
            m[i]=1;
    }
    for(i=1;i<=t;i++)
    {
        if(m[i]==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}