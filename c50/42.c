#include<stdio.h>
int len(const char a[])
{
    int l = 0;
    while(a[l])
        l++;
    return l;
}
int main()
{
    char a[55];
    int m;
    int i,j;
    int b[114514]={0};
    int d1,d2,d3,d4;
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%s",a);
        d1=d2=d3=d4=0;
        for(j=0;j<len(a);j++)
        {
            if(len(a)<8||len(a)>16) break;
            if(a[j]>='A'&&a[j]<='Z') d1=1;
            if(a[j]>='a'&&a[j]<='z') d2=1;
            if(a[j]>='0'&&a[j]<='9') d3=1;
            if(a[j]=='~'||a[j]=='!'||a[j]=='@'||
            a[j]=='#'||a[j]=='$'||a[j]=='%'||
            a[j]=='^') d4=1;
        }
        if((d1+d2+d3+d4)>=3) b[i]=1;
    }
    for(i=1;i<=m;i++)
    {
        if(b[i]==1) printf("YES\n");
        else printf("NO\n");
    }
}