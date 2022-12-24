#include<stdio.h>
int len(char a[])
{
    int l=0;
    while(a[l])
        l++;
    return l;
}
int main()
{
    char a[114][51];
    int b[114];
    int n;
    scanf("%d",&n);
    int i,j;
    int c; while((c=getchar())!='\n'&&c!=EOF);
    for(i=1;i<=n;i++)
    {
        gets(a[i]);
        if(a[i][0]=='_'||(a[i][0]>='a'&&a[i][0]<='z')
            ||(a[i][0]>='A'&&a[i][0]<='Z'))  b[i]=1;
        for ( j = 1; j < len(a[i]); j++)
        {
            if(a[i][j]==' ') b[i]=0;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(b[i]) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}